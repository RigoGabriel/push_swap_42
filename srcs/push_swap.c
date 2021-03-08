/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigo <grigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:15:10 by grigo             #+#    #+#             */
/*   Updated: 2021/03/08 14:57:25 by grigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int		ft_check_arg_error(t_pile *a, char **tab)
{
	int		first;

	if ((first = get_arg(tab, a)) == -1)
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
	if (check_error(tab, first) == -1)
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
	return (first);
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
	tab = get_cmd(av, 1, 0, 0);
	first = ft_check_arg_error(a, tab);
	i = ft_tablen(tab) - 1;
	while (i >= first)
	{
		empiler(a, ft_atoi(tab[i]));
		i--;
	}
	ft_splitdel(&tab);
	sort_pile(a, b);
	if (a->color == 1 || a->visual == 1)
		show_final_pile(a);
	if (a->total == 1)
		printf("total operation = %d\n", a->count);
	return (0);
}
