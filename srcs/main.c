/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:33:52 by pavicent          #+#    #+#             */
/*   Updated: 2024/12/05 11:33:55 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philos(t_philo *data)
{
	int	ph;

	ph = 1;
	while (ph < data->n_philo)
	{
		pthread_create(data->philos->thread_id, NULL, philo_routine,
			data->philos);
		ph++;
	}
}

int	main(int ac, char **av)
{
	t_philo	*data;

	if (ac != 5 && ac != 6)
		exit_message(1);
	if (!parse_values(av))
		exit_message(2);
	data = init_data(ac, av);
	create_philos(data);
}
