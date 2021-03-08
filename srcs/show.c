#include "pile.h"

void show_pile(t_pile *a, t_pile *b)
{
  t_element *actuel_a;
  t_element *actuel_b;
  int i;
  int j;

  actuel_b = b->first;
  actuel_a = a->first;
  i = pile_count(a) + pile_count(b) + 1;
  while (i >= 0)
  {
    j = 0;
    if (i < pile_count(a))
    {
      while (actuel_a->nb > j)
      {
        printf("-");
        j++;
      }
      while (j < 60)
      {
        printf(" ");
        j++;
      }
      actuel_a = actuel_a->next;
    }
    else
      printf("%*c", 10, ' ');
    j = 0;
    if (i < pile_count(b))
    {
      while (actuel_b->nb > j)
      {
        printf("-");
        j++;
      }
      while (j < 60)
      {
        printf(" ");
        j++;
      }
      actuel_b = actuel_b->next;
    }
    else
      printf("%*c", 10, ' ');
    printf("\n");
    i--;
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
    if (pile->color == 1)
      printf("%s", GREEN);
    printf("%d: ", actuel->nb);
    i = 0;
    while (i < actuel->nb)
    {
      printf("-");
      i++;
    }
    printf("\n");
    printf("%s", WHITE);
    system("sleep 0.05");
    actuel = actuel->next;
  }
}

void show(t_pile *a, t_pile *b)
{
  show_pile(a, b);
  system("sleep 0.1");
  system("clear");
}
