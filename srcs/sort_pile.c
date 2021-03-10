/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigo <grigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:25:31 by grigo             #+#    #+#             */
/*   Updated: 2021/03/08 14:25:35 by grigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

static void		sort_little_pile_r(t_pile *a, t_pile *b, int len)
{
	register int	min_id;

	if (len == 1)
		return ;
	else if (len == 2)
	{
		if (a->first->nb < a->first->next->nb)
			ft_cmd("sa", a, b);
	}
	else
	{
		min_id = find_min_elem(a);
		if (min_id == 0)
			ft_cmd("ra", a, b);
		else if (min_id == 1)
			ft_cmd("rra", a, b);
		if (a->first->nb < a->first->next->nb)
			ft_cmd("sa", a, b);
	}
}

static void		sort_little_pile(t_pile *a, t_pile *b, int len)
{
	register int	max_id;

	if (a->reverse == 1)
	{
		sort_little_pile_r(a, b, len);
		return ;
	}
	if (len == 1)
		return ;
	else if (len == 2)
	{
		if (a->first->nb > a->first->next->nb)
			ft_cmd("sa", a, b);
	}
	else
	{
		max_id = find_max_elem(a);
		if (max_id == 0)
			ft_cmd("ra", a, b);
		else if (max_id == 1)
			ft_cmd("rra", a, b);
		if (a->first->nb > a->first->next->nb)
			ft_cmd("sa", a, b);
	}
}

void			sort_pile(t_pile *a, t_pile *b)
{
	if ((ft_check_tri(a) == 1 && a->reverse == 0)
			|| (ft_check_reverse_tri(a) == 1 && a->reverse == 1))
		return ;
	if (pile_count(a) <= 3)
		sort_little_pile(a, b, pile_count(a));
	else
		sort_all(a, b);
	if (a->color == 1 || a->visual == 1)
		show_final_pile(a);
	if (a->total == 1)
		printf("total operation = %d\n", a->count);
	free_pile(a);
	free_pile(b);
}
