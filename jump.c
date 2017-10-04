/******************************************************************
 *  File: jump.c                                                  *
 *  Project: Impossible Triangle                                  *
 *  Author: Lucas Wagner                                          *
 *  Purpose: Movement and Jump Data                               * 
 *  FOR DEMONSTRATION USE ONLY                                    *
 *  COPYRIGHT (c)2017, Lucas C. Wagner. All Rights Reserved.      *
 ******************************************************************/

#include "common.h"
#include "jump.h"
#include "pos.h"
#include "board.h"

/* neighborhood and jump coordinates */

static Coord leftParent[1],   jumpLeftParent[1];
static Coord rightParent[1],  jumpRightParent[1];
static Coord leftSibling[1],  jumpLeftSibling[1];
static Coord rightSibling[1], jumpRightSibling[1];
static Coord leftChild[1],    jumpLeftChild[1];
static Coord rightChild[1],   jumpRightChild[1];

Coord *isLeftParentValid(Coord *pos)
{
    if ((pos == NULL) || (pos->x == 0) || (pos->y == 0)) {
        return NULL;
    }

    pos->x -= 1;
    pos->y -= 1;

    return pos;
}

Coord *isRightParentValid(Coord *pos)
{
    if ((pos == NULL) || (pos->x == 0) || (pos->x == pos->y)) {
        return NULL;
    }

    pos->x -= 1;
    /* pos->y unchanged */

    return pos;
}

Coord *isLeftSiblingValid(Coord *pos)
{
    if ((pos == NULL) || (pos->y == 0)) {
        return NULL;
    }

    /* pos->x unchanged */
    pos->y -= 1;

    return pos;
}

Coord *isRightSiblingValid(Coord *pos)
{
    if ((pos == NULL) || (pos->x == pos->y)) {
        return NULL;
    }

    /* pos->x unchanged */
    pos->y += 1;

    return pos;
}

Coord *isLeftChildValid(Coord *pos)
{
    if ((pos == NULL) || (pos->x == BOARD_BOUNDS)) {
        return NULL;
    }

    pos->x += 1;
    /* pos->y unchanged */

    return pos;
}

Coord *isRightChildValid(Coord *pos)
{
    if ((pos == NULL) || (pos->x == BOARD_BOUNDS)) {
        return NULL;
    }

    pos->x += 1;
    pos->y += 1;

    return pos;
}

int validJumps(Coord *pos)
{

    /* for return */
    int validJumps = JUMPFLAGS_NONE;

    Coord *origin = (Coord *)malloc(sizeof(Coord));

    *origin = *pos;
    if ((isLeftParentValid(origin)) && (checkState(origin) == 1)) {
        *leftParent = *origin;
        if ((isLeftParentValid(origin)) && (checkState(origin) == 0)) {
            *jumpLeftParent = *origin;
            validJumps |= JUMPFLAGS_LPARENT;
        }
    }

    *origin = *pos;
    if ((isRightParentValid(origin)) && (checkState(origin) == 1)) {
        *rightParent = *origin;
        if ((isRightParentValid(origin)) && (checkState(origin) == 0)) {
            *jumpRightParent = *origin;
            validJumps |= JUMPFLAGS_RPARENT;
        }
    }

    *origin = *pos;
    if ((isLeftSiblingValid(origin)) && (checkState(origin) == 1)) {
        *leftSibling = *origin;
        if ((isLeftSiblingValid(origin)) && (checkState(origin) == 0)) {
            *jumpLeftSibling = *origin;
            validJumps |= JUMPFLAGS_LSIBLING;
        }
    }

    *origin = *pos;
    if ((isRightSiblingValid(origin)) && (checkState(origin) == 1)) {
        *rightSibling = *origin;
        if ((isRightSiblingValid(origin)) && (checkState(origin) == 0)) {
            *jumpRightSibling = *origin;
            validJumps |= JUMPFLAGS_RSIBLING;
        }
    }

    *origin = *pos;
    if ((isLeftChildValid(origin)) && (checkState(origin) == 1)) {
        *leftChild = *origin;
        if ((isLeftChildValid(origin)) && (checkState(origin) == 0)) {
            *jumpLeftChild = *origin;
            validJumps |= JUMPFLAGS_LCHILD;
        }
    }

    *origin = *pos;
    if ((isRightChildValid(origin)) && (checkState(origin) == 1)) {
        *rightChild = *origin;
        if ((isRightChildValid(origin)) && (checkState(origin) == 0)) {
            *jumpRightChild = *origin;
            validJumps |= JUMPFLAGS_RCHILD;
        }
    }

    free(origin);

    return validJumps;
}

/* 
 * validRandomJump()
 * - Will randomly pick a jump direction based on validJumps()
 * - Seeding takes place in main()
 */

enum jumpFlags validRandomJump(Coord *pos)
{
    int randomNum = 0;
    enum jumpFlags jump = JUMPFLAGS_NONE;
    int end = 0;
    int i;

    if (validJumps(pos) == 0)
        return JUMPFLAGS_NONE;

    while(!end) {
        for(i = 0; i < 8; i++) {
            if((validJumps(pos) >> i) & 0x01) {
                randomNum = rand() % 2;
                if(randomNum)
                    jump = (enum jumpFlags) 1 << i;
                end = 1;
            }
        }
    }
    return jump;
}

/* 
 * jump()
 * - completes the actual jump from curPos and flips the bits
 * - returns 1 if successful, 0 if unsuccessful
 */

int jumpFromCurPos(enum jumpFlags destination)
{

    /* illegal jump */
    if ( !(validJumps(getCurPos()) & destination) )
        return 0;

    switch(destination) {
    case JUMPFLAGS_LPARENT:
        setState(getCurPos(), 0);
        setState(leftParent, 0);
        setState(jumpLeftParent, 1);
        setCurPos(jumpLeftParent);
        break;
    case JUMPFLAGS_RPARENT:
        setState(getCurPos(), 0);
        setState(rightParent, 0);
        setState(jumpRightParent, 1);
        setCurPos(jumpRightParent);
        break;
    case JUMPFLAGS_LSIBLING:
        setState(getCurPos(), 0);
        setState(leftSibling, 0);
        setState(jumpLeftSibling, 1);
        setCurPos(jumpLeftSibling);
        break;
    case JUMPFLAGS_RSIBLING:
        setState(getCurPos(), 0);
        setState(rightSibling, 0);
        setState(jumpRightSibling, 1);
        setCurPos(jumpRightSibling);
        break;
    case JUMPFLAGS_LCHILD:
        setState(getCurPos(), 0);
        setState(leftChild, 0);
        setState(jumpLeftChild, 1);
        setCurPos(jumpLeftChild);
        break;
    case JUMPFLAGS_RCHILD:
        setState(getCurPos(), 0);
        setState(rightChild, 0);
        setState(jumpRightChild, 1);
        setCurPos(jumpRightChild);
        break;
    default:
        return 0;
        break;
    }

    return 1;

}
