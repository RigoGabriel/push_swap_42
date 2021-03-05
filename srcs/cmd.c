#include "pile.h"

void show(t_pile *a, t_pile *b)
{
  printf("Pile a\n");
  show_pile(a);
  printf("Pile b\n");
  show_pile(b);
  sleep(1);
  system("clear");
}

int ft_cmd(char *cmd, t_pile *pile_a, t_pile *pile_b)
{
  if (!ft_strcmp(cmd, "sa"))
    ft_ss(pile_a, cmd);
  else if (!ft_strcmp(cmd, "sb"))
    ft_ss(pile_b, cmd);
  else if (!ft_strcmp(cmd, "ss"))
  {
    ft_ss(pile_a, "ss");
    ft_ss(pile_b, NULL);
  }
  else if (!ft_strcmp(cmd, "pa"))
    ft_pp(pile_a, pile_b, cmd);
  else if (!ft_strcmp(cmd, "pb"))
    ft_pp(pile_b, pile_a, cmd);
  else if (!ft_strcmp(cmd, "ra"))
    ft_rr(pile_a, pile_count(pile_a), cmd);
  else if (!ft_strcmp(cmd, "rb"))
    ft_rr(pile_b, pile_count(pile_a), cmd);
  else if (!ft_strcmp(cmd, "rr"))
  {
    ft_rr(pile_a, pile_count(pile_a), "rr");
    ft_rr(pile_b, pile_count(pile_a), NULL);
  }
  else if (!ft_strcmp(cmd, "rra"))
    ft_rrr(pile_a, pile_count(pile_a), cmd);
  else if (!ft_strcmp(cmd, "rrb"))
    ft_rrr(pile_b, pile_count(pile_a), cmd);
  else if (!ft_strcmp(cmd, "rrr"))
  {
    ft_rrr(pile_a, pile_count(pile_a), "rrr");
    ft_rrr(pile_b, pile_count(pile_a), NULL);
  }
  else
    return (0);
  //show(pile_a, pile_b);
  return (1);
}
