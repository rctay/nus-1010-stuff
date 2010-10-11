#include <stdio.h>

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

/* Print out an int[] on a line, with a space between each element. */
void print_int_arr(int *ptr, int len) {
	int i;
	if (len >= 1)
		printf("%d", *ptr);

	for (i = 1; i < len; i++)
		printf(" %d", *(ptr + i));

	printf("\n");
}

int main() {
	int arr[] = {1,-1,2,5,3,-2};
	int len = sizeof(arr)/sizeof(int);
	sel_sort(&arr[0], len);
	print_int_arr(arr, len);

	return 0;
}
