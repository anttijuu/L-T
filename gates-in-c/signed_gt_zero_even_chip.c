//
//  signed_gt_zero_even_chip.c
//  
//
//  Created by Antti Juustila on 18.9.2022.
//

#include "signed_gt_zero_even_chip.h"
#include "and.h"
#include "nand.h"
#include "not.h"
#include "iszero.h"
#include "iseven.h"

/// This chip checks if a SIGNED byte is larger than zero and even integer.
/// In a signed byte, the most significant bit (msb, on the left) is 1 if the number is negative,
/// and zero if the number is positive. We use NAND to check the most significant bit.
/// In the demo video showing the solution, I used AND and NOT gates, but NAND can be used
/// to replace those as you can see in the code below.
bool isSignedByteLargerThanZeroAndEven(bool byte[]) {
	// If the byte is NOT zero AND it is even AND byte's msb is zero (number is not < 0), return true.
	return and(nand(byte[0], byte[0]), and(not(isZero(byte)), isEven(byte)));
}

