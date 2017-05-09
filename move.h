
#ifndef MOVE_H
#define MOVE_H

#include "gameplay.h"
#include <stdlib.h>

//Determine if pawn can move to specified position or not
int PawnMove(GamePlay Square1, GamePlay Square2);

//Determine if rook can move to specified position or not
int RookMove(GamePlay Square1, GamePlay Square2, GamePlay BoardArray[8][8]);

//Determine if knight can move to specified position or not
int KnightMove(GamePlay Square1, GamePlay Square2);

//Determine if bishop can move to specified position or not
int BishopMove(GamePlay Square1, GamePlay Square2, GamePlay BoardArray[8][8]);

//Determine if king can move to specified position or not
int KingMove(GamePlay Square1, GamePlay Square2);

//Determine if queen can move to specified position or not
int QueenMove(GamePlay Square1, GamePlay Square2, GamePlay BoardArray[8][8]);

//Determine the specified chess piece and if it can move or not
int Move(int* arr);

#endif
