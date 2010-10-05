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

	for (i = 0; i <= digits; i++) {
		digit = curr / exp;
		curr = curr % exp;
		exp /= 10;

		printf("got digit %d\n", digit);
	}

	return 0;
}
