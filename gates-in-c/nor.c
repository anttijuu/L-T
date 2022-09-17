#include "nor.h"
#include "or.h"
#include "not.h"

/// Implements NOR gate using OR and NOT.
bool nor(bool x, bool y) {
	return not(or(x,y));
}

