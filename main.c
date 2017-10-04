/******************************************************************
 *  File: main.c                                                  *
 *  Project: Impossible Triangle                                  *
 *  Author: Lucas Wagner                                          *
 *  Purpose: main() and Game State Functions                      * 
 *  FOR DEMONSTRATION USE ONLY                                    *
 *  COPYRIGHT (c)2017, Lucas C. Wagner. All Rights Reserved.      *
 ******************************************************************/

#include "common.h"
#include "board.h"
#include "pos.h"
#include "jump.h"

static Coord winningMoves[MAX_ARRAY];
static Coord *winningMove = winningMoves;

static void addToWinningMoves(Coord *pos)
{
    *winningMove = *pos;
    winningMove++;
}

static void clearWinningMoves()
{
    memset(winningMoves, 0, sizeof(winningMoves));
    winningMove = winningMoves;
}

static void printWinningMoves()
{
    int i = 1;
    Coord *base;

    for (base = winningMoves; base < winningMove ; base++) {
        printf("%d. [%d,%d]->", i, base->x, base->y);
        base++;
        printf("[%d,%d]\n", base->x, base->y);
        i++;
    }

}

static void congratulate(int attempts, Coord *pos){
	int estimatedActual = attempts * 3 + 5;

	printf("\n");
    printf("Impossible Triangle\n");
    printf("-------------------\n\n");

    printf("Congratulations! The Impossible Triangle was solved in %d attempts.\n\n", attempts);

	printf("Based on some extremely scientific assumptions (e.g., three minutes \n");
	printf("per iteration, after drinks were brought out and the patrons grew \n");
	printf("tired of staring at the folksy trinkets on the walls), this would \n");
	printf("have taken an actual restaurant patron %d minutes.\n\n", estimatedActual);

	printf("The winning start void was at location [%d,%d].\n\n", pos->x, pos->y);

	printf("Winning moves (sequentially, in order of play):\n\n");

    printWinningMoves();
	printf("\n");
}
 
static void interruptHandler(int dummy)
{
    printf("Caught SIGINT. Aborting.\n");
    exit(1);
}

int main(int argc, char *argv[])
{
    /* trap SIGINT for cleanup */
    signal(SIGINT, interruptHandler);

    /* seeding for rand() */
    srand(time(0));

    /* randomize starting point */
    while(1) {
        int attempts = 0;
        Coord *randEmpty = NULL;

        /* setup the board */
        initializeBoard(1);

        /* pick an initial empty spot */
        randEmpty = getRandomPos();
        if (randEmpty) {
            setState(randEmpty, 0);
        } else {
            printf("ERROR: Unable to set random empty spot. Aborting.\n");
            exit(1);
        }

        clearWinningMoves();

        /* 50 tries is arbitrary. For larger puzzles, it may need more
         * or else it will exit without finding a starting spot. */
        while(attempts < 50) {
            Coord *randPos = NULL;

            /* pick and set a random starting spot */
            randPos = getRandomPos();
            if (randPos) {
                setCurPos(randPos);
                free(randPos);
            } else {
                printf("ERROR: Unable to set random starting spot. Aborting.\n");
                exit(1);
            }

            while(validJumps(getCurPos()) != JUMPFLAGS_NONE) {
                enum jumpFlags proposedJump;

                proposedJump = validRandomJump(getCurPos());
                if (proposedJump == JUMPFLAGS_NONE)
                    continue;

                addToWinningMoves(getCurPos());
                jumpFromCurPos(proposedJump);
                addToWinningMoves(getCurPos());
                if (checkBoardForWin()) {
                   congratulate(attempts, randEmpty);
                   exit(0);
                }
            }
            attempts++;
        }

        free(randEmpty);
    }

}
