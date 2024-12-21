/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:33:52 by pavicent          #+#    #+#             */
/*   Updated: 2024/12/20 11:27:53 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_total_meals(t_philo *data)
{
	int		ph;
	int		tot;
	t_list	*current;

	ph = 1;
	current = data->philos;
	tot = 0;
	pthread_mutex_lock(&data->add_meals);
	while (ph <= data->n_philo)
	{
		if (current->full == true)
			tot++;
		ph++;
		current = current->next;
	}
	if (tot == data->n_philo)
	{
		pthread_mutex_lock(&data->m_status);
		data->end_sim = true;
		pthread_mutex_unlock(&data->m_status);
	}
	pthread_mutex_unlock(&data->add_meals);
}

void	check_death(t_list *philo)
{
	long	current_time;

	current_time = get_current_time();
	pthread_mutex_lock(&philo->data->add_meals);
	if (philo->meals_count > 0)
	{
		pthread_mutex_lock(&philo->data->t_eat);
		if (current_time > philo->last_meal + philo->data->tt_die)
		{
			pthread_mutex_lock(&philo->data->m_death);
			philo->dead = true;
			pthread_mutex_unlock(&philo->data->m_death);
			pthread_mutex_lock(&philo->data->m_status);
			philo->data->end_sim = true;
			pthread_mutex_unlock(&philo->data->m_status);
		}
		pthread_mutex_unlock(&philo->data->t_eat);
	}
	else
		check_death2(philo, current_time);
	pthread_mutex_unlock(&philo->data->add_meals);
}

void	reaper(t_philo *data)
{
	t_list	*current;

	current = data->philos;
	while (1)
	{
		check_death(current);
		check_total_meals(data);
		pthread_mutex_lock(&data->m_death);
		if (current->dead == true)
		{
			pthread_mutex_unlock(&data->m_death);
			printf("Time: [%ld] Philo🧝: %d died 💀\n",
				get_current_time() - data->start_time, current->id);
			end_sim(data);
		}
		pthread_mutex_unlock(&data->m_death);
		pthread_mutex_lock(&data->m_status);
		if (data->end_sim)
		{
			pthread_mutex_unlock(&data->m_status);
			end_sim(data);
		}
		pthread_mutex_unlock(&data->m_status);
		current = current->next;
	}
}

void	create_philos(t_philo *data)
{
	int		ph;
	t_list	*current;

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
