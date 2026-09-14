#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>

void printUsage(const char * binaryName);
void signedToOutput(const char * hexString);
void unsignedToOutput(const char * hexString);
int valueFromHexChar(char hex);
unsigned char * getBits(size_t const size, void const * const ptr);
void printBits(unsigned char * bytes);

int main(int argc, char * argv[]) {
    if (argc != 2 && argc != 3) {
		printUsage(argv[0]);
		return EXIT_SUCCESS;
	}
    int length = strlen(argv[1]);
    if (length != 6) {
        printUsage(argv[0]);
        return EXIT_SUCCESS;
    }

    char input[5] = {0};
    char * firstHexChar = argv[1];
    firstHexChar++;
    firstHexChar++;
    strncpy(input, firstHexChar, 4);

    bool signedInput = false;
    char * output = "unsigned";
    if (argc == 3) {
        signedInput = strcmp(argv[2], "signed") == 0;
        output = "signed";
    }
    if (signedInput) {
        printf(" --- Treating input as signed\n");
        signedToOutput(input);
    } else {
        printf(" --- Treating input as unsigned\n");
        unsignedToOutput(input);
    }
	return EXIT_SUCCESS;
}

void signedToOutput(const char * hexString) {
    size_t toPow = strlen(hexString) - 1;
    int value = 0;
    bool isNegative = false;
    for (int index = 0; index < strlen(hexString); index++) {
        int hexAsInt = valueFromHexChar(hexString[index]);
        if (index == 0 && hexAsInt > 9) {
            isNegative = true;
        }
        int multiplier = (int)pow(16, toPow);
        printf("hexAsInt * multiplier: %d * %d = %d\n", hexAsInt, multiplier, hexAsInt * multiplier);
        value += hexAsInt * multiplier;
        printf("  hex: %c hexAsInt: %d multiplier: %d value: %d\n", hexString[index], hexAsInt, multiplier, value);
        toPow--;
    }
    int16_t finalValue = value;
    printf(" !! Assigned int %d to int16_t, overflowing to int16_t value: %d\n", value, finalValue);
    
    printf(" >>>> Hex value 0x%s", hexString);
    printf(" as bits: ");
    unsigned char * bytes = getBits(sizeof(int16_t), &finalValue);
    printBits(bytes);
    printf("as unsigned int is: %d\n", finalValue);
}

void unsignedToOutput(const char * hexString) {
    int toPow = strlen(hexString) - 1;
    uint16_t value = 0;
	for (int index = 0; index < strlen(hexString); index++) {
        int hexAsInt = valueFromHexChar(hexString[index]);
        int multiplier = (int)pow(16, toPow);
        value += hexAsInt * multiplier;
		printf("  hex: %c multiplier: %d value: %d\n", hexString[index], multiplier, value);
        toPow--;
	}
    printf(" >>>> Hex value 0x%s", hexString);
    printf(" as bits: ");
    unsigned char * bytes = getBits(sizeof(uint16_t), &value);
    printBits(bytes);
    printf("as unsigned int is: %d\n", value);
}

unsigned char * getBits(size_t const size, void const * const ptr) {
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    unsigned char * bytes = calloc(sizeof(unsigned char), 16);
    int bytesIndex = 0;
    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            bytes[bytesIndex] = byte;
            bytesIndex++;
        }
    }
    return bytes;
}

void printBits(unsigned char * bytes) {
    int j = 1;
    unsigned char byte;
    for (int index = 0; index < 16; index++) {
        printf("%u", bytes[index]);
        if (j % 4 == 0) {
            printf(" ");
            j = 1;
        } else {
            j++;
        }
    }
}


int valueFromHexChar(char hex) {
    hex = tolower(hex);
    if (isnumber(hex)) {
        return hex - '0';
    }
    switch (hex) {
        case 'a':
            return 10;
        case 'b':
            return 11;
        case 'c':
            return 12;
        case 'd':
            return 13;
        case 'e':
            return 14;
        case 'f':
            return 15;
        default:
            assert(false);
    }
}


void printUsage(const char * binaryName) {
	printf("\nUsage: %s <16 bit hex value> [signed|unsigned] [\n", binaryName);
	printf("  Show the 16 bit hexadecimal number as bits and int value.\n");
	printf("  Example run: %s 0xF0FF signed\n", binaryName);
    printf("  Will print: \n    0xF0FF as bits: 1111 0000 1111 1111 as signed int: -3841.\n");
    printf("  Example run: %s 0xF0FF unsigned\n", binaryName);
    printf("  Will print: \n    0xF0FF as bits: 1111 0000 1111 1111 as unsigned int: 61 695.\n\n");
}
