#
# Makefile
#
# Copyright (C) 2011 Creytiv.com
#


all: retest1.o
	gcc retest1.o -l re -o retest1

retest1.o: retest1.c
	gcc -c -I/usr/local/include/re -L/usr/local/lib retest1.c

clean:
	@rm retest1.o
	@rm retest1
