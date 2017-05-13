
#include "moveset.h"

int size;
int Displacement[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
int DisplacementKnight[8][2]={{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};

void PawnMoveSet(GamePlay Square1, int MoveSet[27][2], GamePlay BoardArray[8][8])
{
    int i;
    for(i=0; i<3; i++)
    {
        if(Square1.GetPieceId()>0)
        {
            MoveSet[i][0]=BoardArray[Square1.GetSquareIdX()-1][Square1.GetSquareIdY()-1+i].GetSquareIdX();
            MoveSet[i][1]=BoardArray[Square1.GetSquareIdX()-1][Square1.GetSquareIdY()-1+i].GetSquareIdY();
        }
        else
        {
            MoveSet[i][0]=BoardArray[Square1.GetSquareIdX()+1][Square1.GetSquareIdY()-1+i].GetSquareIdX();
            MoveSet[i][1]=BoardArray[Square1.GetSquareIdX()+1][Square1.GetSquareIdY()-1+i].GetSquareIdY();
        }
    }
    size = i;
}

void RookMoveSet(GamePlay Square1, int MoveSet[27][2], GamePlay BoardArray[8][8])
{
    int i,j=1;
    for(i=0; i<4; i++)
    {
        MoveSet[i][0]=BoardArray[Square1.GetSquareIdX()+Displacement[j][0]][Square1.GetSquareIdY()+Displacement[j][1]].GetSquareIdX();
        MoveSet[i][1]=BoardArray[Square1.GetSquareIdX()+Displacement[j][0]][Square1.GetSquareIdY()+Displacement[j][1]].GetSquareIdY();
        j=j+2;
    }
    size = 4;
}

void KnightMoveSet(GamePlay Square1, int MoveSet[27][2], GamePlay BoardArray[8][8])
{
    int i,j=0;
    for(i=0; i<8; i++)
    {
        MoveSet[i][0]=BoardArray[Square1.GetSquareIdX()+DisplacementKnight[j][0]][Square1.GetSquareIdY()+DisplacementKnight[j][1]].GetSquareIdX();
        MoveSet[i][1]=BoardArray[Square1.GetSquareIdX()+DisplacementKnight[j][0]][Square1.GetSquareIdY()+DisplacementKnight[j][1]].GetSquareIdY();
        j++;
    }
    size = 8;
}

void BishopMoveSet(GamePlay Square1, int MoveSet[27][2], GamePlay BoardArray[8][8])
{
    int i,j=0;
    for(i=0; i<4; i++)
    {
        MoveSet[i][0]=BoardArray[Square1.GetSquareIdX()+Displacement[j][0]][Square1.GetSquareIdY()+Displacement[j][1]].GetSquareIdX();
        MoveSet[i][1]=BoardArray[Square1.GetSquareIdX()+Displacement[j][0]][Square1.GetSquareIdY()+Displacement[j][1]].GetSquareIdY();
        j=j+2;
    }
    size = 4;
}

void QueenMoveSet(GamePlay Square1, int MoveSet[27][2], GamePlay BoardArray[8][8])
{
    int i,j=0;
    for(i=0; i<4; i++)
    {
        MoveSet[i][0]=BoardArray[Square1.GetSquareIdX()+Displacement[j][0]][Square1.GetSquareIdY()+Displacement[j][1]].GetSquareIdX();
        MoveSet[i][1]=BoardArray[Square1.GetSquareIdX()+Displacement[j][0]][Square1.GetSquareIdY()+Displacement[j][1]].GetSquareIdY();
        j++;
    }
    size = 4;
}

void KingMoveSet(GamePlay Square1, int MoveSet[27][2], GamePlay BoardArray[8][8])
{
    int i,j=0;
    for(i=0; i<4; i++)
    {
        MoveSet[i][0]=BoardArray[Square1.GetSquareIdX()+Displacement[j][0]][Square1.GetSquareIdY()+Displacement[j][1]].GetSquareIdX();
        MoveSet[i][1]=BoardArray[Square1.GetSquareIdX()+Displacement[j][0]][Square1.GetSquareIdY()+Displacement[j][1]].GetSquareIdY();
        j++;
    }
    size = 4;
}

int MoveSetFunction(int arr[4], int MoveSet[27][2], GamePlay BoardArray[8][8])
{
    GamePlay Square1;
    Square1.Copy(BoardArray[arr[0]][arr[1]]);

    switch(abs(Square1.GetPieceId()))
	{
		case 1: PawnMoveSet(Square1, MoveSet, BoardArray);
				break;
		case 2: RookMoveSet(Square1, MoveSet, BoardArray);
				break;
		case 3: KnightMoveSet(Square1, MoveSet, BoardArray);
				break;
		case 4: BishopMoveSet(Square1, MoveSet, BoardArray);
				break;
		case 5: QueenMoveSet(Square1, MoveSet, BoardArray);
				break;
		case 6: KingMoveSet(Square1, MoveSet, BoardArray);
				break;
	}
    return size;
}
