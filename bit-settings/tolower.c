#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

void flipTheChars(void);

int main() {
	
	printf("\nDo the bit flipping of CAPS chars to lowercased chars for ASCII chars...\n");
	flipTheChars();
	
	return EXIT_SUCCESS;
}

// A demo on how to switch upper case ASCII chars to lowercase
// using bit flipping. Things to note:
// - ASCII is 7 bit encoding system.
// - Flipping the sixth bit from the right to 1 makes an upper case letter lowercase.
// changes the case from uppercase to lowercase. For example:
//  0100 0001 is A
//  0010 0000 flipper byte, flips the 6th bit using binary or operator
//  0110 0001 is a, note the flipped 6th bit from the right.
void flipTheChars(void) {
	// Prepare an array of uppercase letters.
	char upperCased[27];
	strcpy(upperCased, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	
	// Have a flipper byte that is used to flip the 6th bit from the right.
	const uint8_t flipper = 0b00100000;
	
	int index = 0;
	while (index < strlen(upperCased)) {
		uint8_t upperCase = upperCased[index];
		uint8_t lowercase = (upperCase | flipper); // Flip the bits
		printf("Character %c in lowercase is %c\n", upperCase, lowercase);
		index++;
	}
}
