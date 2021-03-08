/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigo <grigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:06:36 by grigo             #+#    #+#             */
/*   Updated: 2021/03/08 14:06:38 by grigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int		ft_elem(t_pile *pile, int pos)
{
	t_element	*actuel;
	int			i;

	actuel = pile->first;
	i = 0;
	while (i < pos && actuel->next)
	{
		actuel = actuel->next;
		i++;
	}
	return (actuel->nb);
}

char	*ft_color(int max, int min, int nb, t_pile *a)
{
	if (nb == max && a->color == 1)
		return (RED);
	else if (nb == min && a->color == 1)
		return (GREEN);
	return (WHITE);
}
