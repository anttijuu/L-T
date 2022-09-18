#include <stdio.h>
#include <stdbool.h>

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
void printBooleanArrayAsBits(bool array[]);

/// main function demonstrates the logical operators and "chips" implemented
/// using the logical operators, following the course exercise 3.
int main() {
	printf("Printing out truth tables for operators...\n");
	printTruthTable(AND);
	printTruthTable(NAND);
	printTruthTable(OR);
	printTruthTable(NOR);
	printTruthTable(XOR);

	printf("\n---------------------------------------------\n");

	// Eight bit arrays as truth values.
	bool zeroArray[] =    {false, false, false, false, false, false, false, false}; // 00000000, 0x00, 0
	bool nonZeroArray[] = {false, true, false,  false, false, false, false, true};  // 01000001, 0x41, 65

	// Testing isZero chip.
	printf("\nTesting isZero chip...\n");
	printBooleanArrayAsBits(zeroArray);
	printf("Is the byte above a zero integer?: %s\n\n", isZero(zeroArray) ? "Yes" : "No");
	printBooleanArrayAsBits(nonZeroArray);
	printf("Is the byte above a zero integer?: %s\n\n", isZero(nonZeroArray) ? "Yes" : "No");

	printf("\n---------------------------------------------\n");

	// Testing isEven chip.
	printf("\nTesting isEven chip...\n");
	printBooleanArrayAsBits(zeroArray);
	printf("Is the byte an even integer?: %s\n\n", isEven(zeroArray) ? "Yes" : "No");
	printBooleanArrayAsBits(nonZeroArray);
	printf("Is the byte above an even integer?: %s\n\n", isEven(nonZeroArray) ? "Yes" : "No");

	printf("\n---------------------------------------------\n");

	// The final exercise chip has two solutions, depending if you interpret the byte to
	// be unsigned or signed. Let's start with unsigned chip...
	printf("Considering a byte as UNSIGNED now...\n");
	printf("\nTesting if a byte is larger than zero int and even or not...\n");
	printBooleanArrayAsBits(zeroArray);
	printf("Is the byte above larger than 0 and even?: %s\n\n", isUnsignedByteLargerThanZeroAndEven(zeroArray) ? "Yes" : "No");
	printBooleanArrayAsBits(nonZeroArray);
	printf("Is the byte above larger than 0 and even?: %s\n\n", isUnsignedByteLargerThanZeroAndEven(nonZeroArray) ? "Yes" : "No");
	nonZeroArray[0] = true;
	nonZeroArray[7] = false;
	// Now bits in nonZeroArray are: 11000000
	printBooleanArrayAsBits(nonZeroArray);
	printf("Is the byte above larger than 0 and even?: %s\n\n", isUnsignedByteLargerThanZeroAndEven(nonZeroArray) ? "Yes" : "No");

	printf("\n---------------------------------------------\n");

	// The final exercise chip has two solutions, depending if you interpret the byte to
	// be unsigned or signed. Here we test the signed chip...
	printf("\nConsidering a byte as SIGNED now...\n");
	printf("\nTesting if a byte is larger than zero int and even or not...\n");
	printBooleanArrayAsBits(zeroArray);
	printf("Is the byte above larger than 0 and even?: %s\n\n", isSignedByteLargerThanZeroAndEven(zeroArray) ? "Yes" : "No");
	nonZeroArray[7] = true;
	// Now bits in nonZeroArray are: 11000001
	printBooleanArrayAsBits(nonZeroArray);
	printf("Is the byte above larger than 0 and even?: %s\n\n", isSignedByteLargerThanZeroAndEven(nonZeroArray) ? "Yes" : "No");
	nonZeroArray[7] = false;
	// Now bits in nonZeroArray are: 11000000
	printBooleanArrayAsBits(nonZeroArray);
	printf("Is the byte above larger than 0 and even?: %s\n\n", isSignedByteLargerThanZeroAndEven(nonZeroArray) ? "Yes" : "No");
	nonZeroArray[0] = false;
	// Now bits in nonZeroArray are: 01000000
	printBooleanArrayAsBits(nonZeroArray);
	printf("Is the byte above larger than 0 and even?: %s\n\n", isSignedByteLargerThanZeroAndEven(nonZeroArray) ? "Yes" : "No");
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
			printf("Truth table for AND\n");
			funcPtr = &and;
			break;
		case NAND:
			printf("Truth table for NAND\n");
			funcPtr = &nand;
			break;
		case OR:
			printf("Truth table for OR\n");
			funcPtr = &or;
			break;
		case NOR:
			printf("Truth table for NOR\n");
			funcPtr = &nor;
			break;
		case XOR:
			printf("Truth table for XOR\n");
			funcPtr = &xor;
			break;
		default:
			break;
	}
	// Did we manage to select a function to call?
	if (funcPtr != NULL) {
		printf("\tx\ty\t?\n");
		printf("\t--------------------\n");
		printf("\t0\t0\t%d\n", (*funcPtr)(false, false) ? 1 : 0);
		printf("\t1\t0\t%d\n", (*funcPtr)(true, false) ? 1 : 0);
		printf("\t0\t1\t%d\n", (*funcPtr)(false, true) ? 1 : 0);
		printf("\t1\t1\t%d\n", (*funcPtr)(true, true) ? 1 : 0);
	} else {
		printf("ERROR, operator not supported\n");
	}
}

/// Prints a boolean array of size 8 as bits.
/// - Parameter array: An array with 8 boolean values.
void printBooleanArrayAsBits(bool array[]) {
	for (int i = 0; i < 8; i++) {
		printf("%d", array[i] ? 1 : 0);
	}
	printf("\n");
}
