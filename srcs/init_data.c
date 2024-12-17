/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:41:06 by pavicent          #+#    #+#             */
/*   Updated: 2024/12/09 11:41:07 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_list(t_philo *data)
{
	t_list *first;
	t_list *tmp;
	int		i;

	first = data->philos;
	i = 1;
	while (i < data->n_philo)
	{
		tmp = (t_list *)malloc(sizeof(t_list));
		if (!tmp)
			exit_message(3);
		tmp->id = i + 1;
		tmp->last_meal = 0;
		pthread_mutex_init(tmp->fork, NULL);
		tmp->meals_count = 0;
		tmp->dead = false;
		tmp->next = NULL;
		data->philos->data = data;
		data->philos->next = tmp;
		data->philos = data->philos->next;
		i++;
	}
	data->philos->next = first;
	data->philos = first;
}

t_philo	*init_data(int ac, char **av)
{
	t_philo	*data;

	data = (t_philo *)malloc(sizeof(t_philo));
	data->total_meals = 0;
	data->end_sim = false;
	data->n_philo = ft_atoi(av[1]);
	data->tt_die = ft_atoi(av[2]) * 1000;
	data->tt_eat = ft_atoi(av[3]) * 1000;
	data->tt_sleep  = ft_atoi(av[4]) * 1000;
	data->nt_eat = -1;
	if (ac == 6)
		data->nt_eat = ft_atoi(av[5]);
	data->end_sim = false;
	pthread_mutex_init(data->m_end_sim, NULL);
	pthread_mutex_init(data->t_eat, NULL);
	data->philos = (t_list *)malloc(sizeof(t_list));
	data->philos->id = 1;
	data->philos->last_meal = 0;
	data->philos->meals_count = 0;
	pthread_mutex_init(data->philos->fork, NULL);
	data->philos->next = NULL;
	data->philos->data = data;
	init_list(data);
	return (data);
}
