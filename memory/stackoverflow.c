#include <stdio.h>
#include <stdlib.h>

/*
 See how stack overflow happens.

 After seeing it, comment out line 20
 and uncomment the two commented out lines.
 No more stack overflow.
 */
void recursive(int repeats);

int main() {
	recursive(40);
	return 0;
}

void recursive(int repeats) {
	printf("Repeats left: %d\n", repeats);
	char array[300000] = {0};
	// long *array = malloc(sizeof(long) * 100000);

	if (--repeats >= 0) {
		recursive(repeats);
	} else {
		printf("At the bottom!\n");
	}
	// free(array);
}
