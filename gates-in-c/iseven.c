#include "iseven.h"
#include "nor.h"

/// This chip checks if the least significant bit on the right side
/// is zero -- then the number is even.
bool isEven(bool array[]) {
	// Can use either nor or nand.
	return nor(array[7], array[7]);
}
