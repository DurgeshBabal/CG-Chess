// implementation of the class chessboard
#include "chessboard.h"

// to draw black square
int ChessBoard::BlackSquare(GLfloat *vertices)
{
    //glColor3f(0,0,0);
    glColor3f((float)153/255, (float)51/255, (float)0/255);
    DrawQuad(vertices);
}

// to draw white square
int ChessBoard::WhiteSquare(GLfloat *vertices)
{
    //glColor3f(1,1,1);
    glColor3f((float)255/255, (float)230/255, (float)153/255);
    DrawQuad(vertices);
}

int ChessBoard::DrawChessBoard(GLfloat x0, GLfloat y0, GLfloat size)
{
    int n = 8; // number of the square in one row

    GLfloat x = x0;
    GLfloat y = y0;

    for (int i = 0; i < n; ++i)         // row
    {
        for (int j = 0; j < n; ++j)         // coloum
        {
            GLfloat vertices[] = {x, y, x+size, y, x+size, y+size, x, y+size};
            if (i%2==0)
            {
                if (j%2 == 0)
                    WhiteSquare(vertices);
                else
                    BlackSquare(vertices);
            }
            else
            {
                if (j%2 == 0)
                    BlackSquare(vertices);
                else
                    WhiteSquare(vertices);
            }
            x += size;
        }
        x = x0;
        y += size;
    }
}
