/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:57:51 by pavicent          #+#    #+#             */
/*   Updated: 2024/12/18 12:57:55 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_status(t_list *philo)
{
	pthread_mutex_lock(&philo->data->m_status);
	pthread_mutex_lock(&philo->data->m_death);
	if (philo->data->end_sim == true)
	{
		pthread_mutex_unlock(&philo->data->m_death);
		pthread_mutex_unlock(&philo->data->m_status);
		return (1);
	}
	else if (philo->full == true)
	{
		pthread_mutex_unlock(&philo->data->m_death);
		pthread_mutex_unlock(&philo->data->m_status);
		return (1);
	}
	else if (philo->dead == true)
	{
		pthread_mutex_unlock(&philo->data->m_death);
		pthread_mutex_unlock(&philo->data->m_status);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->m_death);
	pthread_mutex_unlock(&philo->data->m_status);
	return (0);
}

long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	end_sim(t_philo *data)
{
	int		ph;
	t_list	*current;

	ph = 1;
	current = data->philos;
	while (ph <= data->n_philo)
	{
		pthread_join(current->thread_id, NULL);
		ph++;
		current = current->next;
	}
	ft_free_struct(data);
	exit(EXIT_SUCCESS);
}

void	ft_free_list(t_list *philo, t_philo *data)
{
	t_list	*tmp;
	int		i;

	i = 1;
	while (i <= data->n_philo)
	{
		tmp = philo;
		pthread_mutex_destroy(&tmp->fork);
		tmp->data = NULL;
		if (philo->next)
			philo = philo->next;
		tmp->next = NULL;
		free(tmp);
		tmp = NULL;
		i++;
	}
}

void	ft_free_struct(t_philo *data)
{
	ft_free_list(data->philos, data);
	pthread_mutex_destroy(&data->t_eat);
	pthread_mutex_destroy(&data->m_end_sim);
	pthread_mutex_destroy(&data->add_meals);
	pthread_mutex_destroy(&data->m_status);
	pthread_mutex_destroy(&data->m_time);
	pthread_mutex_destroy(&data->m_printf);
	pthread_mutex_destroy(&data->m_death);
	free(data);
}
