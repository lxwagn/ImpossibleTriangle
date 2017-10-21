#******************************************************************
# *  File: Makefile                                               *
# *  Project: Impossible Triangle                                 *
# *  Author: Lucas Wagner                                         *
# *  Purpose: n/a                                                 *
# *  FOR DEMONSTRATION USE ONLY                                   *
# *  COPYRIGHT (c)2017, Lucas C. Wagner. All Rights Reserved.     *
# *****************************************************************

CC= gcc
CFLAGS= -g -Wall
INCLUDE= -I/usr/local/include -I../src
LIBS= -L/usr/local/lib -lcunit
SOURCES= ../src/board.c ../src/jump.c ../src/pos.c
TESTEXECUTABLE= itriangle-tests

all: $(TESTEXECUTABLE)

$(TESTEXECUTABLE): tests.c $(SOURCES)
	$(CC) $(CFLAGS) $(INCLUDE) tests.c $(SOURCES) -o ../build/$@ $(LIBS)

.PHONY: clean

clean: 
	rm -f ../build/$(TESTEXECUTABLE) 
