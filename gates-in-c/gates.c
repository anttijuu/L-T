/**
 Tämä tiedosto toteuttaa Laitteet ja tietoverkot -kurssin Harjoituksen 3 portit C -kielellä.
 Toteutus noudattaa malliratkaisua josta löytyy demovideo.

 This file implements the Devices and data networks course Exercise 3 gates in C language.
 The implementation follows the sample solution video demonstration.

 Compile on *nix machines:
 > gcc gates.c -o gates

 Compile on Windows:
 > gcc gates.c -o gates.exe
 */

#include <stdio.h>
#include <stdbool.h>

/// Enumerate different basic logical operations.
typedef enum operationType {
	AND,
	NOT,
	NAND,
	OR,
	NOR,
	XOR
} Operation;

/// Forward declarations for operators and other functions needed.
/// The two gates available in Digital Logic Sim when you create a new project:
bool and(bool x, bool y);
bool not(bool x);
/// The first port to create, NAND:
bool nand(bool x, bool y);
/// OR port created by using three NAND gates:
bool or(bool x, bool y);
/// NOR port created using OR and NOT:
bool nor(bool x, bool y);
/// XOR gate created using four NAND gates:
bool xor(bool x, bool y);

/// Gate or chip checking if a byte is zero integer or not.
bool isZero(bool array[]);
/// Gate or chip checking if a byte is even integer or not.
bool isEven(bool array[]);
/// Final task in the exercise is to check if a byte is larger than
/// zero and even. This has two solutions, depending if you consider
/// the byte to be signed or unsigned. This first is for unsigned bytes.
bool isUnsignedByteLargerThanZeroAndEven(bool array[]);
/// The second solution where byte is considered to be signed.
bool isSignedByteLargerThanZeroAndEven(bool array[]);

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

/// Returns true if both inputs are true, as AND gate does.
bool and(bool x, bool y) {
	return x && y;
}

/// Returns the x reversed, the job of the NOT gate.
bool not(bool x) {
	return !x;
}

/// Implements the NAND gate using AND and NOT.
bool nand(bool x, bool y) {
	return not(and(x, y));
}

/// Implements the OR gate using three NAND gates.
bool or(bool x, bool y) {
	/* Visualization:
	 x 		nand1(x,x)
							nand3(nand1, nand2)
	 y 		nand2(y,y)
	 */
	return nand(nand(x, x), nand(y, y));
	//      ^nand3 ˆnand1      ^nand2
}

/// Implements NOR gate using OR and NOT.
bool nor(bool x, bool y) {
	return not(or(x,y));
}

/// Implements the XOR using four NAND gates.
bool xor(bool x, bool y) {
	/* Visualization:
	x					nand2(x,nand1)
		nand1(x,y)						nand4(nand2, nand3)
	y 					nand3(y,nand1)
	 */
	return nand(nand(x, nand(x, y)), nand(y, nand(x,y)));
	//     ^nand4 ˆnand2   ^nand1       ^nand3    ^nand1
}

/// Implements isZero chip by OR'ing each input, combining
/// each to another OR and finally using NOT. Since without
/// NOT, this chip would say if the byte is not zero and we
/// want the opposite.
bool isZero(bool array[]) {
	// This layout for the code may help in seeing the structure better.
	return not(or(									// OR the result of OR'ing the two nibbles, done below.
					  or(								// OR the result of two OR's below, the left side nibble.
						  or(
							  array[0], array[1] // OR first two bits
							  ),
						  or(
							  array[2], array[3] // OR 3rd and 4th bits from the left
							  )
						  ),
					  or(								// OR the result of two OR's below, right side nibble.
						  or(
							  array[4], array[5] // OR 5th and 6th bits from the left
							  ),
						  or(
							  array[6], array[7] // OR 7th and 8th bits from the left
							  )
						  )
					  )
				  );
}

/// This chip checks if the least significant bit on the right side
/// is zero -- then the number is even.
bool isEven(bool array[]) {
	return nand(array[7], array[7]);
}

/// This chip checks if an UNSIGNED byte is larger than zero and even integer.
/// In unsigned bytes, the most significant bit value of 1 does *not* mean number is negative.
bool isUnsignedByteLargerThanZeroAndEven(bool array[]) {
	return and(not(isZero(array)), isEven(array));
}

/// This chip checks if a SIGNED byte is larger than zero and even integer.
/// In a signed byte, the most significant bit (on the left) is 1 if the number is negative,
/// and zero if the number is positive. We use NAND to check the most significant bit.
/// In the demo video showing the solution, I used AND and NOT gates, but NAND can be used
/// to replace those as you can see in the code below.
bool isSignedByteLargerThanZeroAndEven(bool array[]) {
	return and(nand(array[0], array[0]), and(not(isZero(array)), isEven(array)));
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
