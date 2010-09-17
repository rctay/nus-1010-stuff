#include <stdio.h>

int isLucas ( int num );

int main () {
  int num;

  scanf("%d", &num);

  printf("%d", isLucas (num));

  return 0;
}

/**
 * Returns -1 if not a Lucas number; else, an integer indicating the term of
 * the Lucas number.
 */
int isLucas ( int num ) {

  int cur, prev1, prev2;

  int ret, i;

  /* by default, not a Lucas number */
  ret = -1;

  /* L_(n-1) */
  prev1=1;
  /* L_(n-2) */
  prev2=2;

  cur = prev1+prev2;

  for (i=2; i < num; i++) {
    cur = prev1+prev2;

    /* L_(n-1) becomes the new L_(n-2) */
    prev2 = prev1;
    /* L_(n) becomes the new L_(n-1) */
    prev1 = cur;

    if (num = cur) {
      ret = i;
      break;
    }
  }

  return ret;
}
