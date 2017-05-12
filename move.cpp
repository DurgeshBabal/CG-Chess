
#include "move.h"

int PawnMove(GamePlay Square1, GamePlay Square2)
{
	printf("In PawnMove\n");
	if(Square1.GetPieceId()>0 && Square2.GetSquareIdX() != Square1.GetSquareIdX()-1)
	{
		printf("In PawnMove 1\n");
		return 0;
	}
	else if(Square1.GetPieceId()<0 && Square2.GetSquareIdX() != Square1.GetSquareIdX()+1)
	{
			printf("In PawnMove 1\n");
			return 0;
	}
	else if(Square2.GetSquareIdY() == Square1.GetSquareIdY())
	{
		if(Square2.GetPieceId()!=0)
		{
			printf("In PawnMove 2\n");
			return 0;
		}
	}
	else if(abs(Square2.GetSquareIdY()-Square1.GetSquareIdY())>1)
	{
		return 0;
	}
	else if(abs(Square2.GetSquareIdY()-Square1.GetSquareIdY())==1)
	{
		if(Square2.GetPieceId()*Square1.GetPieceId()>0 || Square2.GetPieceId()==0)
		{
			printf("In PawnMove 3\n");
			return 0;
		}
	}
	return 1;
}

int RookMove(GamePlay Square1, GamePlay Square2, GamePlay BoardArray[8][8])
{
	if(Square2.GetSquareIdY() != Square1.GetSquareIdY() && Square2.GetSquareIdX() != Square1.GetSquareIdX())
	{
		return 0;
	}
	else
	{
		if(Square2.GetPieceId()*Square1.GetPieceId()>0)
		{
			return 0;
		}
		if(Square2.GetSquareIdY() == Square1.GetSquareIdY())
		{
            int i,j=Square1.GetSquareIdY();
			if(Square1.GetSquareIdX()<Square2.GetSquareIdX())
			{
				for(i=Square1.GetSquareIdX()+1; i<Square2.GetSquareIdX(); i++)
				{
					if(BoardArray[i][j].GetPieceId()!=0)
						break;
				}
			}
			else
			{
				for(i=Square1.GetSquareIdX()-1; i>Square2.GetSquareIdX(); i--)
				{
					if(BoardArray[i][j].GetPieceId()!=0)
						break;
				}
			}
			if(i!=Square2.GetSquareIdX())
			{
				return 0;
			}
		}
		else
		{
            int j,i=Square1.GetSquareIdX();
            if(Square1.GetSquareIdY()<Square2.GetSquareIdY())
			{
				for(j=Square1.GetSquareIdY()+1; j<Square2.GetSquareIdY(); j++)
				{
					if(BoardArray[i][j].GetPieceId()!=0)
						break;
				}
			}
			else
			{
				for(j=Square1.GetSquareIdY()-1; j>Square2.GetSquareIdY(); j--)
				{
					if(BoardArray[i][j].GetPieceId()!=0)
						break;
				}
			}
			if(j!=Square2.GetSquareIdY())
			{
				return 0;
			}
		}
	}
	return 1;
}

int KnightMove(GamePlay Square1, GamePlay Square2)
{
	if(Square2.GetPieceId()*Square1.GetPieceId()>0)
	{
		return 0;
	}
	else
	{
		if(abs(Square2.GetSquareIdX()-Square1.GetSquareIdX()) == 2)
		{
			if(abs(Square2.GetSquareIdY()-Square1.GetSquareIdY()) == 1)
			{
				return 1;
			}
		}
		else if(abs(Square2.GetSquareIdX()-Square1.GetSquareIdX()) == 1)
		{
			if(abs(Square2.GetSquareIdY()-Square1.GetSquareIdY()) == 2)
			{
				return 1;
			}
		}
	}
	return 0;
}

