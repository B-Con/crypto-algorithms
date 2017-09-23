/*********************************************************************
* Filename:   speck128128.h
* Author:     Landon Curt Noll (http://www.isthe.com/chongo/address.html)
* Copyright:  This code is in the public domain.
* Disclaimer: This code is presented "as is" without any guarantees.
* 	NOTE: The author does NOT endorse this algorithm.
* Details:    Implementation of the Speck128/128 encryption algorithm with key expansion.
*		https://eprint.iacr.org/2013/404.pdf
*********************************************************************/

#ifndef SPECK128128_H
#define SPECK128128_H

/*************************** HEADER FILES ***************************/
#include <stdint.h>

/****************************** MACROS ******************************/
#define SPECK128128_BLOCK_SIZE 16               // Speck128/128 operates on 16 bytes at a time

/**************************** DATA TYPES ****************************/

/*********************** FUNCTION DECLARATIONS **********************/
// Encryplain_texts
void speck128128(uint64_t const plain_text[static 2], uint64_t cipher_text[static 2], uint64_t const key[static 2]);

#endif   // SPECK128128_H
