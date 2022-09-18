#include "iseven.h"
#include "nor.h"

/// This chip checks if the least significant bit on the right side
/// is zero -- then the number is even.
bool isEven(bool byte[]) {
	// Can use either nor or nand.
	return nor(byte[7], byte[7]);
}
