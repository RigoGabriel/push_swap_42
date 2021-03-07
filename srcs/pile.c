#include "pile.h"

t_pile *initialiser(int f)
{
    t_pile *pile = malloc(sizeof(*pile));
    pile->first = NULL;
    pile->flag = f;
    pile->color = 0;
    pile->visual = 0;
    pile->total = 0;
    pile->count = 0;
    return (pile);
}

int pile_count(t_pile *pile)
{
  t_element *actuel;
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

void empiler(t_pile *pile, int nb)
{
  t_element *new;

  new = malloc(sizeof(*new));
  if (pile == NULL || new == NULL)
    exit(EXIT_FAILURE);
  new->nb = nb;
  new->next = pile->first;
  pile->first = new;
}

int depiler(t_pile *pile)
{
  int nbDepile;
  t_element *elDepile;

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

void show_pile(t_pile *pile)
{
  t_element *actuel;
  int i;

  if (pile == NULL)
    return ;
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

void show_final_pile(t_pile *pile)
{
  t_element *actuel;
  int i;

  if (pile == NULL)
    return ;
  actuel = pile->first;
  while (actuel)
  {
    printf("\033[0;32m");
    printf("%d: ", actuel->nb);
    i = 0;
    while (i < actuel->nb)
    {
      printf("-");
      i++;
    }
    printf("\n");
    system("sleep 0.05");
    actuel = actuel->next;
  }
}
