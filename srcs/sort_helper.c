#include "pile.h"

int   find_max_elem(Pile *pile)
{
  register int  i;
  register int  res;
  register int  id;
  Element       *actuel;

  actuel = pile->first;
  res = actuel->nb;
  i = 0;
  while (actuel)
  {
    if (res < actuel->nb)
    {
      res = actuel->nb;
      id = i;
    }
    actuel = actuel->next;
    i++;
  }
  return (id);
}
