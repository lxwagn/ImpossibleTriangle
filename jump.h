/******************************************************************
 *  File: jump.h                                                  *
 *  Project: Impossible Triangle                                  *
 *  Author: Lucas Wagner                                          *
 *  Purpose: Movement and Jump Data (Header)                      *
 *  FOR DEMONSTRATION USE ONLY                                    *
 *  COPYRIGHT (c)2017, Lucas C. Wagner. All Rights Reserved.      *
 ******************************************************************/

#pragma once

int validJumps(Coord *pos);
enum jumpFlags validRandomJump(Coord *pos);
int jumpFromCurPos(enum jumpFlags destination);

/* testing only */
Coord *isLeftParentValid(Coord *pos);
Coord *isRightParentValid(Coord *pos);
Coord *isLeftSiblingValid(Coord *pos);
Coord *isRightSiblingValid(Coord *pos);
Coord *isLeftChildValid(Coord *pos);
Coord *isRightChildValid(Coord *pos);
