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

void	philo_think(t_list *philo)
{
	ft_print(1, philo);
	if (philo->id % 2 != 0 && (philo->data->n_philo % 2 != 0))
		ft_usleep(philo->data->think_time * 0.45, philo);
}

void	philo_sleep(t_list *philo)
{
	ft_print(3, philo);
	ft_usleep(philo->data->tt_sleep, philo);
}

void	eat(t_list *philo)
{
	check_status(philo);
	ft_print(2, philo);
	pthread_mutex_lock(&philo->data->add_meals);
	philo->data->total_meals++;
	philo->meals_count++;
	if (philo->meals_count == philo->data->nt_eat)
		philo->full = true;
	pthread_mutex_unlock(&philo->data->add_meals);
	check_status(philo);
	ft_usleep(philo->data->tt_eat, philo);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->next->fork);
		pthread_mutex_unlock(&philo->fork);
	}
	else
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
	}
}

void	take_forks(t_list *philo)
{
	if (philo->id % 2 == 0)
	{
		check_status(philo);
		pthread_mutex_lock(&philo->fork);
		check_status(philo);
		ft_print(4, philo);
		pthread_mutex_lock(&philo->next->fork);
	}
	else
	{
		pthread_mutex_lock(&philo->next->fork);
		check_status(philo);
		ft_print(4, philo);
		pthread_mutex_lock(&philo->fork);
	}
	check_status(philo);
	ft_print(4, philo);
	pthread_mutex_lock(&philo->data->t_eat);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->data->t_eat);
	eat(philo);
}

void	*philo_routine(void	*arg)
{
	t_list	*philo;

	philo = (t_list *)arg;
	if (philo->data->n_philo != 1 && philo->id % 2 != 0)
		ft_usleep(50, philo);
	philo->data->think_time = take_think(philo->data);
	//think time es t_eat *2 - t_sleep
	while (1)
	{
		if (check_status(philo))
			break ;
		take_forks(philo);
		if (check_status(philo))
			break ;
		philo_sleep(philo);
		if (check_status(philo))
			break ;
		philo_think(philo);
	}
	return (NULL);
}
