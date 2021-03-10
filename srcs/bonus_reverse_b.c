/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_reverse_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigo <grigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:48:41 by grigo             #+#    #+#             */
/*   Updated: 2021/03/10 12:48:54 by grigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int		find_place_in_b_2_r(t_pile *b, int len, int elem)
{
	register int	i;
	register int	place;

	place = 0;
	i = 0;
	while (i < len)
	{
		if (elem > ft_elem(b, i) &&
			((i + 1 < len && elem < ft_elem(b, i + 1)) ||
			(i + 1 == len && elem < ft_elem(b, 0))))
		{
			place = i + 1;
			break ;
		}
		i++;
	}
	return (place);
}

int		find_place_in_b_r(t_pile *b, int len, int elem, char **rot_type)
{
	register int	place;

	place = 0;
	if (len == 2 && elem < ft_elem(b, 0) && elem > ft_elem(b, 1))
		place = 0;
	else if (len == 2 && elem > ft_elem(b, 0) && elem < ft_elem(b, 1))
		place = 1;
	else if (elem < ft_elem(b, find_min_elem(b))
			|| elem > ft_elem(b, find_max_elem(b)))
		place = find_min_elem(b);
	else
		place = find_place_in_b_2_r(b, len, elem);
	return (find_b_best_rotation(len, place, rot_type));
}
