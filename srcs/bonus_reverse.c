/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigo <grigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:47:54 by grigo             #+#    #+#             */
/*   Updated: 2021/03/10 12:48:24 by grigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

void	insert_back_in_a_r(t_pile *a, t_pile *b)
{
	register int	num_of_rots;
	char			*rot_type;

	num_of_rots = 0;
	rot_type = ft_strnew(3);
	while (pile_count(b))
	{
		num_of_rots =
			find_place_in_a_r(a, pile_count(a), ft_elem(b, 0), &rot_type);
		while (num_of_rots > 0)
		{
			if (!ft_strcmp(rot_type, "ra"))
				ft_cmd("ra", a, b);
			else
				ft_cmd("rra", a, b);
			num_of_rots--;
		}
		ft_cmd("pa", a, b);
	}
	place_bigest_first_a(a, b);
	free(rot_type);
}

void	insert_leftover_to_b_r(t_pile *a, t_pile *b)
{
	int				idx;

	idx = 0;
	while (pile_count(a) > 2)
	{
		idx = find_max_elem(a);
		if (idx == 0)
			ft_cmd("pb", a, b);
		else if (idx <= pile_count(a) / 2)
			ft_cmd("ra", a, b);
		else if (idx > pile_count(a) / 2)
			ft_cmd("rra", a, b);
	}
}

void	place_bigest_first_a(t_pile *a, t_pile *b)
{
	register int	max_index;

	max_index = find_max_elem(a);
	if (max_index <= pile_count(a) / 2)
		while (max_index--)
			ft_cmd("ra", a, b);
	else
	{
		while ((pile_count(a) - max_index) > 0)
		{
			ft_cmd("rra", a, b);
			max_index++;
		}
	}
}

int		find_place_in_a_r(t_pile *a, int len, int elem, char **rot_type)
{
	register int	i;
	register int	place;

	i = 0;
	place = 0;
	if (len == 2 && elem < ft_elem(a, 0) && elem > ft_elem(a, 1))
		place = 1;
	else if (len == 2 && elem > ft_elem(a, 0) && elem < ft_elem(a, 1))
		place = 0;
	else if (elem < ft_elem(a, find_min_elem(a)) ||
			elem > ft_elem(a, find_max_elem(a)))
		place = find_max_elem(a);
	else
		while (i < len)
		{
			if (elem < ft_elem(a, i) &&
					((i + 1 < len && elem > ft_elem(a, i + 1)) ||
					(i + 1 == len && elem > ft_elem(a, 0))))
			{
				place = i + 1;
				break ;
			}
			i++;
		}
	return (find_a_best_rotation(len, place, rot_type));
}
