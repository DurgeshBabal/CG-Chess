#ifndef EVENT_H
#define EVENT_H

int Check(int IsWhiteMove, GamePlay BoardArray[8][8], int Check);

int Stalemate(int IsWhiteMove, GamePlay BoardArray[8][8], int Check);

int Checkmate(int Check, int Stalemate, int Checkmate);

#endif
