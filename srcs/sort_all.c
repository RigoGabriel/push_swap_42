/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigo <grigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:20:21 by grigo             #+#    #+#             */
/*   Updated: 2021/03/08 14:22:21 by grigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int			find_place_in_a(t_pile *a, int len, int elem, char **rot_type)
{
	register int		i;
	register int		place;

	i = 0;
	place = 0;
	if (len == 2 && elem > ft_elem(a, 0) && elem < ft_elem(a, 1))
		place = 1;
	else if (len == 2 && elem < ft_elem(a, 0) && elem > ft_elem(a, 1))
		place = 0;
	else if (elem > ft_elem(a, find_max_elem(a)) ||
			elem < ft_elem(a, find_min_elem(a)))
		place = find_min_elem(a);
	else
		while (i < len)
		{
			if (elem > ft_elem(a, i) &&
					((i + 1 < len && elem < ft_elem(a, i + 1)) ||
					(i + 1 == len && elem < ft_elem(a, 0))))
			{
				place = i + 1;
				break ;
			}
			i++;
		}
	return (find_a_best_rotation(len, place, rot_type));
}

static void	insert_back_in_a(t_pile *a, t_pile *b)
{
	register int	num_of_rots;
	char			*rot_type;

	num_of_rots = 0;
	rot_type = ft_strnew(3);
	while (pile_count(b))
	{
		num_of_rots =
			find_place_in_a(a, pile_count(a), ft_elem(b, 0), &rot_type);
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
	place_smallest_first_a(a, b);
	free(rot_type);
}

static void	insert_leftover_to_b(t_pile *a, t_pile *b)
{
	int				idx;

	idx = 0;
	while (pile_count(a) > 2)
	{
		idx = find_min_elem(a);
		if (idx == 0)
			ft_cmd("pb", a, b);
		else if (idx <= pile_count(a) / 2)
			ft_cmd("ra", a, b);
		else if (idx > pile_count(a) / 2)
			ft_cmd("rra", a, b);
	}
}

static void	process_moves(t_move *best_move, t_pile *a, t_pile *b)
{
	while (best_move->a_moves)
	{
		if (!ft_strcmp(best_move->a_rot_type, "ra"))
			ft_cmd("ra", a, b);
		else
			ft_cmd("rra", a, b);
		best_move->a_moves--;
	}
	while (best_move->b_moves)
	{
		if (!ft_strcmp(best_move->b_rot_type, "rb"))
			ft_cmd("rb", a, b);
		else
			ft_cmd("rrb", a, b);
		best_move->b_moves--;
	}
}

void		sort_all(t_pile *a, t_pile *b)
{
	t_move			*best_move;
	int				optimizer;

	optimizer = (pile_count(a) > 200) ? 50 : 2;
	ft_cmd("pb", a, b);
	ft_cmd("pb", a, b);
	while (pile_count(a) > optimizer)
	{
		best_move = best_a_to_b(a, b);
		while (best_move->common_moves)
		{
			if (!ft_strcmp(best_move->common_rot, "rr"))
				ft_cmd("rr", a, b);
			else
				ft_cmd("rrr", a, b);
			best_move->common_moves--;
		}
		process_moves(best_move, a, b);
		ft_cmd("pb", a, b);
		free_move(best_move);
	}
	insert_leftover_to_b(a, b);
	insert_back_in_a(a, b);
}
