/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:40:55 by pavicent          #+#    #+#             */
/*   Updated: 2024/12/05 11:40:56 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

void	exit_message(int pr)
{
	if (pr == 1)
		printf("./philo number_of_philosophers time_to_die time_to_eat time_to_sleep\n");
}