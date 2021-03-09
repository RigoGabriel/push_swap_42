/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigo <grigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:03:09 by grigo             #+#    #+#             */
/*   Updated: 2021/03/09 14:03:08 by grigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

void	free_move(t_move *moves)
{
	free(moves->a_rot_type);
	free(moves->b_rot_type);
	free(moves->common_rot);
	free(moves);
	moves = NULL;
}

void	free_pile(t_pile *pile)
{
	while (pile_count(pile) != 0)
		depiler(pile);
	free(pile);
}
