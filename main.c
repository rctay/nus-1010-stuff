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

	/* current minimum */
	int *min_ptr;

	/* old head - used later on */
	int old;

	if (len >= 1) {
		/* first element */
		min_ptr = ptr;
		/* immediately start with next element */
		for (i = 1, ptr++; i < len; i++, ptr++)
			if (*ptr < *min_ptr)
				min_ptr = ptr;

		/* reset ptr */
		ptr -= len;

		/* save temporarily the first element */
		old = *ptr;
		*ptr = *min_ptr;
		*min_ptr = old;
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
	int len, i;

	/* warning: int* a, b won't work! */
	int *arr, *ptr;

	/*
	 * Read a series of integers; the first is the length <n> of the
	 * sequence of integers to be sorted, and all other integers (up
	 * to <n>) will be treated as the integers to be sorted.
	 *
	 * Length <n> must be at least 2.
	 */
	while (scanf("%d", &len) == 1) {
		if (! (len >= 2)) {
			fprintf(stderr, "Please enter a valid length!\n");
			continue;
		}

		arr = malloc(len * sizeof(int));
		ptr = arr;

		for (i = 0; i < len; i++)
			if (scanf("%d", ptr) == 1)
				ptr++;

		sel_sort(arr, len);
		print_int_arr(arr, len);

		free(arr);
	}

	if (arr)
		free(arr);

	return 0;
}
