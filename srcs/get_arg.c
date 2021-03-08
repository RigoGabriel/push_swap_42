#include "pile.h"

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
