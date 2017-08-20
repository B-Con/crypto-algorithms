/*********************************************************************
* Filename:   blowfish_test.c
* Author:     Brad Conte (brad AT bradconte.com)
* Copyright:
* Disclaimer: This code is presented "as is" without any guarantees.
* Details:    Performs known-answer tests on the corresponding Base64
	          implementation. These tests do not encompass the full
	          range of available test vectors, however, if the tests
	          pass it is very, very likely that the code is correct
	          and was compiled properly. This code also serves as
	          example usage of the functions.
*********************************************************************/

/*************************** HEADER FILES ***************************/
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "base64.h"

/*********************** FUNCTION DEFINITIONS ***********************/
int base64_test()
{
	BYTE text[3][1024] = {{"fo"},
	                      {"foobar"},
	                      {"Man is distinguished, not only by his reason, but by this singular passion from other animals, which is a lust of the mind, that by a perseverance of delight in the continued and indefatigable generation of knowledge, exceeds the short vehemence of any carnal pleasure."}};
	BYTE code[3][1024] = {{"Zm8="},
	                      {"Zm9vYmFy"},
	                      {"TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlz\nIHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2Yg\ndGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGlu\ndWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRo\nZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4="}};
	BYTE buf[1024];
	size_t buf_len;
	int pass = 1;
	int idx;

	for (idx = 0; idx < 3; idx++) {
		memset(buf, 0, sizeof(buf));
		buf_len = base64_encode(text[idx], buf, strlen((const char *)text[idx]), 1);
		pass = pass && ((buf_len == strlen((const char *)code[idx])) &&
		                 (buf_len == base64_encode(text[idx], NULL, strlen((const char *)text[idx]), 1)));
		pass = pass && !strcmp((const char *)code[idx], (const char *)buf);

		memset(buf, 0, sizeof(buf));
		buf_len = base64_decode(code[idx], buf, strlen((const char *)code[idx]));
		pass = pass && ((buf_len == strlen((const char *)text[idx])) &&
		                (buf_len == base64_decode(code[idx], NULL, strlen((const char *)code[idx]))));
		pass = pass && !strcmp((const char *)text[idx], (const char *)buf);
	}

	return(pass);
}

int main()
{
	int ret;	// 0 ==> test failed, != 0 ==> test suceeded

	ret = base64_test();
	printf("Base64 Tests: %s\n", ret ? "SUCCEEDED" : "FAILED");

	exit(ret == 0 ? 1 : 0);
}
