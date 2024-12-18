/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:10:54 by pavicent          #+#    #+#             */
/*   Updated: 2024/12/16 13:10:56 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//asegurame de comprobar siempre si hay algun philo muerto
void	philo_think(t_list *philo)
{
	printf("Time: [%ld] Philo🧝‍♂️: %d is thinking 🤔\n",
		get_current_time() - philo->data->start_time, philo->id);
}

void	philo_sleep(t_list *philo)
{
	printf("Time: [%ld] Philo🧝‍♂️: %d is sleeping 🛏️\n",
		get_current_time() - philo->data->start_time, philo->id);
	usleep(philo->data->tt_sleep * 1000);
}

void	eat(t_list *philo)
{
	printf("Time: [%ld] Philo🧝‍♂️: %d is eating 🍜\n",
		get_current_time() - philo->data->start_time, philo->id);
	pthread_mutex_lock(&philo->data->t_eat);
	philo->meals_count++;
	pthread_mutex_unlock(&philo->data->t_eat);
	usleep(philo->data->tt_eat * 1000);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->next->fork);
		pthread_mutex_unlock(&philo->fork);
	}
	if (philo->id % 2 != 0)
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
	}
}

void	take_forks(t_list *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->fork);
		printf("Time: [%ld] Philo🧝‍♂️ %d: has taken a fork 🍴\n",
			get_current_time() - philo->data->start_time, philo->id);
		pthread_mutex_lock(&philo->next->fork);
	}
	else
	{
		pthread_mutex_lock(&philo->next->fork);
		printf("Time: [%ld] Philo🧝‍♂️ %d: has taken a fork 🍴\n",
			get_current_time() - philo->data->start_time, philo->id);
		pthread_mutex_lock(&philo->fork);
	}
	printf("Time: [%ld] Philo🧝‍♂️ %d: has taken a fork 🍴\n",
		get_current_time() - philo->data->start_time, philo->id);
	pthread_mutex_lock(&philo->data->t_eat);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->data->t_eat);
	eat(philo);
}

void	*philo_routine(void	*arg)
{
	t_list	*philo;

	philo = (t_list *)arg;
	while (1)
	{
		
		if (philo->data->end_sim == true)
			break ;
		take_forks(philo);
		if (philo->data->end_sim == true)
			break ;
		philo_sleep(philo);
		if (philo->data->end_sim == true)
			break ;
		philo_think(philo);
		if (philo->data->end_sim == true)
			break ;
	}
	return (NULL);
}
