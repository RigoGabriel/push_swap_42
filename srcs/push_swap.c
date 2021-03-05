#include "pile.h"

static void sort_little_pile(Pile *a, int len)
{
  register int  max_id;
  Element       *actuel;

  actuel = a->first;
  if (len == 1)
    return ;
  else if (len == 2)
  {
    if (actuel->nb > actuel->next->nb)
      ft_cmd("sa", a, NULL);
    return ;
  }
  else
  {
    max_id = find_max_elem(a);
    if (max_id == 0)
      ft_cmd("ra", a, NULL);
    else if (max_id == 1)
      ft_cmd("rra", a, NULL);
    actuel = a->first;
    if (actuel->nb > actuel->next->nb)
      ft_cmd("sa", a, NULL);
  }
}

void  sort_stack(Pile *a)
{
  if (pile_count(a) <= 3)
    sort_little_pile(a, pile_count(a));
}

int   main(int ac, char *av[])
{
  int i;
  Pile *a;
  char **tab;

  if (ac <= 1)
    exit(0);
  tab = get_cmd(av, 1, 0, 0);
  for (i = 0; tab[i]; i++)
  if (check_error(tab) == -1)
  {
    write(2, "Error\n", 6);
    exit(-1);
  }
  a = initialiser();
  i = ft_tablen(tab) - 1;
  while (i >= 0)
  {
    empiler(a, ft_atoi(tab[i]));
    i--;
  }
  ft_splitdel(&tab);
  //printf("Pile a first\n");
  sort_stack(a);
  showPile(a);
  //printf("Pile a after\n");
  //showPile(a);
  //system("leaks push_swap");
  return (0);
}
