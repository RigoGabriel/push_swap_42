#include "pile.h"

int   check_error(char **av)
{
  int i;
  int j;
  long res;

  i = 0;
  while (av[i])
  {
    j = 0;
    while (av[i][j] != '\0')
    {
      if ((av[i][j] < 48 || av[i][j] > 57) && av[i][0] != 45)
        return (-1);
      j++;
    }
    i++;
  }
  i = 0;
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
  i = 0;
  while (av[i])
  {
    res = ft_atoi(av[i]);
    if (res > 2147483647 || res < -2147483648)
      return (-1);
    i++;
  }
  return (1);
}
