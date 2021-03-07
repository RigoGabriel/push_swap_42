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
  if (ft_check_tri(a) == 1)
    return ;
  if (pile_count(a) <= 3)
    sort_little_pile(a, b, pile_count(a));
  else
    sort_all(a, b);
}

int ft_cmparg(t_pile *a, char *str)
{
  int j;
  char *arg[4];

  arg[0] = "-v";
  arg[1] = "-c";
  arg[2] = "-t";
  arg[3] = NULL;
  j = 0;
  while (arg[j])
  {
    if (!ft_strcmp(arg[j], str))
    {
      if (j == 0)
      {
        a->visual = 1;
        return (1);
      }
      else if (j == 1)
      {
        a->color = 1;
        return (1);
      }
      else if (j == 2)
      {
        a->total = 1;
        return (1);
      }
    }
    j++;
  }
  return (0);
}
int get_arg(char **tab, t_pile *a)
{
  int i;

  i = 0;
  while (tab[i])
  {
    if ((tab[i][0] != '-') || (tab[i][0] == '-' && ft_isdigit(tab[i][1])))
      return (i);
    if (!ft_cmparg(a, tab[i]))
      return (i);
    i++;
  }
  return (i);
}

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
  sort_stack(a, b);
  if (a->color == 1 || a->visual == 1)
    show_final_pile(a);
  if (a->total == 1)
    printf("total operation = %d\n", a->count);
  return (0);
}
