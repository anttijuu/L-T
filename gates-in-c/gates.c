#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

// Include all the gates / chips
#include "and.h"
#include "not.h"
#include "nand.h"
#include "or.h"
#include "nor.h"
#include "xor.h"
#include "iseven.h"
#include "iszero.h"
#include "unsigned_gt_zero_even_chip.h"
#include "signed_gt_zero_even_chip.h"

/// Enumerate different basic logical operations.
typedef enum operationType {
	AND,
	NOT,
	NAND,
	OR,
	NOR,
	XOR
} Operation;

/// Input and output.
/// Print truth tables for basic operators having two inputs.
void printTruthTable(Operation op);
void printBooleanArrayAsBits(bool byte[]);
void printBooleanArrayAs8BitUnsignedInt(bool byte[]);
void printBooleanArrayAs8BitSignedInt(bool byte[]);

/// main function demonstrates the logical operators and "chips" implemented
/// using the logical operators, following the course exercise 3.
int main() {
	printf("Printing out truth tables for operators...\n");
	printTruthTable(AND);
	printTruthTable(NOT);
	printTruthTable(NAND);
	printTruthTable(OR);
	printTruthTable(NOR);
	printTruthTable(XOR);

	printf("\n---------------------------------------------\n");

	// Eight bit arrays as truth values.
	bool zeroByte[] =    {false, false, false, false, false, false, false, false}; // 00000000, 0x00, 0
	bool nonZeroByte[] = {false, true, false,  false, false, false, false, true};  // 01000001, 0x41, 65
	bool dec234[] = {true, true, true,  false, true, false, true, false};  // 11101010, 0xEA, 234

	// Printing out some numbers
	printf("\nPrinting out number 234...\n");
	printf("First print the bits             : ");
	printBooleanArrayAsBits(dec234);
	printf("Then print the SIGNED int value  : ");
	printBooleanArrayAs8BitSignedInt(dec234);
	printf("\nVerify that this works ...\n");
	int8_t verifySigned = 0b11101010; // Same bin value as above
	printf("Should be same value as above    : %d\n", verifySigned);
	printf("Then print the UNSIGNED int value: ");
	printBooleanArrayAs8BitUnsignedInt(dec234);
	uint8_t verifyUnsigned = 0b11101010; // Same bin value as above
	printf("\nShould be same value as above    : %d", verifyUnsigned);

	// Testing isZero chip.
	printf("\n\nTesting isZero chip...\n");
	printBooleanArrayAsBits(zeroByte);
	printf("Is the byte above a zero integer?: %s\n\n", isZero(zeroByte) ? "Yes" : "No");
	printBooleanArrayAsBits(nonZeroByte);
	printf("Is the byte above a zero integer?: %s\n\n", isZero(nonZeroByte) ? "Yes" : "No");

	printf("\n---------------------------------------------\n");

	// Testing isEven chip.
	printf("\nTesting isEven chip...\n");
	printBooleanArrayAsBits(zeroByte);
	zeroByte[3] = true;
	// Now zeroByte is temporarily 0b00010000 and still even integer.
	printf("\nTesting isEven chip...\n");
	printBooleanArrayAsBits(zeroByte);
	zeroByte[3] = false;
	// Now zeroByte is back to zero 0b00000000
	printf("Is the byte an even integer?: %s\n\n", isEven(zeroByte) ? "Yes" : "No");
	printBooleanArrayAsBits(nonZeroByte);
	printf("Is the byte above an even integer?: %s\n\n", isEven(nonZeroByte) ? "Yes" : "No");

	printf("\n---------------------------------------------\n");

	// The final exercise chip has two solutions, depending if you interpret the byte to
	// be unsigned or signed. Let's start with unsigned chip...
	printf("Considering a byte as UNSIGNED now...\n");
	printf("\nTesting if a byte is larger than zero int and even or not...\n");
	printBooleanArrayAsBits(zeroByte);
	printf("Is the byte above larger than 0 and even?: %s\n\n", isUnsignedByteLargerThanZeroAndEven(zeroByte) ? "Yes" : "No");
	printBooleanArrayAsBits(nonZeroByte);
	printf("Is the byte above larger than 0 and even?: %s\n\n", isUnsignedByteLargerThanZeroAndEven(nonZeroByte) ? "Yes" : "No");
	nonZeroByte[0] = true;
	nonZeroByte[7] = false;
	// Now bits in nonZeroByte are: 11000000
	printBooleanArrayAsBits(nonZeroByte);
	printf("Is the byte above larger than 0 and even?: %s\n\n", isUnsignedByteLargerThanZeroAndEven(nonZeroByte) ? "Yes" : "No");

	printf("\n---------------------------------------------\n");

	// The final exercise chip has two solutions, depending if you interpret the byte to
	// be unsigned or signed. Here we test the signed chip...
	printf("\nConsidering a byte as SIGNED now...\n");
	printf("\nTesting if a byte is larger than zero int and even or not...\n");
	printBooleanArrayAsBits(zeroByte);
	printf("Is the byte above larger than 0 and even?: %s\n\n", isSignedByteLargerThanZeroAndEven(zeroByte) ? "Yes" : "No");
	nonZeroByte[7] = true;
	// Now bits in nonZeroByte are: 11000001
	printBooleanArrayAsBits(nonZeroByte);
	printf("Is the byte above larger than 0 and even?: %s\n\n", isSignedByteLargerThanZeroAndEven(nonZeroByte) ? "Yes" : "No");
	nonZeroByte[7] = false;
	// Now bits in nonZeroByte are: 11000000
	printBooleanArrayAsBits(nonZeroByte);
	printf("Is the byte above larger than 0 and even?: %s\n\n", isSignedByteLargerThanZeroAndEven(nonZeroByte) ? "Yes" : "No");
	nonZeroByte[0] = false;
	// Now bits in nonZeroByte are: 01000000
	printBooleanArrayAsBits(nonZeroByte);
	printf("Is the byte above larger than 0 and even?: %s\n\n", isSignedByteLargerThanZeroAndEven(nonZeroByte) ? "Yes" : "No");
}

