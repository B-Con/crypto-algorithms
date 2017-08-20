/*********************************************************************
* Filename:   rot-13_test.c
* Author:     Brad Conte (brad AT bradconte.com)
* Copyright:
* Disclaimer: This code is presented "as is" without any guarantees.
* Details:    Performs known-answer tests on the corresponding ROT-13
	          implementation. These tests do not encompass the full
	          range of available test vectors, however, if the tests
	          pass it is very, very likely that the code is correct
	          and was compiled properly. This code also serves as
	          example usage of the functions.
*********************************************************************/

/*************************** HEADER FILES ***************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rot-13.h"

/*********************** FUNCTION DEFINITIONS ***********************/
int rot13_test()
{
	char text[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
	char code[] = {"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm"};
	char buf[1024];
	int pass = 1;
	size_t len;

	// To encode, just apply ROT-13.
	memset(buf, 0, sizeof(buf));
	len = sizeof(text);
	memcpy(buf, text, len);
	rot13((BYTE *)buf, len);
	pass = pass && (memcmp(code, buf, len) == 0);

	// To decode, just re-apply ROT-13.
	rot13((BYTE *)buf, len);
	pass = pass && (memcmp(text, buf, len) == 0);

	return(pass);
}

int main()
{
	int ret;	// 0 ==> test failed, != 0 ==> test suceeded

	ret = rot13_test();
	printf("ROT-13 Tests: %s\n", ret ? "SUCCEEDED" : "FAILED");

	exit(ret == 0 ? 1 : 0);
}
