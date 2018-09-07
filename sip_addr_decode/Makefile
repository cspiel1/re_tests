#
# Makefile
#
# Copyright (C) 2018 commend.com
#


all: retest.o
	gcc retest.o -l re -o retest

retest.o: retest.c
	gcc -c -I/usr/local/include/re -L/usr/local/lib retest.c

clean:
	@rm retest.o
	@rm retest
