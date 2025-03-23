#include <stdio.h>
#include <limits.h>

/*@
  requires x != INT_MIN; 
  ensures (x >= 0) ==> \result == x;
  ensures (x < 0) ==> \result == -x;
*/
int iabs(int x);

int iabs(int x)
{
  if (x >= 0)
    return x;
  else
    return -x;
}

int main()
{
  int x;
  scanf("%d", &x);
  x = iabs(x);
  printf("%d\n", x);
}
