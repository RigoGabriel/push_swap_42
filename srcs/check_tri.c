#include "pile.h"

int   ft_check_tri(Pile *pile)
{
  Element *actuel;
  int tmp;

  if (pile == NULL)
    return (0);
  actuel = pile->first;
  tmp = actuel->nb;
  while (1)
  {
    actuel = actuel->next;
    if (!actuel)
      break ;
    if (tmp > actuel->nb)
      return (0);
    tmp = actuel->nb;
  }
  return (1);
}

int   ft_check(Pile *pile_a, Pile *pile_b)
{
  if (pile_count(pile_b) == 0)
  {
    if (ft_check_tri(pile_a) == 1)
      printf("OK\n");
    else
      printf("KO\n");
  }
  else
    printf("KO\n");
  return (0);
}
