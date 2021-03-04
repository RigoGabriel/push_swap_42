#include "pile.h"

Pile *sort_stack(Pile *a, Pile *b)
{
  int tmp;

  while (pile_count(a) > 0)
  {
    tmp = depiler(a);
    while (pile_count(b) > 0 && b->first->nb > tmp)
      ft_pp(a, b);
    empiler(b, tmp);
  }
  return (b);
}

int main(int ac, char *av[])
{
  int i;
  Pile *a;
  Pile *b;

  if (ac <= 1)
    exit(0);
  if (check_error(av) == -1)
  {
    write(2, "Error\n", 6);
    exit(-1);
  }
  a = initialiser();
  b = initialiser();
  i = ac - 1;
  while (i > 0)
  {
    empiler(a, ft_atoi(av[i]));
    i--;
  }
  a = sort_stack(a, b);
  showPile(a);

  return (0);
}
