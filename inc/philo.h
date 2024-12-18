/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:35:13 by pavicent          #+#    #+#             */
/*   Updated: 2024/12/05 11:35:15 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <unistd.h>
# include <stdint.h>
# include <sys/types.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

//el tenedor con el que entran es el de la izquierda.
//Los pares cogen primero su tenedor, los impares el otro
typedef struct s_list
{
	int				id;
	pthread_mutex_t	fork;
	long			last_meal; //time passed from last meal
	long			meals_count;
	bool			dead;
	//struct s_list	*prev;
	pthread_t		thread_id;
	struct s_philo	*data;
	struct s_list	*next;	
}					t_list;

typedef struct s_philo
{
	long			n_philo;
	long			tt_die;
	long			tt_eat;
	long			tt_sleep;
	long			nt_eat;
	long			total_meals;
	long			philo_meals;
	long			start_time;
	bool			end_sim;
	pthread_mutex_t	t_eat;
	pthread_mutex_t	m_end_sim;
	t_list			*philos;
}					t_philo;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isspace(int c);
int		parse_values(char **av);
int64_t	ft_atoll(const char *str);
long	get_current_time(void);
t_philo	*init_data(int ac, char **av);
void	eat(t_list *philo);
void	end_sim(t_philo *data);
void	exit_message(int pr);
void	ft_free_struct(t_philo *data);
void	*philo_routine(void	*arg);

#endif