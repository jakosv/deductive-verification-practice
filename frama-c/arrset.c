/*@
  requires n >= 0;
  requires \valid(a + (0 .. n - 1));
  assigns a[0 .. n - 1];
  ensures \forall integer i; 0 <= i < n ==> a[i] == v;
*/
void arrset(int *a, int n, int v)
{
  int i = 0;
  /*@
    loop invariant 0 <= i <= n;
    loop invariant \forall integer j; 0 <= j < i ==> a[j] == v;
    loop variant n - i;
  */
  /*
  while (i < n) {
    a[i++] = v;
  }
  */
  for (i = 0; i < n; ++i) {
    a[i] = v;
  }
}
