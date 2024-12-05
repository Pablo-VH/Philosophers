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

//el tenedor con el que entran es el de la izquierda. Los pares cogen primero su tenedor, los impares el otro
typedef struct s_list
{
	int				id;
	pthread_mutex_t	fork;
	long			last_meal;
	struct s_list	*next;
	
}					t_list;

typedef struct s_philo
{
	int	n_philo;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
}		t_philo;



void	exit_message(int pr);

#endif