#include <math.h>
#include <limits.h>

/*@
  //requires a > 0;
  //requires b > 0;
  requires a*a <= INT_MAX;
  requires b*b <= INT_MAX;
  requires (a*a + b*b) <= INT_MAX;
  requires \exists integer c; c*c == (a*a + b*b);
  ensures \result * \result == (a*a + b*b);
*/

int hyp(int a, int b)
{
  int s = a*a + b*b;
  int i = 0;

  // Alt-Ergo fails this
  /*@
    //loop invariant 0 <= i*i <= (a*a + b*b);
    loop invariant i*i <= (a*a + b*b);
    loop variant (a*a + b*b) - i;
    // i*i < a*a + b*b
    // (i+1)(i+1) = i^2 + 2i + 1 
  */

  while (i*i < s)
    i += 1;
  return i;
}
/*
int main()
{
  return hyp(3, 5);
}
*/
