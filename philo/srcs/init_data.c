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

long	take_think(t_philo *data)
{
	if (data->tt_eat * 2 - data->tt_sleep <= 0)
		return (0);
	else
		return (data->tt_eat * 2 - data->tt_sleep);
}

void	ft_usleep(long wait, t_list *philo)
{
	long	start;

	start = get_current_time();
	while (1)
	{
		if (get_current_time() >= wait + start)
			break ;
		check_status(philo);
	}
}

void	init_mutex(t_philo *data)
{
	pthread_mutex_init(&data->m_end_sim, NULL);
	pthread_mutex_init(&data->t_eat, NULL);
	pthread_mutex_init(&data->add_meals, NULL);
	pthread_mutex_init(&data->m_status, NULL);
	pthread_mutex_init(&data->m_time, NULL);
	pthread_mutex_init(&data->m_printf, NULL);
	pthread_mutex_init(&data->m_death, NULL);
}

void	init_list(t_philo *data)
{
	t_list	*first;
	t_list	*tmp;
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
		pthread_mutex_init(&tmp->fork, NULL);
		tmp->meals_count = 0;
		tmp->dead = false;
		tmp->full = false;
		tmp->next = NULL;
		tmp->data = data;
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
	data->tt_die = ft_atoi(av[2]);
	data->tt_eat = ft_atoi(av[3]);
	data->tt_sleep = ft_atoi(av[4]);
	data->think_time = take_think(data);
	data->nt_eat = -1;
	data->start_time = get_current_time();
	if (ac == 6)
		data->nt_eat = ft_atoi(av[5]);
	init_mutex(data);
	data->philos = (t_list *)malloc(sizeof(t_list));
	data->philos->id = 1;
	data->philos->last_meal = 0;
	data->philos->meals_count = 0;
	data->philos->full = false;
	data->philos->dead = false;
	pthread_mutex_init(&data->philos->fork, NULL);
	data->philos->next = NULL;
	data->philos->data = data;
	return (init_list(data), data);
}
