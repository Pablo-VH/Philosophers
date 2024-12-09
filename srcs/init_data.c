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
	i = 0;
	while (i < data->n_philo - 1)
	{
		tmp = (t_list *)malloc(sizeof(t_list));
		tmp->id = i + 2;
		tmp->last_meal = 0;
		//tmp->fork = NULL;
		tmp->next = NULL;
		data->philos->next = tmp;
		data->philos = data->philos->next;
		i++;
	}
	data->philos = first;
}

void	init_data(t_philo *data, int ac, char **av)
{
	data = (t_philo *)malloc(sizeof(t_philo));
	data->n_philo = ft_atoi(av[1]);
	data->tt_die = ft_atoi(av[2]);
	data->tt_eat = ft_atoi(av[3]);
	data->tt_sleep  = ft_atoi(av[4]);
	data->nt_eat = 0;
	if (ac == 6)
		data->nt_eat = ft_atoi(av[5]);
	data->philos = (t_list *)malloc(sizeof(t_list));
	data->philos->id = 1;
	data->philos->last_meal = 0;
	//data->philos->fork = NULL;
	data->philos->next = NULL;
	init_list(data);
}
