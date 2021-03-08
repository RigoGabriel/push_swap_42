/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigo <grigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:24:38 by grigo             #+#    #+#             */
/*   Updated: 2021/03/08 14:24:39 by grigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int		find_max_elem(t_pile *pile)
{
	register int	i;
	register int	res;
	register int	id;
	t_element		*actuel;

	if (pile_count(pile) == 0)
		return (-1);
	actuel = pile->first;
	res = actuel->nb;
	i = 0;
	id = 0;
	while (actuel)
	{
		if (res < actuel->nb)
		{
			res = actuel->nb;
			id = i;
		}
		actuel = actuel->next;
		i++;
	}
	return (id);
}

int		find_min_elem(t_pile *pile)
{
	register int	i;
	register int	res;
	register int	id;
	t_element		*actuel;

	if (pile_count(pile) == 0)
		return (-1);
	actuel = pile->first;
	res = actuel->nb;
	i = 0;
	id = 0;
	while (actuel)
	{
		if (res > actuel->nb)
		{
			res = actuel->nb;
			id = i;
		}
		actuel = actuel->next;
		i++;
	}
	return (id);
}

int		get_max(t_pile *pile)
{
	register int	res;
	t_element		*actuel;

	if (pile_count(pile) == 0)
		return (-1);
	actuel = pile->first;
	res = actuel->nb;
	while (actuel)
	{
		if (res < actuel->nb)
			res = actuel->nb;
		actuel = actuel->next;
	}
	return (res);
}

int		get_min(t_pile *pile)
{
	register int	res;
	t_element		*actuel;

	if (pile_count(pile) == 0)
		return (-1);
	actuel = pile->first;
	res = actuel->nb;
	while (actuel)
	{
		if (res > actuel->nb)
			res = actuel->nb;
		actuel = actuel->next;
	}
	return (res);
}

void	place_smallest_first_a(t_pile *a, t_pile *b)
{
	register int	min_index;

	min_index = find_min_elem(a);
	if (min_index <= pile_count(a) / 2)
		while (min_index--)
			ft_cmd("ra", a, b);
	else
	{
		while ((pile_count(a) - min_index) > 0)
		{
			ft_cmd("rra", a, b);
			min_index++;
		}
	}
}
