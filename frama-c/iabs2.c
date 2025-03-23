#include <limits.h>

/*@
  requires \valid(a);
  ensures x != INT_MIN ==>
          ((((x >= 0) ==> *a == x) || ((x < 0) ==> *a == -x)) &&
          \result == 0);
  ensures x == INT_MIN ==> \result == -1;
*/

int iabs2(int x, int *a)
{
  if (x == INT_MIN) {
    return -1;
  } else if (x < 0) {
    x = -x;
  }
  *a = x;
  return 0;
}
