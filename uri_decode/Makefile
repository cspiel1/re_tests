#
# Makefile
#
# Copyright (C) 2018 commend.com
#


all: retest3.o
	gcc retest3.o -l re -o retest3

retest3.o: retest3.c
	gcc -c -I/usr/local/include/re -L/usr/local/lib retest3.c

clean:
	@rm retest3.o
	@rm retest3
