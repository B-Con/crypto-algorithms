/*********************************************************************
* Filename:   md2.h
* Author:     Brad Conte (brad AT bradconte.com)
* Copyright:
* Disclaimer: This code is presented "as is" without any guarantees.
* Details:    Defines the API for the corresponding MD2 implementation.
*********************************************************************/

#ifndef MD2_H
#define MD2_H

/*************************** HEADER FILES ***************************/
#include <stddef.h>
#include <stdint.h>

/****************************** MACROS ******************************/
#define MD2_BLOCK_SIZE 16

/**************************** DATA TYPES ****************************/
#if !defined(CRYPTO_TYPES)
typedef uint8_t BYTE;            // 8-bit byte
#define CRYPTO_TYPES
#endif

typedef struct {
   BYTE data[16];
   BYTE state[48];
   BYTE checksum[16];
   int len;
} MD2_CTX;

/*********************** FUNCTION DECLARATIONS **********************/
void md2_init(MD2_CTX *ctx);
void md2_update(MD2_CTX *ctx, const BYTE data[], size_t len);
void md2_final(MD2_CTX *ctx, BYTE hash[]);   // size of hash must be MD2_BLOCK_SIZE
void md2(BYTE hash[], BYTE data[], size_t len);

#endif   // MD2_H
