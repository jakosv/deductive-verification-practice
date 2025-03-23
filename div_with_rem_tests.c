#include <limits.h>

/*@
  requires x1 >= 0;
  requires x2 > 0;
  requires \base_addr(z1) == \base_addr(z2) ==> z1 != z2;
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

/* 
  int t1;
  int t2;

  We use \valid for global varaible addresses since frama-c reduces it to
  pointers with dereference:

    requires \valid(&t1);
    requires \valid(&t2);

  Another way is to use 'global invariant' specificator for global var's
  to apply this for all global varaibles usage:

    global invariant valid_t1: \valid(&t1);
    global invariant valid_t2: \valid(&t2);
  */

int *nums;

/*@
  //global invariant valid_nums: \forall integeer i: 0 <= i <= 9 ==> \valid(&nums[i])
  global invariant valid_nums: \valid(nums + (0 .. 9)); 

  // (0 .. 9) means (min_offset .. max_offset);
  // and we got aliasing problem, which wasn't with using of global varaibles to
  // simplify proving
  // so, if there are pointers in program then frama-c enables aliasing check
*/

/*@
  //requires \valid(&t1);
  //requires \valid(&t2);
  //ensures t1 == 496;
  //ensures t2 == 2;
  
  ensures nums[0] == 496;
  ensures nums[1] == 2;
  ensures nums[2] == 15;
*/
static void test(void)
{
  nums[2] = 15; // we cannot prove that value saved after div 
                // so we should specify, that div modifies only nums[0] and nums[1]
                // with 'assign'
  div(1490, 3, nums, nums + 1);
}