// ==================//
// Output functions. //
// ==================//

/// Prints out a truth table for a specific Boolean operation.
void printTruthTable(Operation op) {
	// Implementation uses a function pointer to select the
	// function to call, based on the parameter value.
	bool (*funcPtr)(bool, bool) = NULL;
	switch (op) {
		case AND:
			printf("Truth table for AND:\n");
			funcPtr = &and;
			break;
		case NOT:
			// Leave the function pointer to NULL,
			// easier to handle one parameter NOT
			// function here than below where 2 params
			// are required.
			printf("Truth table for NOT:\n");
			printf("\tx\t?\n");
			printf("\t------------\n");
			printf("\t0\t%d\n", not(false) ? 1 : 0);
			printf("\t1\t%d\n", not(true) ? 1 : 0);
			break;
		case NAND:
			printf("Truth table for NAND:\n");
			funcPtr = &nand;
			break;
		case OR:
			printf("Truth table for OR:\n");
			funcPtr = &or;
			break;
		case NOR:
			printf("Truth table for NOR:\n");
			funcPtr = &nor;
			break;
		case XOR:
			printf("Truth table for XOR:\n");
			funcPtr = &xor;
			break;
		default:
			break;
	}
	// Did we manage to select a function to call (NOT handled above)?
	if (funcPtr != NULL) {
		printf("\tx\ty\t?\n");
		printf("\t--------------------\n");
		printf("\t0\t0\t%d\n", (*funcPtr)(false, false) ? 1 : 0);
		printf("\t1\t0\t%d\n", (*funcPtr)(true, false) ? 1 : 0);
		printf("\t0\t1\t%d\n", (*funcPtr)(false, true) ? 1 : 0);
		printf("\t1\t1\t%d\n", (*funcPtr)(true, true) ? 1 : 0);
	} else {
		printf("ERROR, Boolean operator not supported\n");
	}
}

/// Prints a boolean array of size 8 as bits.
/// - Parameter array: An array with 8 boolean values.
void printBooleanArrayAsBits(bool byte[]) {
	for (int i = 0; i < 8; i++) {
		printf("%d", byte[i] ? 1 : 0);
	}
	printf("\n");
}

void printBooleanArrayAs8BitUnsignedInt(bool byte[]) {
	uint8_t value = 0;
	for (int bitIndex = 0, bitValue = 128; bitIndex < 8; bitIndex++, bitValue = bitValue >> 1) {
		// printf("-- value: %ud bitValue: %d\n", value, bitValue);
		value += byte[bitIndex] ? bitValue : 0;
	}
	printf("%d", value);
}

void printBooleanArrayAs8BitSignedInt(bool byte[]) {
	int8_t value = 0;
	for (int bitIndex = 0, bitValue = 128; bitIndex < 8; bitIndex++, bitValue = bitValue >> 1) {
		// printf("-- value: %ud bitValue: %d\n", value, bitValue);
		value += byte[bitIndex] ? bitValue : 0;
	}
	printf("%d", value);
}
