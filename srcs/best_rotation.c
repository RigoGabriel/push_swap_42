#include "pile.h"

int		find_a_best_rotation(int len, int pos, char **a_rot_type)
{
	printf("Enter in find_a_best_rotation\n");
	if (pos > len / 2)
	{
		*a_rot_type = ft_strcpy(*a_rot_type, "rra");
		if (len > 2)
			pos = len - pos;
	}
	else
		*a_rot_type = ft_strcpy(*a_rot_type, "ra");
	return (pos);
}

int		find_b_best_rotation(int len, int pos, char **b_rot_type)
{
	printf("Enter in find_b_best_rotation\n");
	if (pos > len / 2)
	{
		*b_rot_type = ft_strcpy(*b_rot_type, "rrb");
		if (len > 2)
			pos = len - pos;
	}
	else
		*b_rot_type = ft_strcpy(*b_rot_type, "rb");
	return (pos);
}
