/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigo <grigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:06:52 by grigo             #+#    #+#             */
/*   Updated: 2021/03/08 14:08:22 by grigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int		ft_cmp_arg_str(t_pile *a, int j)
{
	if (j == 0)
	{
		a->visual = 1;
		return (1);
	}
	else if (j == 1)
	{
		a->color = 1;
		return (1);
	}
	else if (j == 2)
	{
		a->total = 1;
		return (1);
	}
	return (0);
}

int		ft_cmparg(t_pile *a, char *str)
{
	int		j;
	char	*arg[4];

	arg[0] = "-v";
	arg[1] = "-c";
	arg[2] = "-t";
	arg[3] = NULL;
	j = 0;
	while (arg[j])
	{
		if (!ft_strcmp(arg[j], str))
			if (ft_cmp_arg_str(a, j) == 1)
				return (1);
		j++;
	}
	return (0);
}

int		get_arg(char **tab, t_pile *a)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if ((tab[i][0] != '-') || (tab[i][0] == '-' && ft_isdigit(tab[i][1])))
			return (i);
		if (!ft_cmparg(a, tab[i]))
			return (i);
		i++;
	}
	return (i);
}
