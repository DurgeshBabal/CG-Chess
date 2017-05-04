// defines the piece class source

#include "piece.h"
#include <GL/glut.h>

int Piece::Pawn(GLfloat x, GLfloat y, GLfloat l)
{
    GLfloat VerticesRectangle[]={x+(8*l/25),y+(3*l/25), x+(8*l/25),y+(13*l/25),
                                x+(17*l/25),y+(13*l/25), x+(17*l/25),y+(3*l/25)};
    // draw the rectangle
    DrawQuad(VerticesRectangle);

    DrawCircleFilled(x+(12.5*l/25),y+(16.5*l/25), 3.5*l/25, 100);
}

int Piece::Rook(GLfloat x, GLfloat y, GLfloat l)
{

}

int Piece::Knight(GLfloat x, GLfloat y, GLfloat l)
{

}

int Piece::Bishop(GLfloat x, GLfloat y, GLfloat l)
{

}

int Piece::King(GLfloat x, GLfloat y, GLfloat l)
{

}

int Piece::Queen(GLfloat x, GLfloat y, GLfloat l)
{
    
}
