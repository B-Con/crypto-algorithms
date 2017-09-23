/*********************************************************************
* Filename:   speck128128_test.c
* Author:     Landon Curt Noll (http://www.isthe.com/chongo/address.html)
* Copyright:  This code is in the public domain.
* Disclaimer: This code is presented "as is" without any guarantees.
* 	NOTE: The author does NOT endorse this algorithm.
* Details:    Implementation of the Speck128/128 encryption algorithm with key expansion.
*	      Algorithm specification can be found here: https://eprint.iacr.org/2013/404.pdf
*********************************************************************/

/*************************** HEADER FILES ***************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "speck128128.h"

#define TEST_WORDS (32)

/*********************** FUNCTION DEFINITIONS ***********************/
int speck128128_test()
{
	// j-random plain text
	uint64_t const plain_text[TEST_WORDS] = {
		0x0123456789abcdef, 0xfedcba9876543210,
		0x3900e49972035990, 0x86f910e0c3d54776,
		0xc2fdc49498df33e6, 0xcac5a085fc51660a,
		0x177be2883036a67a, 0x23a0fdca4012c545,
		0x46208f3a607126a3, 0x033abf878b08a2ec,
		0x3f31cc3a8c80e83d, 0x3e3073ccf36f9f7d,
		0x018c78ac65e8c984, 0x01d98df913ab7caf,
		0x7ad1cbb608e85105, 0x13dcca88d9ab8faf,
		0xc170a6c90a533183, 0x325b824c239f9bf4,
		0x65310d337798f928, 0x34532b7b8e8723ca,
		0xd66daaa2845c0fe1, 0xf8f5604a2f4732bc,
		0x90534a156ca95987, 0xcabb6639898557a1,
		0x982ca1424d8552ab, 0xbd1436bfa0b2f69a,
		0xfe8f58885aa69974, 0x49d2fdb66e1d7be4,
		0x7d4f406255f3eabb, 0xbfd15a0c7d83bfb6,
		0xc2275dad2ef776bc, 0x257b72a934d81856,
	};
	// 128-bit encryption key
	uint64_t const key[] = {
		0xfeedfacedeedbeef, 0x31415926cafef00d
	};
	// encrypted plain text
	uint64_t cipher_text[TEST_WORDS];
	// verified encrypted plain text
	uint64_t const cipher_answer[TEST_WORDS] = {
		0x7043bb38d771b03c, 0x46d49489a35a8e87,
		0x0bd7b3fabb9a53fc, 0xc7988bd7133b124e,
		0xd7c852854c26feb4, 0x03e3836a508cc5df,
		0xd061ddf3a04715ec, 0xc9aa3363dcdd0f16,
		0x11af02adaefb6950, 0x0ecf90075c1ffd49,
		0x86b2038ade43f4d9, 0x78cda3c8c9d5f76d,
		0x9e0acf5e651937c2, 0xe4dda6fd1d0c0813,
		0x7338e77207d61e6b, 0xe1302dc0ecb099f3,
		0xa76736ed596fc28f, 0x2e9afec560e3dfe6,
		0x68d36b466c350f29, 0xdeb9d921dd64f8b4,
		0xf43bcb1c95d9e777, 0x7a52326b6e8a83bd,
		0xf734cabbbddcb012, 0x4a4270ef09416b56,
		0x4344c3b64966c573, 0x14b192c6b77547ee,
		0xafe21b4289d7929b, 0x15b5c93eec7b7e55,
		0xc99398b54194a317, 0x103ca3f17f7841f1,
		0xd56c55b24a4505ca, 0xbb832226c8d0aebc,
	};
	int pass;	// 0 ==> cipher_text was wrong, 1 ==> cipher_text is OK
	int i;

	// encrypt test vector
	for (i=0; i < TEST_WORDS; i += 2) {
		speck128128(plain_text+i, cipher_text+i, key);
		// printf("0x%016lx, 0x%016lx,\n", cipher_text[i], cipher_text[i+1]);
	}

	//  test answer
	if (memcmp(cipher_text, cipher_answer, sizeof(cipher_answer)) == 0) {
		pass = 1;
	} else {
		pass = 0;
	}
	return(pass);
}

int main()
{
	int ret;	// 0 ==> test failed, != 0 ==> test suceeded

	ret = speck128128_test();
	printf("Speck128/128 Tests: %s\n", ret ? "SUCCEEDED" : "FAILED");

	exit(ret == 0 ? 1 : 0);
}
