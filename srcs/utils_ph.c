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

long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	end_sim(t_philo *data)
{
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
	/*if (data->philos)
		free(data->philos);*/
	pthread_mutex_destroy(&data->t_eat);
	pthread_mutex_destroy(&data->m_end_sim);
	free(data);
}
