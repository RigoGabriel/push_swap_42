/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigo <grigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:01:24 by grigo             #+#    #+#             */
/*   Updated: 2021/03/08 14:01:27 by grigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int		ft_check_reverse_tri(t_pile *pile)
{
	t_element	*actuel;
	int			tmp;

	if (pile == NULL)
		return (0);
	actuel = pile->first;
	tmp = actuel->nb;
	while (1)
	{
		actuel = actuel->next;
		if (!actuel)
			break ;
		if (tmp < actuel->nb)
			return (0);
		tmp = actuel->nb;
	}
	return (1);
}

int		ft_check_tri(t_pile *pile)
{
	t_element	*actuel;
	int			tmp;

	if (pile == NULL)
		return (0);
	actuel = pile->first;
	tmp = actuel->nb;
	while (1)
	{
		actuel = actuel->next;
		if (!actuel)
			break ;
		if (tmp > actuel->nb)
			return (0);
		tmp = actuel->nb;
	}
	return (1);
}

int		ft_check(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_count(pile_b) == 0)
	{
		if ((ft_check_tri(pile_a) == 1 && pile_a->reverse == 0) ||
				(ft_check_reverse_tri(pile_a) == 1 && pile_a->reverse == 1))
			printf("OK\n");
		else
			printf("KO\n");
	}
	else
		printf("KO\n");
	return (0);
}
