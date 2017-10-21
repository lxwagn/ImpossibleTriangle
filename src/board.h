/******************************************************************
 *  File: board.h                                                 *
 *  Project: Impossible Triangle                                  *
 *  Author: Lucas Wagner                                          *
 *  Purpose: Board Data (Headers)                                 *
 *  FOR DEMONSTRATION USE ONLY                                    *
 *  COPYRIGHT (c)2017, Lucas C. Wagner. All Rights Reserved.      *
 ******************************************************************/

#pragma once

int checkState(Coord *pos);
int setState(Coord *pos, int state);
int initializeBoard();
int checkBoardForWin();
