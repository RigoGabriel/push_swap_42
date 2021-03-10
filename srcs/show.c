/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigo <grigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:18:28 by grigo             #+#    #+#             */
/*   Updated: 2021/03/10 16:42:34 by grigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

t_element	*print_a(t_pile *a, t_pile *b, int i, t_element *actuel_a)
{
	int			j;
	int			min;
	int			max;

	max = (get_max(a) > get_max(b)) ? get_max(a) : get_max(b);
	min = (get_min(a) < get_min(b)) ? get_min(a) : get_min(b);
	j = 0;
	if (i < pile_count(a))
	{
		printf("%s", ft_color(max, min, actuel_a->nb, a));
		printf("%4d: ", actuel_a->nb);
		while (actuel_a->nb > j++)
			printf("-");
		while (j++ < max + 10)
			printf(" ");
		actuel_a = actuel_a->next;
		printf("%s", WHITE);
	}
	else
		printf("%*c", max + 15, ' ');
	return (actuel_a);
}

t_element	*print_b(t_pile *b, t_pile *a, int i, t_element *actuel_b)
{
	int			min;
	int			max;
	int			j;

	max = (get_max(a) > get_max(b)) ? get_max(a) : get_max(b);
	min = (get_min(a) < get_min(b)) ? get_min(a) : get_min(b);
	j = 0;
	if (i < pile_count(b))
	{
		printf("%s", ft_color(max, min, actuel_b->nb, a));
		printf("%4d: ", actuel_b->nb);
		while (actuel_b->nb > j)
		{
			printf("-");
			j++;
		}
		while (j < max + 10)
		{
			printf(" ");
			j++;
		}
		actuel_b = actuel_b->next;
		printf("%s", WHITE);
	}
	return (actuel_b);
}

void		show_pile(t_pile *a, t_pile *b)
{
	t_element	*actuel_a;
	t_element	*actuel_b;
	int			i;

	actuel_b = b->first;
	actuel_a = a->first;
	i = pile_count(a) + pile_count(b) + 1;
	while (i >= 0)
	{
		actuel_a = print_a(a, b, i, actuel_a);
		actuel_b = print_b(b, a, i, actuel_b);
		printf("\n");
		i--;
	}
}

void		show_final_pile(t_pile *pile)
{
	t_element	*actuel;
	int			i;

	if (pile == NULL)
		return ;
	actuel = pile->first;
	while (actuel)
	{
		if (pile->color == 1)
			printf("%s", GREEN);
		printf("%4d: ", actuel->nb);
		i = 0;
		while (i < actuel->nb)
		{
			printf("-");
			i++;
		}
		printf("\n");
		printf("%s", WHITE);
		system("sleep 0.01");
		actuel = actuel->next;
	}
}

void		show(t_pile *a, t_pile *b)
{
	show_pile(a, b);
	system("sleep 0.05");
	system("clear");
}
