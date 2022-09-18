#include "xor.h"
#include "nand.h"

/// Implements the XOR using four NAND gates.
bool xor(bool x, bool y) {
	/* Visualization:
	 x \----------> nand2(x,nand1)
       \        /                \
	     nand1(x,y)                nand4(nand2, nand3) --->
	    /         \               /
	 y /----------> nand3(y,nand1)
	 */
	return nand(nand(x, nand(x, y)), nand(y, nand(x,y)));
	//     ^nand4 ˆnand2   ^nand1       ^nand3    ^nand1
}
