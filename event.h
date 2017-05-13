#ifndef EVENT_H
#define EVENT_H

#include "gameplay.h"
#include "move.h"
#include "moveset.h"

int CheckFunction(int IsWhiteMove, GamePlay BoardArray[8][8]);

int StalemateFunction(int IsWhiteMove, GamePlay BoardArray[8][8], int Check, int MoveSet[27][2]);

int CheckmateFunction(int Check, int Stalemate, int Checkmate);

int Castling(int Check, GamePlay Square1, GamePlay Square2, GamePlay BoardArray[8][8]);

#endif
