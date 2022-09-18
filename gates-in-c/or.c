#include "or.h"
#include "nand.h"

/// Implements the OR gate using three NAND gates.
bool or(bool x, bool y) {
	/* Visualization:
	 x --> nand1(x,x) --\
                        nand3(nand1, nand2) --->
	 y --> nand2(y,y) --/
	 */
	return nand(nand(x, x), nand(y, y));
	//      ^nand3 ˆnand1      ^nand2
}


