/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigo <grigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:11:02 by grigo             #+#    #+#             */
/*   Updated: 2021/03/08 14:14:06 by grigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

t_pile	*initialiser(int f)
{
	t_pile *pile;

	if (!(pile = malloc(sizeof(*pile))))
	{
		write(2, "malloc failed\n", 14);
		exit(-1);
	}
	pile->first = NULL;
	pile->flag = f;
	pile->color = 0;
	pile->visual = 0;
	pile->total = 0;
	pile->count = 0;
	pile->reverse = 0;
	return (pile);
}

int		pile_count(t_pile *pile)
{
	t_element	*actuel;
	int			i;

	if (pile == NULL)
		return (0);
	actuel = pile->first;
	i = 0;
	while (actuel)
	{
		actuel = actuel->next;
		i++;
	}
	return (i);
}

void	empiler(t_pile *pile, int nb)
{
	t_element	*new;

	new = malloc(sizeof(*new));
	if (pile == NULL || new == NULL)
		exit(EXIT_FAILURE);
	new->nb = nb;
	new->next = pile->first;
	pile->first = new;
}

int		depiler(t_pile *pile)
{
	int			nb_depile;
	t_element	*el_depile;

	if (pile == NULL)
		exit(EXIT_FAILURE);
	nb_depile = 0;
	el_depile = pile->first;
	if (pile != NULL && pile->first != NULL)
	{
		nb_depile = el_depile->nb;
		pile->first = el_depile->next;
		free(el_depile);
	}
	return (nb_depile);
}
