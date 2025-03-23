#include <limits.h>

/*@
  requires x1 >= 0;
  requires x2 > 0;
  requires \valid(z1);
  requires \valid(z2);
  ensures x1 == *z1 * x2 + *z2 && 0 <= *z2 < x2;
*/
void div(int x1, int x2, int *z1, int *z2)
{
  int y1 = 0, y2 = x2;
  /*@
    loop invariant \at(x1, Pre) == y1 * y2 + x1;
    loop invariant 0 <= x1;
    loop variant x1;
  */
  while (x1 >= y2) {
    ++y1;
    x1 -= y2;
  }

  *z1 = y1;
  *z2 = x1;
}
