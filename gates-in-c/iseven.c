#include "iseven.h"
#include "nand.h"

/// This chip checks if the least significant bit on the right side
/// is zero -- then the number is even.
bool isEven(bool array[]) {
	return nand(array[7], array[7]);
}
