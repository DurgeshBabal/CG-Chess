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
				BoardArray[i][j].SetHasMoved(0);
			}
		}
	}
	else if(ActionId == 3)
	{
		FILE *fp;
	    fp = fopen("currentgame.save", "r");
	    if(fp<0)
	    {
	        printf("Error in opening the savegame file for reading\n");
	        return;
	    }
	    for(int i=0; i<8; i++)
	    {
	        for(int j=0; j<8; j++)
	        {
	            int DataToReaded[sizeof(GamePlay)];

				fread(DataToReaded, sizeof(GamePlay), 5, fp);

				printf("SquareIdX: %d ",DataToReaded[0]);
	            printf("SquareIdY: %d ",DataToReaded[1]);
	            printf("X-coordinate: %d ",DataToReaded[2]);
	            printf("Y-coordinate: %d ",DataToReaded[3]);
	            printf("PieceId: %d \n",DataToReaded[4]);

				BoardArray[i][j].SetSquareIdX(DataToReaded[0]);
	            BoardArray[i][j].SetSquareIdY(DataToReaded[1]);
	            BoardArray[i][j].SetX(DataToReaded[2]);
	            BoardArray[i][j].SetY(DataToReaded[3]);
	            BoardArray[i][j].SetPieceId(DataToReaded[4]);

	        }
	    }
		printf("DataToReaded and put into object\n");

		for (int i = 0; i < 8; i++)
		{
	       for (int j=0; j < 8; j++)
		   {
	            printf("SquareIdX: %d ",BoardArray[i][j].GetSquareIdX());
	            printf("SquareIdY: %d ",BoardArray[i][j].GetSquareIdY());
	            printf("X-coordinate: %d ",BoardArray[i][j].GetX());
	            printf("Y-coordinate: %d ",BoardArray[i][j].GetY());
	            printf("PieceId: %d \n",BoardArray[i][j].GetPieceId());
	       }
	    }
		printf("Object Dumped\n");
		fclose(fp);
	}
	return ;
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

int GamePlay::GetHasMoved()
{
	return HasMoved;
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

void GamePlay::SetHasMoved(int moved)
{
	HasMoved=moved;
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
