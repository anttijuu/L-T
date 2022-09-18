//
//  signed_gt_zero_even_chip.c
//  
//
//  Created by Antti Juustila on 18.9.2022.
//

#include "unsigned_gt_zero_even_chip.h"
#include "and.h"
#include "not.h"
#include "iszero.h"
#include "iseven.h"

/// This chip checks if an UNSIGNED byte is larger than zero and even integer.
/// In unsigned bytes, the most significant bit value of 1 does *not* mean number is negative.
bool isUnsignedByteLargerThanZeroAndEven(bool byte[]) {
	// If the byte is NOT zero AND is even, return true.
	return and(not(isZero(byte)), isEven(byte));
}