int BishopMove(GamePlay Square1, GamePlay Square2, GamePlay BoardArray[8][8])
{
	if(abs(Square1.GetSquareIdX()-Square2.GetSquareIdX()) != abs(Square1.GetSquareIdY()-Square2.GetSquareIdY()))
	{
		return 0;
	}
	else
	{
		if(Square2.GetPieceId()*Square1.GetPieceId()>0)
		{
			return 0;
		}
        int i,j;
		if(Square1.GetSquareIdX()<Square2.GetSquareIdX() && Square1.GetSquareIdY()<Square2.GetSquareIdY())
		{
			for(i=Square1.GetSquareIdX()+1,j=Square1.GetSquareIdY()+1; i<Square2.GetSquareIdX(),j<Square2.GetSquareIdY(); i++,j++)
			{
				if(BoardArray[i][j].GetPieceId()!=0)
					break;
			}
		}
		else if(Square1.GetSquareIdX()<Square2.GetSquareIdX() && Square1.GetSquareIdY()>Square2.GetSquareIdY())
		{
			for(i=Square1.GetSquareIdX()+1,j=Square1.GetSquareIdY()-1; i<Square2.GetSquareIdX(),j>Square2.GetSquareIdY(); i++,j--)
			{
				if(BoardArray[i][j].GetPieceId()!=0)
						break;
			}
		}
		else if(Square1.GetSquareIdX()>Square2.GetSquareIdX() && Square1.GetSquareIdY()<Square2.GetSquareIdY())
		{
			for(i=Square1.GetSquareIdX()-1,j=Square1.GetSquareIdY()+1; i>Square2.GetSquareIdX(),j<Square2.GetSquareIdY(); i--,j++)
			{
				if(BoardArray[i][j].GetPieceId()!=0)
						break;
			}
		}
		else
		{
			for(i=Square1.GetSquareIdX()-1,j=Square1.GetSquareIdY()-1; i>Square2.GetSquareIdX(),j>Square2.GetSquareIdY(); i--,j--)
			{
				if(BoardArray[i][j].GetPieceId()!=0)
						break;
			}
		}
		if(i!=Square2.GetSquareIdX())
		{
			return 0;
		}
	}
	return 1;
}

int KingMove(GamePlay Square1, GamePlay Square2)
{
	if(abs(Square1.GetSquareIdX()-Square2.GetSquareIdX())>1 || abs(Square1.GetSquareIdY()-Square2.GetSquareIdY())>1)
	{
		return 0;
	}
	else
	{
		if(Square2.GetPieceId()*Square1.GetPieceId()>0)
		{
			return 0;
		}
	}
	return 1;
}

int QueenMove(GamePlay Square1, GamePlay Square2, GamePlay BoardArray[8][8])
{
	int RookReturnValue, BishopReturnValue;

	RookReturnValue = RookMove(Square1, Square2, BoardArray);
	BishopReturnValue = BishopMove(Square1, Square2, BoardArray);

	if(RookReturnValue == 1 || BishopReturnValue == 1)
	{
		return 1;
	}
	return 0;
}

int Move(int* arr, GamePlay BoardArray[8][8])
{
    GamePlay Square1,Square2;
	Square1.Copy(BoardArray[arr[0]][arr[1]]);
	Square2.Copy(BoardArray[arr[2]][arr[3]]);
	int returnvalue;

	printf("Array[0] = %d\t",arr[0]);
	printf("Array[1] = %d\t",arr[1]);
	printf("Array[2] = %d\t",arr[2]);
	printf("Array[3] = %d\n",arr[3]);

	printf("Square1.GetSquareIdX() = %d\n", Square1.GetSquareIdX());
	printf("Square1.GetSquareIdY() = %d\n", Square1.GetSquareIdY());
	printf("Square1.GetX() = %d\n", Square1.GetX());
	printf("Square1.GetY() = %d\n", Square1.GetY());
	printf("Square1.GetPieceId() = %d\n", Square1.GetPieceId());

	printf("Square2.GetSquareIdX() = %d\n", Square2.GetSquareIdX());
	printf("Square2.GetSquareIdY() = %d\n", Square2.GetSquareIdY());
	printf("Square2.GetX() = %d\n", Square2.GetX());
	printf("Square2.GetY() = %d\n", Square2.GetY());
	printf("Square2.GetPieceId() = %d\n", Square2.GetPieceId());

	switch(abs(Square1.GetPieceId()))
	{
		case 0:	returnvalue = 0;
				break;
		case 1: returnvalue = PawnMove(Square1, Square2);
				break;
		case 2: returnvalue = RookMove(Square1, Square2, BoardArray);
				break;
		case 3: returnvalue = KnightMove(Square1, Square2);
				break;
		case 4: returnvalue = BishopMove(Square1, Square2, BoardArray);
				break;
		case 5: returnvalue = QueenMove(Square1, Square2, BoardArray);
				break;
		case 6: returnvalue = KingMove(Square1, Square2);
				break;
	}
	return returnvalue;
}
