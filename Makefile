NAME        	= philo
CC          	= gcc
CFLAGS      	= -Wextra -Werror -Wall -I$(INC) -g3
#-g3 -fsanitize=address valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --trace-children=yes 

INC         	= inc/

SRCS_DIR    	= srcs/
OBJS_DIR    	= objs/
SRCS_FILES		= main.c exits.c \

OBJS_FILES		= $(SRCS_FILES:.c=.o)

SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS			= $(addprefix $(OBJS_DIR), $(OBJS_FILES))


all: $(NAME)

$(NAME): $(OBJS) 
	@echo "\nCompiling $(BLUE)$(NAME)$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "\n$(GREEN)$(NAME) compiled!$(DEF_COLOR)"
	@echo "$(BOLD_CYAN)\n------------\n| Done! 👌 |\n------------$(DEF_COLOR)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@[ -d $(OBJS_DIR) ] || mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)
	@echo "$(GREEN)$(NAME) cleaned$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re
.SILENT: all clean fclean