/******************************************************************
 *  File: common.h												  *
 *  Project: Impossible Triangle                                  *
 *  Author: Lucas Wagner                                          *
 *  Purpose: Common Libraries, Structures, and Enums (Header)     *
 *  FOR DEMONSTRATION USE ONLY                                    *
 *  COPYRIGHT (c)2017, Lucas C. Wagner. All Rights Reserved.      *
 ******************************************************************/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>

#define BOARD_SIZE	    4
#define BOARD_BOUNDS	BOARD_SIZE - 1
#define MAX_ARRAY		100
#define MAX_TRIES		100

typedef struct Coordinate {
    int x;
    int y;
} Coord;

enum jumpFlags {
     JUMPFLAGS_NONE 	 = 0x0
    ,JUMPFLAGS_LPARENT 	 = 0x1
    ,JUMPFLAGS_RPARENT 	 = 0x2
    ,JUMPFLAGS_LSIBLING  = 0x4
    ,JUMPFLAGS_RSIBLING  = 0x8
    ,JUMPFLAGS_LCHILD 	 = 0x10
    ,JUMPFLAGS_RCHILD 	 = 0x20
};

