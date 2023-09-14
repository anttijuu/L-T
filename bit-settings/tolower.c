#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// A demo on how to switch upper case ASCII chars to lowercase
// using bit flipping. Things to note:
// - ASCII is 7 bit encoding system.
// - Flipping the sixth bit from the right to 1 makes an upper case letter lowercase.
// changes the case from uppercase to lowercase. For example:
//  0100 0001 is A
//  0010 0000 flipper byte, flips the 6th bit using binary or operator
//  0110 0001 is a, note the flipped 6th bit from the right.

// Note: C standard does not specify if char is signed or unsigned.
// See e.g. https://stackoverflow.com/questions/15533115/why-dont-the-c-or-c-standards-explicitly-define-char-as-signed-or-unsigned
// Therefore, compilers / platforms may use either or.
// Here we use uint8_t for a single char, which means unsigned.
// Luckily this doesn't matter so much since we are only supporting ASCII letters
// A...Z and a...z in this little demonstration :)

void flipTheChars(void);
uint8_t flipOneUpperCaseChar(uint8_t c);
char * flipUpperCaseString(char * string);

int main() {
	printf("Size of char is %lu byte\n", sizeof(char));
	printf("\nDo the bit flipping of CAPS chars to lowercased chars for ASCII chars...\n");
	flipTheChars();
	
	printf("\nPlease enter a CAPS LOCK string to convert to lowercase > ");
	char string[100];
	fgets(string, sizeof(string)-1, stdin);
	string[strlen(string)-1] = '\0';
	printf("Flipped: %s\n", flipUpperCaseString(string));
	
	return EXIT_SUCCESS;
}

void flipTheChars(void) {
	// Prepare an array of uppercase letters.
	char upperCased[27];
	strcpy(upperCased, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	
	int index = 0;
	while (index < strlen(upperCased)) {
		uint8_t upperCase = upperCased[index];
		uint8_t lowercase = flipOneUpperCaseChar(upperCase); // Flip the bits
		printf("Character %c in lowercase is %c\n", upperCase, lowercase);
		index++;
	}
}

uint8_t flipOneUpperCaseChar(uint8_t c) {
	// If not an upper case char, return the unmodified char.
	if (c < 'A' && c > 'Z') {
		return c;
	}
	// Have a flipper byte that is used to flip the 6th bit from the right.
	const uint8_t flipper = 0b00100000;
	return c | flipper;
}

char * flipUpperCaseString(char * string) {
	for (int index = 0; index < strlen(string); index++) {
		string[index] = flipOneUpperCaseChar(string[index]);
	}
	return string;
}
