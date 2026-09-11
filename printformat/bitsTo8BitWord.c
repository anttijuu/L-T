#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

void printBits(size_t const size, void const * const ptr);
void printUsage(const char * binaryName);
int signedToInt(const char * bits);
int unsignedToInt(const char * bits);

const int SIGNED = 0;
const int UNSIGNED = 1;

int main(int argc, char * argv[]) {
	
	if ((argc != 2 && argc != 3)) {
		printUsage(argv[0]);
		return EXIT_SUCCESS;
	}
    int length = strlen(argv[1]);
    if (length != 8) {
        printUsage(argv[0]);
        return EXIT_SUCCESS;
    }
	bool signedInput = false;
	char * input = "unsigned";
	if (argc == 3) {
		signedInput = strcmp(argv[2], "signed") == 0;
		input = "signed";
	}
	int value = 0;
	if (signedInput) {
		value = signedToInt(argv[1]);
	} else {
		value = unsignedToInt(argv[1]);
	}
	printf("\nBits %s as %s 8 bit int is: %d\n", argv[1], input, value);
	return EXIT_SUCCESS;
}

int signedToInt(const char * bits) {
	int multiplier = -128;
	int value = 0;
	for (int index = 0; index < 8; index++) {
		if (bits[index] == '1') {
			value += multiplier;
		}
		printf("  bit: %c multiplier: %d value: %d\n", bits[index], multiplier, value);
		if (multiplier == -128) {
			multiplier = 64;
		} else {
			multiplier = multiplier >> 1;
		}
	}
	return value;
}

int unsignedToInt(const char * bits) {
	int multiplier = 128;
	int value = 0;
	for (int index = 0; index < 8; index++) {
		if (bits[index] == '1') {
			value += multiplier;
		}
		printf("  bit: %c multiplier: %d value: %d\n", bits[index], multiplier, value);
		multiplier = multiplier >> 1;
	}
	return value;
}


void printUsage(const char * binaryName) {
	printf("Usage: %s 11001010 [signed|unsigned]\n", binaryName);
	printf("  Show the 8 bit binary number either as signed or unsigned integer.\n");
	printf("  Example run: %s 11001010 signed\n", binaryName);
}
