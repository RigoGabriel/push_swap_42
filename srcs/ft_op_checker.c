#include "pile.h"

void ft_rrr(t_pile *pile, int lenght)
{
  int nb[lenght + 1];
  int i;

  if (lenght < 2)
    return ;
  i = 0;
  while (i < lenght)
  {
    nb[i] = depiler(pile);
    i++;
  }
  i -= 2;
  while (i >= 0)
  {
    empiler(pile, nb[i]);
    i--;
  }
  empiler(pile, nb[lenght - 1]);
}

void ft_rr(t_pile *pile, int lenght)
{
  int nb[lenght + 1];
  int i;

  if (lenght < 2)
    return ;
  i = 0;
  while (i < lenght)
  {
    nb[i] = depiler(pile);
    i++;
  }
  empiler(pile, nb[0]);
  i--;
  while (i >= 1)
  {
    empiler(pile, nb[i]);
    i--;
  }
}

void ft_ss(t_pile *pile)
{
  int nb[2];

  if ((pile_count(pile)) < 2)
    return ;
  nb[0] = depiler(pile);
  nb[1] = depiler(pile);
  empiler(pile, nb[0]);
  empiler(pile, nb[1]);
}

void ft_pp(t_pile *empil, t_pile *depile)
{
  int nb;

  if (pile_count(depile) < 1)
    return ;
  nb = depiler(depile);
  empiler(empil, nb);
}
