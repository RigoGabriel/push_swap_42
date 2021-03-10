/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigo <grigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:15:10 by grigo             #+#    #+#             */
/*   Updated: 2021/03/09 13:22:31 by grigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int		ft_check_arg_error(t_pile *a, t_pile *b, char **tab)
{
	int		first;

	if ((first = get_arg(tab, a, b)) == -1)
	{
		ft_splitdel(&tab);
		write(2, "Error\n", 6);
		exit(-1);
	}
	if (check_error(tab, first) == -1)
	{
		ft_splitdel(&tab);
		write(2, "Error\n", 6);
		exit(-1);
	}
	return (first);
}

void	check_tab(char **tab, int first)
{
	if (tab[first] == NULL)
	{
		ft_splitdel(&tab);
		write(2, "Error\n", 6);
		exit(-1);
	}
}

int		main(int ac, char *av[])
{
	int		i;
	int		first;
	t_pile	*a;
	t_pile	*b;
	char	**tab;

	if (ac <= 1)
		exit(0);
	a = initialiser(1);
	b = initialiser(1);
	if (!(tab = get_cmd(av, 1, 0)))
		exit(-1);
	first = ft_check_arg_error(a, b, tab);
	check_tab(tab, first);
	i = ft_tablen(tab);
	while (i-- > first)
		empiler(a, ft_atoi(tab[i]));
	ft_splitdel(&tab);
	sort_pile(a, b);
	return (0);
}
