#include "pile.h"

static int		find_common(t_move *moves)
{
	register int		common;

	printf("Enter in find_common\n");
	common = 0;
	if ((!ft_strcmp(moves->a_rot_type, "rra") && (!ft_strcmp(moves->b_rot_type , "rrb"))) ||
			(!ft_strcmp(moves->a_rot_type, "ra") && (!ft_strcmp(moves->b_rot_type , "rb"))))
	{
		common = (moves->a_moves > moves->b_moves ? moves->b_moves : moves->a_moves);
		if (common)
		{
			moves->common_rot = ft_strcpy(moves->common_rot, moves->a_rot_type);
			moves->common_rot[ft_strlen(moves->common_rot) - 1] = 'r';
			moves->b_moves -= common;
			moves->a_moves -= common;
		}
	}
	return (common);
}

static int		find_place_in_b(t_pile *b, int len, int elem, char **rot_type)
{
	register int i;
	register int place;

	printf("Enter in find_place_in_b\n");
	i = 0;
	place = 0;
	if (len == 2 && elem > ft_elem(b, 0) && elem < ft_elem(b, len - 1))
		place = 0;
	else if (len == 2 && elem < ft_elem(b, 0) && elem > ft_elem(b, len - 1))
		place = 1;
	else if (elem > ft_elem(b, find_max_elem(b)) || elem < ft_elem(b, find_min_elem(b)))
		place = find_max_elem(b);
	else
	{
		while (i < len)
		{
			if (elem < ft_elem(b, i) && ((i + 1 < len && elem > ft_elem(b, i + 1)) ||
			(i + 1 == len && elem > ft_elem(b, 0))))
			{
				place = i + 1;
				break ;
			}
			i++;
		}
	}
	return (find_b_best_rotation(len, place, rot_type));
}

static t_move	  *calc_moves_from_a_to_b(t_pile *a, t_pile *b, int pos)
{
	t_move *moves;

	printf("Enter in calc_moves_from_a_to_b\n");
	moves = (t_move *)malloc(sizeof(t_move));
	moves->a_rot_type = ft_strnew(3);
	moves->b_rot_type = ft_strnew(3);
	moves->common_rot = ft_strnew(3);
	moves->elem = ft_elem(a, pos);
	moves->a_moves = find_a_best_rotation(pile_count(a), pos, &(moves->a_rot_type));
	moves->b_moves = find_place_in_b(b, pile_count(b), moves->elem, &(moves->b_rot_type));
	moves->common_moves = find_common(moves);
	moves->total = moves->a_moves + moves->b_moves + moves->common_moves + 1;
	return (moves);
}

t_move          *best_a_to_b(t_pile *a, t_pile *b)
{
  register int		i;
	t_move					*best_move;
	t_move					*moves;

	printf("Enter in best_a_to_b\n");
	i = 0;
	while (i < pile_count(a))
	{
		moves = calc_moves_from_a_to_b(a, b, i);
		if (i == 0)
			best_move = moves;
		else if (best_move->total > moves->total)
		{
			free_move(best_move);
			best_move = moves;
		}
		else
			free_move(moves);
		i++;
	}
	return (best_move);
}
