#include "pile.h"

int ft_isnum(char **av, int i, int *j)
{
  if (av[i][*j + 1] == '\0' || av[i][*j + 1] == ' ' || av[i][*j + 1] == '\n')
    return (-1);
  if (*j == 0)
  {
    *j += 1;
    while (av[i][*j] || av[i][*j] == ' ')
    {
      if (!ft_isdigit(av[i][*j]))
        return (-1);
      *j += 1;
    }
  }
  else if (av[i][*j - 1] != ' ')
    return (-1);
  else
  {
    *j += 1;
    while (av[i][*j] || av[i][*j] == ' ')
    {
      if (!ft_isdigit(av[i][*j]))
        return (-1);
      j++;
    }
  }
  return (0);
}

int   check_error(char **av, int first)
{
  int i;
  int j;
  long res;

  i = first;
  while (av[i])
  {
    j = 0;
    while (av[i][j] != '\0')
    {
      if (av[i][j] == '-')
      {
        if (ft_isnum(av, i, &j) == -1)
          return (-1);
      }
      else if (!ft_isdigit(av[i][j]))
        return (-1);
      j++;
    }
    i++;
  }
  i = first;
  while (av[i])
  {
    j = i + 1;
    while (av[j])
    {
      if (!ft_strcmp(av[i], av[j]))
        return (-1);
      j++;
    }
    i++;
  }
  i = first;
  while (av[i])
  {
    res = ft_atoi(av[i]);
    if (res > 2147483647 || res < -2147483648)
      return (-1);
    i++;
  }
  return (1);
}
