#include <limits.h>

//solver cannot prove, so we should write a lemma, to simplify solver's task
/*@
  lemma divisibility:
    \forall integer a, b; a != 0 ==> (\exists int x; a * x == b) ==> b % a == 0;
*/

/*@
  requires \exists int x; a * x + b == 0;
  ensures a * \result + b == 0; 
*/

int solve(int a, int b)
{
  if (a == 0) {
    return 100;
  }  else if (b == INT_MIN) {
    /* a*x = + 2^31 , x \in [-2^31, 2^31 - 1],
       a \in [-2^31, 2^31 - 1]
       x = 2^31 / a => a \in {+-1, +-2, +-4, ..., +- 2^30, +-2^31}
       a = 1 => x = 2^31 ; impossible
       a = 2 => x = 2^30 ; ok
       a = 2^30 => x = 2 ; ok
       a = -1 => x = -2^31; ok
       a = -2 => x = -2^30; ok

       suppose x = (2^31/a)
    */ 
    if (a == INT_MIN) {
      return -1;
    } else {
      return b / (-a);
    }

  } else {
    return -b / a;
  }
}
