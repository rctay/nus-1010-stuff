#include <stdio.h>
#include <math.h>

int double_digit(int num);

int main () {
  int num;

  /* loop on input */
  while (scanf("%d", &num) == 1)
    printf("%d\n", double_digit(num));

  return 0;
}

int double_digit(int num) {
	int digits = (int) log10(num);
	int exp = (int) pow(10, digits);
	int i;
	int curr = num;
	int digit;
	int ret = 0;

	for (i = 0; i <= digits; i++) {
		digit = curr / exp;

		ret += digit*exp;

		printf("got digit %d\n", digit);

		curr = curr % exp;
		exp /= 10;
	}

	return ret;
}
