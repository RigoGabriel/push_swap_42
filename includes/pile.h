#ifndef PILE_H
# define PILE_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct  s_element
{
  int nb;
  struct s_element *next;
}               t_element;

typedef struct  s_pile
{
  t_element *first;
}               t_pile;

typedef struct  s_move
{
  int			elem;
	int			a_moves;
	char		*a_rot_type;
	char		*b_rot_type;
	char		*common_rot;
	int			b_moves;
	int			common_moves;
	int			total;
}               t_move;

//fonction pile
void empiler(t_pile *pile, int nb);
int depiler(t_pile *pile);
void show_pile(t_pile *pile);
t_pile *initialiser(void);
int pile_count(t_pile *pile);

//fonction operation
void ft_ss(t_pile *pile, char *cmd);
void ft_pp(t_pile *empil, t_pile *depile, char *cmd);
void ft_rr(t_pile *pile, int lenght, char *cmd);
void ft_rrr(t_pile *pile, int lenght, char *cmd);

//fonction commande
int ft_cmd(char *cmd, t_pile *pile_a, t_pile *pile_b);

//fonction check
int   ft_check_tri(t_pile *pile);
int   ft_check(t_pile *pile_a, t_pile *pile_b);
int   check_error(char **av);

//fonction parsing
int   ft_nb_cmd(char **av, int i, int j, int len);
char  **get_cmd(char **av, int i, int j, int j_cmd);

//fonction sort_helper
int   find_max_elem(t_pile *pile);
int   find_min_elem(t_pile *pile);
void	place_smallest_first_a(t_pile *a, t_pile *b);

//fonction best moves
t_move          *best_a_to_b(t_pile *a, t_pile *b);

//fonction outil
int             ft_elem(t_pile *pile, int pos);

//fonction best best_rotation
int		find_a_best_rotation(int len, int pos, char **a_rot_type);
int		find_b_best_rotation(int len, int pos, char **b_rot_type);

//fonction clear
void	free_move(t_move *moves);

//fonction sort
void sort_all(t_pile *a, t_pile *b);

#endif
