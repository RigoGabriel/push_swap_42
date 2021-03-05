#include "pile.h"

static void sort_little_pile(t_pile *a, t_pile *b, int len)
{
  register int  max_id;

  if (len == 1)
    return ;
  else if (len == 2)
  {
    if (a->first->nb > a->first->next->nb)
      ft_cmd("sa", a, b);
  }
  else
  {
    max_id = find_max_elem(a);
    if (max_id == 0)
      ft_cmd("ra", a, b);
    else if (max_id == 1)
      ft_cmd("rra", a, b);
    if (a->first->nb > a->first->next->nb)
      ft_cmd("sa", a, b);
  }
}

void  sort_stack(t_pile *a, t_pile *b)
{
  if (pile_count(a) <= 3)
    sort_little_pile(a, b, pile_count(a));
  else
    sort_all(a, b);
}

int   main(int ac, char *av[])
{
  int i;
  t_pile *a;
  t_pile *b;
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
  b = initialiser();
  i = ft_tablen(tab) - 1;
  while (i >= 0)
  {
    empiler(a, ft_atoi(tab[i]));
    i--;
  }
  ft_splitdel(&tab);
  sort_stack(a, b);
  show_pile(a);
  show_pile(b);
  //system("leaks push_swap");
  return (0);
}
