#include <stdio.h>
#include <limits.h>

void printBits(size_t const size, void const * const ptr);

int main() {
	// Overflow with signed int, 32 bits.
	int largeNumber = INT_MAX - 2;
	
	for (int counter = 0; counter < 5; counter++) {
		largeNumber++;
		printf("signed int number  : %12d  ", largeNumber);
		printBits(sizeof(unsigned int), &largeNumber);
	}
	
	// Overflow with unsigned int, 32 bits.
	unsigned int largeNumber2 = UINT_MAX - 2;
	
	for (int counter = 0; counter < 5; counter++) {
		largeNumber2++;
		printf("unsigned int number: %12u  ", largeNumber2);
		printBits(sizeof(unsigned int), &largeNumber2);
	}
	return 0;
}

void printBits(size_t const size, void const * const ptr)
{
	unsigned char *b = (unsigned char*) ptr;
	unsigned char byte;
	int i, j;
	
	for (i = size-1; i >= 0; i--) {
		for (j = 7; j >= 0; j--) {
			byte = (b[i] >> j) & 1;
			printf("%u", byte);
			if (j % 4 == 0) {
				printf(" ");
			}
		}
	}
	puts("");
}
