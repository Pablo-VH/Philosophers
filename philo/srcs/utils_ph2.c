/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ph2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:44:32 by pavicent          #+#    #+#             */
/*   Updated: 2024/12/20 11:26:47 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_one_philo(t_list *philo)
{
	ft_print(4, philo);
	ft_usleep(philo->data->tt_die, philo);
}

int	take_forks2(t_list *philo)
{
	pthread_mutex_lock(&philo->next->fork);
	ft_print(4, philo);
	if (check_status(philo))
	{
		pthread_mutex_unlock(&philo->next->fork);
		return (1);
	}
	pthread_mutex_lock(&philo->fork);
	if (check_status(philo))
	{
		pthread_mutex_unlock(&philo->next->fork);
		pthread_mutex_unlock(&philo->fork);
		return (1);
	}
	ft_print(4, philo);
	return (0);
}

int	take_forks3(t_list *philo)
{
	pthread_mutex_lock(&philo->fork);
	if (check_status(philo))
	{
		pthread_mutex_unlock(&philo->fork);
		return (1);
	}
	ft_print(4, philo);
	pthread_mutex_lock(&philo->next->fork);
	if (check_status(philo))
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		return (1);
	}
	ft_print(4, philo);
	return (0);
}

void	check_death2(t_list *philo, long current_time)
{
	if (current_time > philo->data->start_time + philo->data->tt_die)
	{
		pthread_mutex_lock(&philo->data->m_death);
		philo->dead = true;
		pthread_mutex_unlock(&philo->data->m_death);
		pthread_mutex_lock(&philo->data->m_status);
		philo->data->end_sim = true;
		pthread_mutex_unlock(&philo->data->m_status);
	}
}

void	ft_print(int pr, t_list *philo)
{
	pthread_mutex_lock(&philo->data->m_printf);
	pthread_mutex_lock(&philo->data->m_status);
	if (pr == 1 && philo->data->end_sim == false)
		printf("Time: [%ld] Philo🧝: %d is thinking 🤔\n",
			get_current_time() - philo->data->start_time, philo->id);
	else if (pr == 2 && philo->data->end_sim == false)
		printf("Time: [%ld] Philo🧝: %d is eating 🍜\n",
			get_current_time() - philo->data->start_time, philo->id);
	else if (pr == 3 && philo->data->end_sim == false)
		printf("Time: [%ld] Philo🧝: %d is sleeping 🛏️\n",
			get_current_time() - philo->data->start_time, philo->id);
	else if (pr == 4 && philo->data->end_sim == false)
		printf("Time: [%ld] Philo🧝: %d has taken a fork 🍴\n",
			get_current_time() - philo->data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->m_status);
	pthread_mutex_unlock(&philo->data->m_printf);
}
