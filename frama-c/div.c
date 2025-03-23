#include <limits.h>

/*@
  requires x1 >= 0;
  requires x2 > 0;
  ensures \exists integer z2; x1 == \result * x2 + z2 && 0 <= z2 < x2;
*/
int div(int x1, int x2)
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

  return y1;
}
