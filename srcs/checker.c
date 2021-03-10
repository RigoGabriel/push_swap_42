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

int		ft_check_arg_error(t_pile *pile_a, t_pile *pile_b, char **tab)
{
	int id;

	id = 0;
	if (!ft_strcmp(tab[0], "-r"))
	{
		pile_a->reverse = 1;
		pile_b->reverse = 1;
		id = 1;
	}
	if (check_error(tab, id) == -1)
	{
		free_pile(pile_a);
		free_pile(pile_b);
		ft_splitdel(&tab);
		write(2, "Error\n", 6);
		exit(-1);
	}
	return (id);
}

int		main(int ac, char *av[])
{
	int		i;
	int		id;
	char	**tab;
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (ac <= 1)
		exit(0);
	if (!(tab = get_cmd(av, 1, 0)))
		exit(-1);
	pile_a = initialiser(0);
	pile_b = initialiser(0);
	id = ft_check_arg_error(pile_a, pile_b, tab);
	i = ft_tablen(tab);
	while (i-- > id)
		empiler(pile_a, ft_atoi(tab[i]));
	ft_splitdel(&tab);
	loop(pile_a, pile_b);
	return (0);
}
