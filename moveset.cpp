
#include "moveset.h"

int size;
int Displacement[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
int DisplacementKnight[8][2]={{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};

int PawnMoveset(GamePlay Square1, int Moveset[27][2], GamePlay BoardArray[8][8])
{
    int i;
    for(i=0; i<3; i++)
    {
        if(Square1.GetPieceId()>0)
        {
            Moveset[i][0]=BoardArray[Square1.GetSquareIdX()-1][Square1.GetSquareIdY()-1+i].GetSquareIdX();
            Moveset[i][1]=BoardArray[Square1.GetSquareIdX()-1][Square1.GetSquareIdY()-1+i].GetSquareIdY();
        }
        else
        {
            Moveset[i][0]=BoardArray[Square1.GetSquareIdX()+1][Square1.GetSquareIdY()-1+i].GetSquareIdX();
            Moveset[i][1]=BoardArray[Square1.GetSquareIdX()+1][Square1.GetSquareIdY()-1+i].GetSquareIdY();
        }
    }
    size = i;
}

int RookMoveset(GamePlay Square1, int Moveset[27][2], GamePlay BoardArray[8][8])
{
    int i,j=1;
    for(i=0; i<4; i++)
    {
        Moveset[i][0]=BoardArray[Square1.GetSquareIdX()+Displacement[j][0]][Square1.GetSquareIdY()+Displacement[j][1]].GetSquareIdX();
        Moveset[i][1]=BoardArray[Square1.GetSquareIdX()+Displacement[j][0]][Square1.GetSquareIdY()+Displacement[j][1]].GetSquareIdY();
        j=j+2;
    }
    size = 4;
}

void KnightMoveset(GamePlay Square1, int Moveset[27][2], GamePlay BoardArray[8][8])
{
    int i,j=0;
    for(i=0; i<8; i++)
    {
        Moveset[i][0]=BoardArray[Square1.GetSquareIdX()+DisplacementKnight[j][0]][Square1.GetSquareIdY()+DisplacementKnight[j][1]].GetSquareIdX();
        Moveset[i][1]=BoardArray[Square1.GetSquareIdX()+DisplacementKnight[j][0]][Square1.GetSquareIdY()+DisplacementKnight[j][1]].GetSquareIdY();
        j++;
    }
    size = 8;
}

void BishopMoveset(GamePlay Square1, int Moveset[27][2], GamePlay BoardArray[8][8])
{
    int i,j=0;
    for(i=0; i<4; i++)
    {
        Moveset[i][0]=BoardArray[Square1.GetSquareIdX()+Displacement[j][0]][Square1.GetSquareIdY()+Displacement[j][1]].GetSquareIdX();
        Moveset[i][1]=BoardArray[Square1.GetSquareIdX()+Displacement[j][0]][Square1.GetSquareIdY()+Displacement[j][1]].GetSquareIdY();
        j=j+2;
    }
    size = 4;
}

void QueenMoveset(GamePlay Square1, int Moveset[27][2], GamePlay BoardArray[8][8])
{
    int i,j=0;
    for(i=0; i<4; i++)
    {
        Moveset[i][0]=BoardArray[Square1.GetSquareIdX()+Displacement[j][0]][Square1.GetSquareIdY()+Displacement[j][1]].GetSquareIdX();
        Moveset[i][1]=BoardArray[Square1.GetSquareIdX()+Displacement[j][0]][Square1.GetSquareIdY()+Displacement[j][1]].GetSquareIdY();
        j++;
    }
    size = 4;
}

void KingMoveset(GamePlay Square1, int Moveset[27][2], GamePlay BoardArray[8][8])
{
    int i,j=0;
    for(i=0; i<4; i++)
    {
        Moveset[i][0]=BoardArray[Square1.GetSquareIdX()+Displacement[j][0]][Square1.GetSquareIdY()+Displacement[j][1]].GetSquareIdX();
        Moveset[i][1]=BoardArray[Square1.GetSquareIdX()+Displacement[j][0]][Square1.GetSquareIdY()+Displacement[j][1]].GetSquareIdY();
        j++;
    }
    size = 4;
}

int Moveset(int arr)
{
    GamePlay Square1.Copy(BoardArray[arr[0]][arr[1]]);

    switch(abs(Square1.GetPieceId()))
	{
		case 1: PawnMoveset(Square1, Moveset, BoardArray);
				break;
		case 2: RookMoveset(Square1, Moveset, BoardArray);
				break;
		case 3: KnightMoveset(Square1, Moveset, BoardArray);
				break;
		case 4: BishopMoveset(Square1, Moveset, BoardArray);
				break;
		case 5: QueenMoveset(Square1, Moveset, BoardArray);
				break;
		case 6: KingMoveset(Square1, Moveset, BoardArray);
				break;
	}
    return size;
}
