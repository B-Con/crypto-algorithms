/*********************************************************************
* Filename:   rot-13.h
* Author:     Brad Conte (brad AT bradconte.com)
* Copyright:
* Disclaimer: This code is presented "as is" without any guarantees.
* Details:    Defines the API for the corresponding ROT-13 implementation.
*********************************************************************/

#ifndef ROT13_H
#define ROT13_H

/*************************** HEADER FILES ***************************/
#include <stddef.h>
#include <stdint.h>

/**************************** DATA TYPES ****************************/
#if !defined(CRYPTO_TYPES)
typedef uint8_t BYTE;            // 8-bit byte
#define CRYPTO_TYPES
#endif

/*********************** FUNCTION DECLARATIONS **********************/
// Performs IN PLACE rotation of the input. Assumes input is NULL terminated.
// Preserves each charcter's case. Ignores non alphabetic characters.
void rot13(BYTE *buf, size_t len);

#endif   // ROT13_H
