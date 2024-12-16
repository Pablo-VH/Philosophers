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

void	eat(t_list *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->fork);
		printf("Philo🧝‍♂️: %d, has taken a fork 🍴", philo->id);
		pthread_mutex_lock(philo->next->fork);
	}
	else
	{
		pthread_mutex_lock(philo->next->fork);
		printf("Philo🧝‍♂️: %d, has taken a fork 🍴", philo->id);
		pthread_mutex_lock(philo->fork);
	}
	printf("Philo🧝‍♂️: %d, has taken a fork 🍴", philo->id);
}

void	philo_routine(void	*arg)
{
	t_list	*philo;

	philo = (t_list *)arg;
	eat(philo);
	philo_sleep(philo);
}
