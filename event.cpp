
#include "event.h"

int CheckFunction(int IsWhiteMove, GamePlay BoardArray[8][8])
{
    int i,j,arr[4],Check;
    for (i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            if(IsWhiteMove==0)
            {
                if(BoardArray[i][j].GetPieceId()==-6)
                {
                    arr[2]=i;
                    arr[3]=j;
                }
            }
            else
            {
                if(BoardArray[i][j].GetPieceId()==6)
                {
                    arr[2]=i;
                    arr[3]=j;
                }
            }
        }
    }
    for (i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            if(IsWhiteMove==0)
            {
                if(BoardArray[i][j].GetPieceId()>0)
                {
                    arr[0]=i;
                    arr[1]=j;
                    Check=Move(arr, BoardArray);
                    if(Check)
                        break;
                }
            }
            else
            {
                if(BoardArray[i][j].GetPieceId()<0)
                {
                    arr[0]=i;
                    arr[1]=j;
                    Check=Move(arr, BoardArray);
                    if(Check)
                        break;
                }
            }
        }
    }
    return Check;
}

int StalemateFunction(int IsWhiteMove, GamePlay BoardArray[8][8], int Stalemate, int MoveSet[27][2])
{
    int i,j,k,arr[4],size;
    for (i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            if(IsWhiteMove==0)
            {
                if(BoardArray[i][j].GetPieceId()<0)
                {
                    arr[0]=i;
                    arr[1]=j;
                    size=MoveSetFunction(arr, MoveSet, BoardArray);
                    for(k=0; k<size; k++)
                    {
                        arr[2]=MoveSet[k][0];
                        arr[3]=MoveSet[k][1];
                        Stalemate=Move(arr, BoardArray);
                        if(Stalemate)
                            break;
                    }
                }
            }
            else
            {
                if(BoardArray[i][j].GetPieceId()>0)
                {
                    arr[0]=i;
                    arr[1]=j;
                    size=MoveSetFunction(arr, MoveSet, BoardArray);
                    for(k=0; k<size; k++)
                    {
                        arr[2]=MoveSet[k][0];
                        arr[3]=MoveSet[k][1];
                        Stalemate=Move(arr, BoardArray);
                        if(Stalemate)
                            break;
                    }
                }
            }
        }
    }
    Stalemate = abs(Stalemate-1);
    return Stalemate;
}

int CheckmateFunction(int Check, int Stalemate, int Checkmate)
{
    if(Check==1 && Stalemate==1)
        Checkmate==1;
    return Checkmate;
}

int Castling(int Check, GamePlay Square1, GamePlay Square2, GamePlay BoardArray[8][8])
{
    printf("\nIn castling");
    int i,j;
    if(Check==1)
    {
        return 0;
    }
    if(Square2.GetSquareIdY()>Square1.GetSquareIdY())
    {
        for(i=Square1.GetSquareIdY()+1; i<7; i++)
        {
            if(BoardArray[Square1.GetSquareIdX()][i].GetPieceId()!=0)
                return 0;
        }
        j=1;
    }
    else
    {
        for(i=Square1.GetSquareIdY()-1; i>0; i--)
        {
            if(BoardArray[Square1.GetSquareIdX()][i].GetPieceId()!=0)
                return 0;
        }
        j=-1;
    }
    if(abs(BoardArray[Square1.GetSquareIdX()][i].GetPieceId())==2 && BoardArray[Square1.GetSquareIdX()][i].GetHasMoved()==0)
    {
        BoardArray[Square1.GetSquareIdX()][Square1.GetSquareIdY()+j].SetPieceId(BoardArray[Square1.GetSquareIdX()][i].GetPieceId());
        BoardArray[Square1.GetSquareIdX()][i].SetPieceId(0);
        BoardArray[Square1.GetSquareIdX()][Square1.GetSquareIdY()+j].SetHasMoved(1);

        BoardArray[Square1.GetSquareIdX()][Square1.GetSquareIdY()+(2*j)].SetPieceId(BoardArray[Square1.GetSquareIdX()][Square1.GetSquareIdY()].GetPieceId());
        BoardArray[Square1.GetSquareIdX()][Square1.GetSquareIdY()].SetPieceId(0);
        BoardArray[Square1.GetSquareIdX()][Square1.GetSquareIdY()+(2*j)].SetHasMoved(1);
        return 1;
    }
    return 0;
}
