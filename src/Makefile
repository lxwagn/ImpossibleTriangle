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
LIBS= -L/usr/local/lib
SOURCES= board.c jump.c pos.c
EXECUTABLE= itriangle

all: $(EXECUTABLE)

$(EXECUTABLE): main.c $(SOURCES)
	$(CC) $(CFLAGS) main.c $(SOURCES) -o ../build/$@ 

.PHONY: clean

clean: 
	rm -f ../build/$(EXECUTABLE)	
