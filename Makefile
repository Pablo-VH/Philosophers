NAME        	= philo
CC          	= gcc
CFLAGS      	= -Wextra -Werror -Wall -I$(INC) -g3 -fsanitize=thread -pthread
#-g3 -fsanitize=address valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --trace-children=yes 
INC         	= inc/

SRCS_DIR    	= srcs/
UTILS_DIR		= utils/
OBJS_DIR    	= objs/

SRCS_FILES		= main.c exits.c parse.c init_data.c action.c utils_ph.c utils_ph2.c
UTILS_FILES		= ft_atoi.c ft_atoll.c ft_isdigit.c ft_isspace.c \

OBJS_FILES		= $(SRCS_FILES:.c=.o) $(UTILS_FILES:.c=.o)
OBJS_SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS_UTILS		= $(addprefix $(UTILS_DIR), $(UTILS_FILES))
SRCS			= $(OBJS_SRCS) $(OBJS_UTILS)
OBJS			= $(addprefix $(OBJS_DIR), $(OBJS_FILES))

all: $(NAME)

$(NAME): $(OBJS) 
	@echo "\nCompiling $(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\n$(NAME) compiled!"
	@echo "$(BOLD_CYAN)\n------------\n| Done! 👌 |\n------------$(DEF_COLOR)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@[ -d $(OBJS_DIR) ] || mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)%.o: $(UTILS_DIR)%.c
	@[ -d $(OBJS_DIR) ] || mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)
	@echo "$(NAME) cleaned"

re: fclean all

.PHONY: all clean fclean re
.SILENT: all clean fclean