#include <stdio.h>
#include <stdlib.h>

/* Print out an int[] on a line, with a space between each element. */
void print_int_arr(int *ptr, int len) {
	int i;
	if (len >= 1) {
		printf("%d", *ptr);

		for (i = 1; i < len; i++)
			printf(" %d", *(ptr + i));

		printf("\n");
	}
}

void swap_smallest_to_front(int *ptr, int len) {
	/* position */
	int i;

	/* value of array at current position */
	int curr;

	/* current minimum and position of minimum */
	int min;
	int min_pos;

	if (len >= 1) {
		/* first element */
		min = ptr[0];
		min_pos = 0;
		/* immediately start with next element */
		for (i = 1; i < len; i++) {
			curr = *(ptr + i);
			if (curr < min) {
				min_pos = i;
				min = curr;
			}
		}
		*(ptr + min_pos) = *ptr;
		*ptr = min;
	}
}

void sel_sort(int *ptr, int len) {
	/* "recursively" partition the array, bringing the smallest
	 * element to the front each time. */
	int i;
	for (i = 0; i < len - 1; i++)
		swap_smallest_to_front(ptr + i, len - i);
}

int main() {
	int input;
	int len;
	int *arr;
	int *ptr;
	int i;

	while (scanf("%d", &input) == 1) {
		len = input;
		arr = malloc(len * sizeof(int));
		ptr = arr;
		for (i = 0; i < len; i++) {
			if (scanf("%d", &input) == 1) {
				*ptr = input;
				ptr++;
			}
		}
		sel_sort(arr, len);
		print_int_arr(arr, len);

		free(arr);
	}

	if (arr)
		free(arr);

	return 0;
}
