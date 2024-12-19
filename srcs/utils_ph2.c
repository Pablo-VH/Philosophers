/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ph2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:44:32 by pavicent          #+#    #+#             */
/*   Updated: 2024/12/19 12:44:34 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
