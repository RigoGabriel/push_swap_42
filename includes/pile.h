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
void ft_ss(Pile *pile);
void ft_pp(Pile *empil, Pile *depile);
void ft_rr(Pile *pile, int lenght);
void ft_rrr(Pile *pile, int lenght);

//fonction commande
int ft_cmd(char *cmd, Pile *pile_a, Pile *pile_b);

//fonction checke
int   ft_check_tri(Pile *pile);
int   ft_check(Pile *pile_a, Pile *pile_b);
int   check_error(char **av);

#endif
