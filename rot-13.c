/*********************************************************************
* Filename:   rot-13.c
* Author:     Brad Conte (brad AT bradconte.com)
* Copyright:
* Disclaimer: This code is presented "as is" without any guarantees.
* Details:    Implementation of the ROT-13 encryption algorithm.
				  Algorithm specification can be found here:
				   *
				  This implementation uses little endian byte order.
*********************************************************************/

/*************************** HEADER FILES ***************************/
#include <string.h>
#include <ctype.h>
#include "rot-13.h"

/*********************** FUNCTION DEFINITIONS ***********************/
void rot13(BYTE *buf, size_t len)
{
    int idx;

    for (idx = 0; idx < len; idx++) {

	// Only process alphabetic characters
	if (isalpha(buf[idx])) {

	    // lower case rotation
	    if (islower(buf[idx])) {
		buf[idx] = (((buf[idx] - 'a') + 13) % 26) + 'a';
	    // UPPER case rotation
	    } else {
		buf[idx] = (((buf[idx] - 'A') + 13) % 26) + 'A';
	    }
	}
    }
}
