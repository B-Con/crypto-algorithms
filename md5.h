/*********************************************************************
* Filename:   md5.h
* Author:     Brad Conte (brad AT bradconte.com)
* Copyright:
* Disclaimer: This code is presented "as is" without any guarantees.
* Details:    Defines the API for the corresponding MD5 implementation.
*********************************************************************/

#ifndef MD5_H
#define MD5_H

/*************************** HEADER FILES ***************************/
#include <stddef.h>
#include <stdint.h>

/****************************** MACROS ******************************/
#define MD5_BLOCK_SIZE 16               // MD5 outputs a 16 byte digest

/**************************** DATA TYPES ****************************/
#if !defined(CRYPTO_TYPES)
typedef uint8_t BYTE;            // 8-bit byte
typedef uint32_t WORD;           // 32-bit word, change to "long" for 16-bit machines
#define CRYPTO_TYPES
#endif

typedef struct {
   BYTE data[64];
   WORD datalen;
   unsigned long long bitlen;
   WORD state[4];
} MD5_CTX;

/*********************** FUNCTION DECLARATIONS **********************/
void md5_init(MD5_CTX *ctx);
void md5_update(MD5_CTX *ctx, const BYTE data[], size_t len);
void md5_final(MD5_CTX *ctx, BYTE hash[]);
void md5(BYTE hash[], BYTE data[], size_t len);

#endif   // MD5_H
