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
INCLUDE= -I/usr/local/include
LIBS= -L/usr/local/lib -lcunit
SOURCES= board.c jump.c pos.c
EXECUTABLE= itriangle
TESTEXECUTABLE= itriangle-tests

all: $(EXECUTABLE)

$(EXECUTABLE): main.c $(SOURCES)
	$(CC) $(CFLAGS) main.c $(SOURCES) -o $@ 

tests: $(TESTEXECUTABLE)

$(TESTEXECUTABLE): tests.c $(SOURCES)
	$(CC) $(CFLAGS) $(INCLUDE) tests.c $(SOURCES) -o $@ $(LIBS)

.PHONY: clean

clean: 
	rm -f $(EXECUTABLE)	
	rm -f $(TESTEXECUTABLE) 
