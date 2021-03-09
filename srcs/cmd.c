/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigo <grigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:03:23 by grigo             #+#    #+#             */
/*   Updated: 2021/03/08 14:53:25 by grigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int		ft_cmd2(char *cmd, t_pile *pile_a, t_pile *pile_b)
{
	if (!ft_strcmp(cmd, "rr"))
	{
		ft_rr(pile_a, pile_count(pile_a));
		ft_rr(pile_b, pile_count(pile_b));
	}
	else if (!ft_strcmp(cmd, "rra"))
		ft_rrr(pile_a, pile_count(pile_a));
	else if (!ft_strcmp(cmd, "rrb"))
		ft_rrr(pile_b, pile_count(pile_b));
	else if (!ft_strcmp(cmd, "rrr"))
	{
		ft_rrr(pile_a, pile_count(pile_a));
		ft_rrr(pile_b, pile_count(pile_b));
	}
	else
		return (0);
	return (1);
}

void	ft_exec_arg(t_pile *pile_a, t_pile *pile_b, char *cmd)
{
	pile_a->count++;
	if (pile_a->flag == 1)
	{
		if (pile_a->visual == 1)
			printf("command = %s\n", cmd);
		else
			printf("%s\n", cmd);
	}
	if (pile_a->visual == 1)
		show(pile_a, pile_b);
}

int		ft_cmd(char *cmd, t_pile *pile_a, t_pile *pile_b)
{
	if (!ft_strcmp(cmd, "sa"))
		ft_ss(pile_a);
	else if (!ft_strcmp(cmd, "sb"))
		ft_ss(pile_b);
	else if (!ft_strcmp(cmd, "ss"))
	{
		ft_ss(pile_a);
		ft_ss(pile_b);
	}
	else if (!ft_strcmp(cmd, "pa"))
		ft_pp(pile_a, pile_b);
	else if (!ft_strcmp(cmd, "pb"))
		ft_pp(pile_b, pile_a);
	else if (!ft_strcmp(cmd, "ra"))
		ft_rr(pile_a, pile_count(pile_a));
	else if (!ft_strcmp(cmd, "rb"))
		ft_rr(pile_b, pile_count(pile_b));
	else
	{
		if (ft_cmd2(cmd, pile_a, pile_b) == 0)
			return (0);
	}
	ft_exec_arg(pile_a, pile_b, cmd);
	return (1);
}
