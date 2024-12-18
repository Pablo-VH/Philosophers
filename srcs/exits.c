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
		printf("Error: Invalid number of arguments\n");
	else if (pr == 2)
		printf("Values must be digits\n");
	else if (pr == 3)
		printf("Error: Memory allocation failed\n");
	exit(EXIT_FAILURE);
}
