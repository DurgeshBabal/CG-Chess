// header for game play class
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <stdio.h>
/*
PieceId's are as follows:
1 -> pawn
2 -> rook
3 -> knight
4 -> bishop
5 -> queen
6 -> king
+ve -> white
-ve -> black
*/
/*
class SquareId
{
   	int SquareIdX;
	int SquareIdY;

	public:
		int GetSquareIdX();
        {
        	return SquareIdX;
        }
        int GetSquareIdY();
        {
        	return SquareIdY;
        }
        int SetSquareIdX(int X);
        {
        	SquareIdX=X;
        }
        int SetSquareIdY(int Y);
        {
        	SquareIdY=Y;
        }
}
*/
class GamePlay
{
    int SquareIdX;
    int SquareIdY;
    int x;
	int y;
	int PieceId;

    public:
        int GetSquareIdX();

        int GetSquareIdY();

        int GetX();

        int GetY();

        int GetPieceId();

        void SetSquareIdX(int X);

        void SetSquareIdY(int Y);

        void SetX(int x);

        void SetY(int y);

        void SetPieceId(int id);

        void Copy(GamePlay obj);

        // if the mouse clicked inside the board then this function return 1 else 0
        int IsInside(int MouseX, int MouseY, int length);

};

//Generate the 2-D array which maps to the chessboard
void Populate(int BoardX, int BoardY, int length, GamePlay BoardArray[8][8], int ActionId);

#endif
