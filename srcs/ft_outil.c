#include "pile.h"

int             ft_elem(t_pile *pile, int pos)
{
  t_element *actuel;
  int i;

  actuel = pile->first;
  i = 0;
  while (i < pos && actuel->next)
  {
    actuel = actuel->next;
    i++;
  }
  return (actuel->nb);
}
