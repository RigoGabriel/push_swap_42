#include "pile.h"

void  loop(t_pile *pile_a, t_pile *pile_b)
{
  char *line;

  while (1)
  {
    if (get_next_line(0, &line) == 0)
      break;
    if (ft_cmd(line, pile_a, pile_b) == 0)
    {
      write(2, "Error\n", 6);
      exit(-1);
    }
    free(line);
    line = NULL;
  }
  ft_check(pile_a, pile_b);
}

int main(int ac, char *av[])
{
  int   i;
  char  **tab;
  t_pile  *pile_a;
  t_pile  *pile_b;

  if (ac <= 1)
    exit(0);
  tab = get_cmd(av, 1, 0, 0);
  if (check_error(tab, 0) == -1)
  {
    write(2, "Error\n", 6);
    exit(-1);
  }
  pile_a = initialiser(0);
  pile_b = initialiser(0);
  i = ft_tablen(tab) - 1;
  while (i >= 0)
  {
    empiler(pile_a, ft_atoi(tab[i]));
    i--;
  }
  loop(pile_a, pile_b);
  return (0);
}
