/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigo <grigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:00:35 by grigo             #+#    #+#             */
/*   Updated: 2021/03/08 14:00:37 by grigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int		ft_isnum(char **av, int i)
{
	int j;

	j = 1;
	while (av[i][j])
	{
		if (!ft_isdigit(av[i][j]))
			return (-1);
		j += 1;
	}
	return (0);
}

int		ft_check_digit(char **av, int i, int j)
{
	while (av[i])
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (av[i][0] == '-')
			{
				if (ft_isnum(av, i) == -1)
					return (-1);
			}
			else if (!ft_isdigit(av[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_double(char **av, int i, int j)
{
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (!ft_strcmp(av[i], av[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_error(char **av, int first)
{
	int		i;
	long	res;

	if (ft_check_digit(av, first, 0) == -1)
		return (-1);
	if (ft_check_double(av, first, 0) == -1)
		return (-1);
	i = first;
	while (av[i])
	{
		res = ft_atoi(av[i]);
		if (res > 2147483647 || res < -2147483648)
			return (-1);
		i++;
	}
	return (1);
}
