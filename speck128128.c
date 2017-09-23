/*********************************************************************
* Filename:   speck128128.c
* Author:     Landon Curt Noll (http://www.isthe.com/chongo/address.html)
* Copyright:  This code is in the public domain.
* Disclaimer: This code is presented "as is" without any guarantees.
* 	NOTE: The author does NOT endorse this algorithm.
* Details:    Implementation of the Speck128/128 encryption algorithm with key expansion.
*	      Algorithm specification can be found here: https://eprint.iacr.org/2013/404.pdf
*********************************************************************/

/*************************** HEADER FILES ***************************/
#include <stdint.h>
#include "speck128128.h"

#define ROR(x, r) (((x) >> (r)) | ((x) << (64 - (r))))
#define ROL(x, r) (((x) << (r)) | ((x) >> (64 - (r))))
#define R(x, y, k) ((x) = ROR((x), 8), (x) += (y), (x) ^= (k), (y) = ROL((y), 3), (y) ^= (x))
#define ROUNDS 32

/*********************** FUNCTION DEFINITIONS ***********************/
void
speck128128(uint64_t const plain_text[static 2], uint64_t cipher_text[static 2], uint64_t const key[static 2])
{
	uint64_t y;		// plaintext word 0
	uint64_t x;		// plaintext word 1
	uint64_t b;		// key word 0
	uint64_t a;		// key word 1
	int i;

	// load plain text
	y = plain_text[0];
	x = plain_text[1];

	// load key
	b = key[0];
	a = key[1];

	// pre-round
	R(x, y, b);

	// Speck rounds
	for (i=0; i < ROUNDS; ++i) {
		R(a, b, i);
		R(x, y, b);
	}

	// return cipher text
	cipher_text[0] = y;
	cipher_text[1] = x;
	return;
}
