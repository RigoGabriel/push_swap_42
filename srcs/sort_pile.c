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

static void		sort_little_pile(t_pile *a, t_pile *b, int len)
{
	register int	max_id;

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
	if (ft_check_tri(a) == 1)
		return ;
	if (pile_count(a) <= 3)
		sort_little_pile(a, b, pile_count(a));
	else
		sort_all(a, b);
}
