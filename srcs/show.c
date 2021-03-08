#include "pile.h"

char *ft_color(int max, int min, int nb, t_pile *a)
{
  if (nb == max && a->color == 1)
    return (RED);
  else if (nb == min && a->color == 1)
    return (GREEN);
  return (WHITE);
}

void show_pile(t_pile *a, t_pile *b)
{
  t_element *actuel_a;
  t_element *actuel_b;
  int i;
  int j;
  int max;
  int min;

  actuel_b = b->first;
  actuel_a = a->first;
  i = pile_count(a) + pile_count(b) + 1;
  max = (get_max(a) > get_max(b)) ? get_max(a) : get_max(b);
  min = (get_min(a) < get_min(b)) ? get_min(a) : get_min(b);
  while (i >= 0)
  {
    j = 0;
    if (i < pile_count(a))
    {
      printf("%s", ft_color(max, min, actuel_a->nb, a));
      printf("%d: ", actuel_a->nb);
      while (actuel_a->nb > j)
      {
        printf("-");
        j++;
      }
      while (j < max + 10)
      {
        printf(" ");
        j++;
      }
      actuel_a = actuel_a->next;
      printf("%s", WHITE);
    }
    else
      printf("%*c", max + 14, ' ');
    j = 0;
    if (i < pile_count(b))
    {
      printf("%s", ft_color(max, min, actuel_b->nb, a));
      printf("%d: ", actuel_b->nb);
      while (actuel_b->nb > j)
      {
        printf("-");
        j++;
      }
      while (j < max + 10)
      {
        printf(" ");
        j++;
      }
      actuel_b = actuel_b->next;
      printf("%s", WHITE);
    }
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
    printf("%4d: ", actuel->nb);
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
  system("sleep 0.05");
  system("clear");
}
