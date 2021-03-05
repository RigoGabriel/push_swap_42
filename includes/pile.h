#ifndef PILE_H
# define PILE_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct Element Element;
struct Element
{
  int nb;
  Element *next;
};

typedef struct Pile Pile;
struct Pile
{
  Element *first;
};

//fonction pile
void empiler(Pile *pile, int nb);
int depiler(Pile *pile);
void showPile(Pile *pile);
Pile *initialiser(void);
int pile_count(Pile *pile);

//fonction operation
void ft_ss(Pile *pile, char *cmd);
void ft_pp(Pile *empil, Pile *depile, char *cmd);
void ft_rr(Pile *pile, int lenght, char *cmd);
void ft_rrr(Pile *pile, int lenght, char *cmd);

//fonction commande
int ft_cmd(char *cmd, Pile *pile_a, Pile *pile_b);

//fonction check
int   ft_check_tri(Pile *pile);
int   ft_check(Pile *pile_a, Pile *pile_b);
int   check_error(char **av);

//fonction parsing
int   ft_nb_cmd(char **av, int i, int j, int len);
char  **get_cmd(char **av, int i, int j, int j_cmd);

//fonction sort_helper
int   find_max_elem(Pile *pile);

#endif
