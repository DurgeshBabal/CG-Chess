
#include "event.h"

int Check(int IsWhiteMove, GamePlay BoardArray[8][8], int Check)
{
    int i,j,arr[4];
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
                    Check=Move(arr,BoardArray);
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
                    Check=Move(arr,BoardArray);
                    if(Check)
                        break;
                }
            }
        }
    }
    return Check;
}

int Stalemate(int IsWhiteMove, GamePlay BoardArray[8][8], int Stalemate)
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
                    size=MoveSet(arr);
                    for(k=0; k<size; k++)
                    {
                        arr[2]=MoveSet[k][0];
                        arr[3]=MoveSet[k][1];
                        Stalemate=Move(arr,BoardArray);
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
                    size=MoveSet(arr);
                    for(k=0; k<size; k++)
                    {
                        arr[2]=MoveSet[k][0];
                        arr[3]=MoveSet[k][1];
                        Stalemate=Move(arr,BoardArray);
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

int Checkmate(int Check, int Stalemate, int Checkmate)
{
    if(Check==1 && Stalemate==1)
        Checkmate==1;
    return Checkmate;
}

void Castling()
{

}
