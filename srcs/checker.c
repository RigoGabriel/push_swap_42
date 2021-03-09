/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigo <grigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:02:34 by grigo             #+#    #+#             */
/*   Updated: 2021/03/09 14:05:06 by grigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

void	loop(t_pile *pile_a, t_pile *pile_b)
{
	char	*line;

	while (1)
	{
		if (get_next_line(0, &line) == 0)
		{
			free(line);
			break ;
		}
		if (ft_cmd(line, pile_a, pile_b) == 0)
		{
			free(line);
			free_pile(pile_a);
			free_pile(pile_b);
			write(2, "Error\n", 6);
			exit(-1);
		}
		free(line);
		line = NULL;
	}
	ft_check(pile_a, pile_b);
	free_pile(pile_a);
	free_pile(pile_b);
}

int		main(int ac, char *av[])
{
	int		i;
	char	**tab;
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (ac <= 1)
		exit(0);
	if (!(tab = get_cmd(av, 1, 0)))
		exit(-1);
	if (check_error(tab, 0) == -1)
	{
		ft_splitdel(&tab);
		write(2, "Error\n", 6);
		exit(-1);
	}
	pile_a = initialiser(0);
	pile_b = initialiser(0);
	i = ft_tablen(tab);
	while (i-- > 0)
		empiler(pile_a, ft_atoi(tab[i]));
	ft_splitdel(&tab);
	loop(pile_a, pile_b);
	return (0);
}
