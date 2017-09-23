#!/bin/make
# @(#)Makefile	1.2 04 May 1995 02:06:57
#
# crypto-algorithms-master - Brad Conte's basic implementations of standard cryptography algorithms
#
# @(#) $Revision$
# @(#) $Id$
# @(#) $Source$
#
# chongo (Landon Curt Noll, http://www.isthe.com/chongo/index.html) /\oo/\
#
# Share and enjoy! :-)

SHELL= /bin/bash
CC= cc
CFLAGS= -O3 -g3 -std=c99 -Wall -pedantic

INSTALL= install
DESTDIR= /usr/global/bin

TEST_TARGETS= aes_test arcfour_test base64_test blowfish_test des_test md2_test md5_test rot-13_test sha1_test sha256_test \
	speck128128_test
TARGETS= ${TEST_TARGETS}

all: ${TARGETS}

aes_test: aes_test.o aes.o
	${CC} ${CFLAGS} aes_test.o aes.o -o aes_test

aes.o: aes.c aes.h
	${CC} ${CFLAGS} aes.c -c

aes_test.o: aes_test.c aes.h
	${CC} ${CFLAGS} aes_test.c -c

arcfour_test: arcfour_test.o arcfour.o
	${CC} ${CFLAGS} arcfour_test.o arcfour.o -o arcfour_test

arcfour.o: arcfour.c arcfour.h
	${CC} ${CFLAGS} arcfour.c -c

arcfour_test.o: arcfour_test.c arcfour.h
	${CC} ${CFLAGS} arcfour_test.c -c

base64_test: base64_test.o base64.o
	${CC} ${CFLAGS} base64_test.o base64.o -o base64_test

base64.o: base64.c base64.h
	${CC} ${CFLAGS} base64.c -c

base64_test.o: base64_test.c base64.h
	${CC} ${CFLAGS} base64_test.c -c

blowfish_test: blowfish_test.o blowfish.o
	${CC} ${CFLAGS} blowfish_test.o blowfish.o -o blowfish_test

blowfish.o: blowfish.c blowfish.h
	${CC} ${CFLAGS} blowfish.c -c

blowfish_test.o: blowfish_test.c blowfish.h
	${CC} ${CFLAGS} blowfish_test.c -c

des_test: des_test.o des.o
	${CC} ${CFLAGS} des_test.o des.o -o des_test

des.o: des.c des.h
	${CC} ${CFLAGS} des.c -c

des_test.o: des_test.c des.h
	${CC} ${CFLAGS} des_test.c -c

md2_test: md2_test.o md2.o
	${CC} ${CFLAGS} md2_test.o md2.o -o md2_test

md2.o: md2.c md2.h
	${CC} ${CFLAGS} md2.c -c

md2_test.o: md2_test.c md2.h
	${CC} ${CFLAGS} md2_test.c -c

md5_test: md5_test.o md5.o
	${CC} ${CFLAGS} md5_test.o md5.o -o md5_test

md5.o: md5.c md5.h
	${CC} ${CFLAGS} md5.c -c

md5_test.o: md5_test.c md5.h
	${CC} ${CFLAGS} md5_test.c -c

rot-13_test: rot-13_test.o rot-13.o
	${CC} ${CFLAGS} rot-13_test.o rot-13.o -o rot-13_test

rot-13.o: rot-13.c rot-13.h
	${CC} ${CFLAGS} rot-13.c -c

rot-13_test.o: rot-13_test.c rot-13.h
	${CC} ${CFLAGS} rot-13_test.c -c

sha1_test: sha1_test.o sha1.o
	${CC} ${CFLAGS} sha1_test.o sha1.o -o sha1_test

sha1.o: sha1.c sha1.h
	${CC} ${CFLAGS} sha1.c -c

sha1_test.o: sha1_test.c sha1.h
	${CC} ${CFLAGS} sha1_test.c -c

sha256_test: sha256_test.o sha256.o
	${CC} ${CFLAGS} sha256_test.o sha256.o -o sha256_test

sha256.o: sha256.c sha256.h
	${CC} ${CFLAGS} sha256.c -c

sha256_test.o: sha256_test.c sha256.h
	${CC} ${CFLAGS} sha256_test.c -c

speck128128_test: speck128128_test.o speck128128.o
	${CC} ${CFLAGS} speck128128_test.o speck128128.o -o speck128128_test

speck128128_test.o: speck128128_test.c speck128128.h
	${CC} ${CFLAGS} speck128128_test.c -c

speck128128.o: speck128128.c speck128128.h
	${CC} ${CFLAGS} speck128128.c -c

test: ${TEST_TARGETS}
	@export last_error="0"; \
	  for i in ${TEST_TARGETS}; do \
	    echo running '=-=' $$i '=-='; \
	    ./$$i; \
	    status="$$?"; \
	    if [ "$$status" != 0 ]; then \
		echo "WARNING: test $$i failed!!"; \
		last_error="$$status"; \
	    fi; \
	done; \
	if [ "$$last_error" = 0 ]; then \
	    echo "=-=-= All tests PASSED =-=-="; \
	else \
	    echo "=-=-= Some tests FAILED =-=-="; \
	fi; \
	exit "$$last_error"

configure:
	@echo nothing to configure

clean quick_clean:
	rm -f *.o

clobber quick_clobber quick_distclean distclean:
	rm -f *.o
	rm -f ${TARGETS}

install: all
	@echo not configured to install, perhaps ${INSTALL} -m 0555 ${TARGETS} ${DESTDIR}

