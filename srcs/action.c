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
void	philo_sleep(t_list *philo)
{
	printf("Philo🧝‍♂️: %d is sleeping 🛏️", philo->id);
	ft_usleep(philo, philo->data->tt_sleep);

}

void	eat(t_list *philo)
{
	printf("Philo🧝‍♂️: %d is eating 🍜", philo->id);
	pthread_mutex_lock(philo->data->t_eat);
	philo->data->total_meals++;
	pthread_mutex_unlock(philo->data->t_eat);
	ft_usleep(philo, philo->data->tt_eat);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->next->fork);
		printf("Philo🧝‍♂️ %d: has dropped a fork 🍴\n", philo->id);
		pthread_mutex_unlock(philo->fork);
		if (philo->data->nt_eat != -1)
			check_total_meals(philo);
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->fork);
		printf("Philo🧝‍♂️ %d: has dropped a fork 🍴\n", philo->id);
		pthread_mutex_unlock(philo->next->fork);
		if (philo->data->nt_eat != -1)
			check_total_meals(philo);
	}
}

void	take_forks(t_list *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->fork);
		printf("Philo🧝‍♂️ %d: has taken a fork 🍴\n", philo->id);
		pthread_mutex_lock(philo->next->fork);
	}
	else
	{
		pthread_mutex_lock(philo->next->fork);
		printf("Philo🧝‍♂️ %d: has taken a fork 🍴\n", philo->id);
		pthread_mutex_lock(philo->fork);
	}
	printf("Philo🧝‍♂️ %d: has taken a fork 🍴\n", philo->id);
	eat(philo);
}

void	philo_routine(void	*arg)
{
	t_list	*philo;

	philo = (t_list *)arg;
	while (1)
	{
		check_death(philo);
		take_forks(philo);
		check_death(philo);
		philo_sleep(philo);
		check_death(philo);
		philo_think(philo);
		check_death(philo);
	}
}
