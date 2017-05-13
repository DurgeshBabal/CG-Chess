#ifndef MOVESET_H
#define MOVESET_H

#include "gameplay.h"
#include <stdlib.h>

void PawnMoveSet(GamePlay Square1, int MoveSet[27][2], GamePlay BoardArray[8][8]);

void RookMoveSet(GamePlay Square1, int MoveSet[27][2], GamePlay BoardArray[8][8]);

void KnightMoveSet(GamePlay Square1, int MoveSet[27][2], GamePlay BoardArray[8][8]);

void BishopMoveSet(GamePlay Square1, int MoveSet[27][2], GamePlay BoardArray[8][8]);

void QueenMoveSet(GamePlay Square1, int MoveSet[27][2], GamePlay BoardArray[8][8]);

void KingMoveSet(GamePlay Square1, int MoveSet[27][2], GamePlay BoardArray[8][8]);

int MoveSetFunction(int arr[4], int Moveset[27][2], GamePlay BoardArray[8][8]);

#endif
