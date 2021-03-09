/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigo <grigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:29:56 by grigo             #+#    #+#             */
/*   Updated: 2021/03/09 14:39:32 by grigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PILE_H
# define PILE_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# define GREEN "\033[0;32m"
# define WHITE "\033[0;37m"
# define RED   "\033[0;31m"

typedef struct	s_element
{
	int					nb;
	struct s_element	*next;
}				t_element;

typedef struct	s_pile
{
	t_element	*first;
	int			flag;
	int			color;
	int			visual;
	int			total;
	int			count;
}				t_pile;

typedef struct	s_move
{
	int			elem;
	int			a_moves;
	char		*a_rot_type;
	char		*b_rot_type;
	char		*common_rot;
	int			b_moves;
	int			common_moves;
	int			total;
}				t_move;

/*
**fonction pile
*/
void			empiler(t_pile *pile, int nb);
int				depiler(t_pile *pile);
t_pile			*initialiser(int flag);
int				pile_count(t_pile *pile);

/*
**fonction operation
*/
void			ft_ss(t_pile *pile);
void			ft_pp(t_pile *empil, t_pile *depile);
void			ft_rr(t_pile *pile, int lenght);
void			ft_rrr(t_pile *pile, int lenght);

/*
**fonction commande
*/
int				ft_cmd(char *cmd, t_pile *pile_a, t_pile *pile_b);

/*
**fonction check
*/
int				ft_check_tri(t_pile *pile);
int				ft_check(t_pile *pile_a, t_pile *pile_b);
int				check_error(char **av, int first);

/*
**fonction parsing
*/
int				ft_nb_cmd(char **av, int i, int j, int len);
char			**get_cmd(char **av, int i, int index_cmd);
int				get_arg(char **tab, t_pile *a);

/*
**fonction sort_helper
*/
int				find_max_elem(t_pile *pile);
int				find_min_elem(t_pile *pile);
void			place_smallest_first_a(t_pile *a, t_pile *b);
int				get_max(t_pile *pile);
int				get_min(t_pile *pile);

/*
**fonction best moves
*/
t_move			*best_a_to_b(t_pile *a, t_pile *b);

/*
**fonction outil
*/
int				ft_elem(t_pile *pile, int pos);
char			*ft_color(int max, int min, int nb, t_pile *a);

/*
**fonction best best_rotation
*/
int				find_a_best_rotation(int len, int pos, char **a_rot_type);
int				find_b_best_rotation(int len, int pos, char **b_rot_type);

/*
**fonction clear
*/
void			free_move(t_move *moves);
void			free_pile(t_pile *pile);

/*
**fonction sort
*/
void			sort_all(t_pile *a, t_pile *b);
void			sort_pile(t_pile *a, t_pile *b);

/*
**fonction show
*/
void			show(t_pile *a, t_pile *b);
void			show_final_pile(t_pile *pile);

/*
**utils command
**ARG=`ruby -e "puts (1..130).to_a.shuffle.join(' ')"`
*/

#endif
