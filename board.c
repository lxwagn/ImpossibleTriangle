
/******************************************************************
 *  File: board.c                                                 *
 *  Project: Impossible Triangle                                  *
 *  Author: Lucas Wagner                                          *
 *  Purpose: Board Data                                           *
 *  FOR DEMONSTRATION USE ONLY                                    *
 *  COPYRIGHT (c)2017, Lucas C. Wagner. All Rights Reserved.      *
 ******************************************************************/

#include "common.h"
#include "board.h"

static int board[BOARD_SIZE][BOARD_SIZE];

/* 
 * intializeBoard()
 * - Set each board slots to the fill (should be 1)
 * - Set the "out of bounds" region to -1's
 * - Return the total pieces initialized
 */

int initializeBoard(int fill)
{
    int i, j;
    int count = 0;

    memset(board, -1, sizeof(board));
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j <= i; j++) {
            board[i][j] = fill;
            count++;
        }
    }

    return count;
}

/* 
 * checkState(Coord *pos)
 * - Given a coordinate, return the current value
 * - Possible return values:
 * 	  1 = slot is filled
 * 	  0 = slot is empty
 * 	 -1 = out of bounds
 */

int checkState(Coord *pos)
{
    return board[pos->x][pos->y];
}

/* 
 * setState(Coord *pos, int state)
 *	- Given a pointer to a coordinate, set state to one of the following:
 * 	   1 = slot is filled
 *     0 = slot is empty
 * 	  -1 = out of bounds
 */

int setState(Coord *pos, int state)
{
    board[pos->x][pos->y] = state;
    return board[pos->x][pos->y];
}

/* 
 * checkBoardForWin()
 * - Iterates through the array, counting pegs (1's)
 * - If there is only a single peg left, return 1. This is a win.
 */

int checkBoardForWin()
{
    int i, j;
    int piecesRemaining = 0;

    for (i = 0; i < (sizeof(board) / sizeof(board[0])); i++)
        for (j = 0; j < (sizeof(board) / sizeof(board[0])); j++)
            if(board[i][j] == 1)
                piecesRemaining++;

    if (piecesRemaining == 1)
        return 1;

    return 0;
}
