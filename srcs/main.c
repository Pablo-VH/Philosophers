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

void	check_total_meals(t_philo *data)
{
	if (data->total_meals == data->nt_eat * data->n_philo)
		data->end_sim = true;
}

void	check_death(t_list *philo)
{
	long	current_time;

	current_time = get_current_time();
	if (philo->meals_count > 0)
	{
		if (current_time > philo->last_meal + philo->data->tt_die)
		{
			philo->dead = true;
			philo->data->end_sim = true;
		}
	}
	else
	{
		if (current_time > philo->data->start_time + philo->data->tt_die)
		{
			philo->dead = true;
			philo->data->end_sim = true;
		}
	}
}
	

void	reaper(t_philo *data)
{
	t_list	*current;

	current = data->philos;
	while (1)
	{
		check_death(current);
		check_total_meals(data);
		if (current->dead == true)
		{
			printf("Time: [%ld] Philo🧝‍♂️: %d died 💀\n",
				get_current_time() - data->start_time, current->id);
			ft_free_struct(data);
			exit(EXIT_FAILURE);
		}
		if (data->end_sim)
			end_sim(data);
		current = current->next;
	}
}

void	create_philos(t_philo *data)
{
	int	ph;
	t_list *current;

	ph = 1;
	current = data->philos;
	while (ph <= data->n_philo)
	{
		pthread_create(&current->thread_id, NULL, philo_routine,
			current);
		current = current->next;
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
	reaper(data);
	return (0);
}
