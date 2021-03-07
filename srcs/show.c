#include "pile.h"

void show(t_pile *a, t_pile *b)
{
  printf("Pile a\n");
  show_pile(a);
  printf("Pile b\n");
  show_pile(b);
  system("sleep 0.05");
  system("clear");
}
