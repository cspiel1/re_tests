#
# Makefile
#
# Copyright (C) 2011 Creytiv.com
#


all: retest2.o
	gcc retest2.o -l re -o retest2

retest2.o: retest2.c
	gcc -c -I/usr/local/include/re -L/usr/local/lib retest2.c

clean:
	@rm retest2.o
	@rm retest2
