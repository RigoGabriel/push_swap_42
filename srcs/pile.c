#include "pile.h"

Pile *initialiser(void)
{
    Pile *pile = malloc(sizeof(*pile));
    pile->first = NULL;
    return (pile);
}

int pile_count(Pile *pile)
{
  Element *actuel;
  int i;

  if (pile == NULL)
    return (0);
  actuel = pile->first;
  i = 0;
  while (actuel)
  {
    actuel = actuel->next;
    i++;
  }
  return (i);
}

void empiler(Pile *pile, int nb)
{
  Element *new;

  new = malloc(sizeof(*new));
  if (pile == NULL || new == NULL)
    exit(EXIT_FAILURE);
  new->nb = nb;
  new->next = pile->first;
  pile->first = new;
}

int depiler(Pile *pile)
{
  int nbDepile;
  Element *elDepile;

  if (pile == NULL)
    exit(EXIT_FAILURE);
  nbDepile = 0;
  elDepile = pile->first;
  if (pile != NULL && pile->first != NULL)
  {
    nbDepile = elDepile->nb;
    pile->first = elDepile->next;
    free(elDepile);
  }
  return (nbDepile);
}

void showPile(Pile *pile)
{
  Element *actuel;
  int i;

  if (pile == NULL)
    exit(EXIT_FAILURE);
  actuel = pile->first;
  while (actuel)
  {
    printf("%d: ", actuel->nb);
    i = 0;
    while (i < actuel->nb)
    {
      printf("-");
      i++;
    }
    printf("\n");
    actuel = actuel->next;
  }
}
