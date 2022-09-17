#include "nand.h"
#include "and.h"
#include "not.h"

/// Implements the NAND gate using AND and NOT.
bool nand(bool x, bool y) {
	return not(and(x, y));
}
