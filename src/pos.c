/******************************************************************
 *  File: pos.c                                                   *
 *  Project: Impossible Triangle                                  *
 *  Author: Lucas Wagner                                          *
 *  Purpose: Board Positional Data                                *
 *  FOR DEMONSTRATION USE ONLY                                    *
 *  COPYRIGHT (c)2017, Lucas C. Wagner. All Rights Reserved.      *
 ******************************************************************/

#include "common.h"
#include "pos.h"
#include "board.h"

static Coord curPos = {0,0};

/*
 * getCurPos()
 * - returns the address of curPos as a pointer to a coordinate
 */

Coord *getCurPos()
{
    return &curPos;
}

/* 
 * setCurPos()
 * - sets curPos when given a pointer to a coordinate
 */

Coord *setCurPos(Coord *pos)
{
    curPos.x = pos->x;
    curPos.y = pos->y;

    /* illegal move */
    if(checkState(pos) != 1)
        return NULL;

    return &curPos;
}

/* 
 * getRandomPos()
 * - used in figuring out a valid starting point
 * - returns a pseudo-random, valid location on the gameboard
 */

Coord *getRandomPos()
{
    int timeout = 0; /* infinite loop protection */
    Coord *pos = (Coord *)malloc(sizeof(Coord));

    while(timeout < 100) {
        pos->x = (rand() % BOARD_BOUNDS + 1);
        pos->y = (rand() % BOARD_BOUNDS + 1);

        if(checkState(pos) == 1) {
            return pos; /* we found one */
        }
        timeout++;
    }

    return NULL; /* nothing found */
}

