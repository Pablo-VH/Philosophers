/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:56:47 by pavicent          #+#    #+#             */
/*   Updated: 2024/12/09 10:56:49 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_len(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		while (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] == '0')
			i++;
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
				return (0);
			i++;
			len++;
		}
	}
	if (len > 10)
		return (0);
	return (len);
}

int	parse_values(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_check_len(av[i]) == 0)
			return (0);
		if (ft_atoi(av[i]) == 0 && ft_atoll(av[i]) != 0)
			return (0);
		if (ft_atoll(av[i]) > INT_MAX || ft_atoll(av[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}
