#include "pile.h"

int   main(int ac, char *av[])
{
  int i;
  int first;
  t_pile *a;
  t_pile *b;
  char **tab;

  if (ac <= 1)
    exit(0);
  a = initialiser(1);
  b = initialiser(1);
  tab = get_cmd(av, 1, 0, 0);
  if ((first = get_arg(tab, a)) == -1)
  {
    write(2, "Error\n", 6);
    exit(-1);
  }
  if (check_error(tab, first) == -1)
  {
    write(2, "Error\n", 6);
    exit(-1);
  }
  i = ft_tablen(tab) - 1;
  while (i >= first)
  {
    empiler(a, ft_atoi(tab[i]));
    i--;
  }
  ft_splitdel(&tab);
  sort_pile(a, b);
  if (a->color == 1 || a->visual == 1)
    show_final_pile(a);
  if (a->total == 1)
    printf("total operation = %d\n", a->count);
  return (0);
}
