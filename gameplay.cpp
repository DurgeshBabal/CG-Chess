// implementation Of GamePlay class

#include "gameplay.h"

int PieceIdArray[8] = {2,3,4,5,6,4,3,2};

void Populate(int BoardX, int BoardY, int length, GamePlay BoardArray[8][8])
{
	int i,j,k=0;
	for(i=7; i>-1; i--)
	{
		for(j=0; j<8; j++)
		{
			BoardArray[i][j].SetSquareIdX(k+1);
			BoardArray[i][j].SetSquareIdY(j+1);
			BoardArray[i][j].SetX(BoardX + (j*length));
			BoardArray[i][j].SetY(BoardY + (k*length));
			if(k==0)
			{
				BoardArray[i][j].SetPieceId(PieceIdArray[j]);
			}
			else if(k==1)
			{
				BoardArray[i][j].SetPieceId(1);
			}
			else if(i==0)
			{
				BoardArray[i][j].SetPieceId(-1*PieceIdArray[j]);
			}
			else if(i==1)
			{
				BoardArray[i][j].SetPieceId(-1);
			}
			else	BoardArray[i][j].SetPieceId(0);
		}
		k++;
	}
}

GamePlay::GamePlay()
{

}

GamePlay::GamePlay(const GamePlay &obj)
{
    SquareIdX = obj.SquareIdX;
    SquareIdY = obj.SquareIdY;
    x = obj.x;
    y = obj.y;
    PieceId = obj.PieceId;
}

int GamePlay::GetSquareIdX()
{
    return SquareIdX;
}

int GamePlay::GetSquareIdY()
{
    return SquareIdY;
}

int GamePlay::GetX()
{
    return x;
}

int GamePlay::GetY()
{
    return y;
}

int GamePlay::GetPieceId()
{
    return PieceId;
}

int GamePlay::SetSquareIdX(int X)
{
    SquareIdX=X;
}

int GamePlay::SetSquareIdY(int Y)
{
    SquareIdY=Y;
}

int GamePlay::SetX(int X)
{
    x=X;
}

int GamePlay::SetY(int Y)
{
    y=Y;
}

int GamePlay::SetPieceId(int id)
{
    PieceId=id;
}

int GamePlay::IsInside(int MouseX, int MouseY, int length)
{
    if( ( MouseX > x && MouseX < x+length ) && ( MouseY < y && MouseY > y+length ) )
        return 1;
    return 0;
}
