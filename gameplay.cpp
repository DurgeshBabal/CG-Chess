// implementation Of GamePlay class

#include "gameplay.h"

int PieceIdArray[8] = {2,3,4,5,6,4,3,2};

void Populate(int BoardX, int BoardY, int length, GamePlay BoardArray[8][8], int ActionId)
{
	if(ActionId == 1)
	{
		int i,j;
		for(i=0; i<8; i++)
		{
			for(j=0; j<8; j++)
			{
				BoardArray[i][j].SetSquareIdX(i);
				BoardArray[i][j].SetSquareIdY(j);
				BoardArray[i][j].SetX(BoardX + (j*length));
				BoardArray[i][j].SetY(BoardY + ((7-i)*length));
				if(i==0)
				{
					BoardArray[i][j].SetPieceId(-1*PieceIdArray[j]);
				}
				else if(i==1)
				{
					BoardArray[i][j].SetPieceId(-1);
				}
				else if(i==6)
				{
					BoardArray[i][j].SetPieceId(1);
				}
				else if(i==7)
				{
					BoardArray[i][j].SetPieceId(PieceIdArray[j]);
				}
				else	BoardArray[i][j].SetPieceId(0);
			}
		}
	}
	/*
	else if(ActionId == 3)
	{
		FILE *open;
		open = fopen("/savegame/save.bin", "r");
		if(open<0)
		{
			cout<<"\nError in opening the savegame file for reading";
			return;
		}
		for(i=0; i<8; i++)
		{
			for(j=0; j<8; j++)
			{
				open.read((char*)&temp,sizeof(temp))
				BoardArray[i][j].Copy(temp);
			}
		}
		open.close();
	}
	*/
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

void GamePlay::SetSquareIdX(int X)
{
    SquareIdX=X;
}

void GamePlay::SetSquareIdY(int Y)
{
    SquareIdY=Y;
}

void GamePlay::SetX(int X)
{
    x=X;
}

void GamePlay::SetY(int Y)
{
    y=Y;
}

void GamePlay::SetPieceId(int id)
{
    PieceId=id;
}

void GamePlay::Copy(GamePlay obj)
{
	SquareIdX = obj.SquareIdX;
    SquareIdY = obj.SquareIdY;
    x = obj.x;
    y = obj.y;
    PieceId = obj.PieceId;
}

int GamePlay::IsInside(int MouseX, int MouseY, int length)
{
    if( ( MouseX > x && MouseX < x+length ) && ( MouseY > y && MouseY < y+length ) )
        return 1;
    return 0;
}
