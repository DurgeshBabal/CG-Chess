// header for game play class
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

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
To do:
Check notification
Stalemate
Checkmate
Pawn turning to power unit at end of board
Double square movement of pawn at beginning of game
castling
16 steps end game when all pieces lost or tied

*/
/*
Variables to be declared:

extern Check;
extern Checkmate;
hasmoved
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
        GamePlay();
        GamePlay(const GamePlay &obj);

        int GetSquareIdX();

        int GetSquareIdY();

        int GetX();

        int GetY();

        int GetPieceId();

        int SetSquareIdX(int X);

        int SetSquareIdY(int Y);

        int SetX(int x);

        int SetY(int y);

        int SetPieceId(int id);

};

//Generate the 2-D array which maps to the chessboard
void Populate(int BoardX, int BoardY, int length, GamePlay BoardArray[8][8]);

#endif
