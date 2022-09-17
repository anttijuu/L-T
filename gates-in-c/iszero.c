#include "iszero.h"
#include "not.h"
#include "or.h"

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
