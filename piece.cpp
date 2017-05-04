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
    GLfloat VerticesTrapezium[]={ x+(6*l/25),y+(3*l/25), x+(7.5*l/25),y+(6*l/25),
                                  x+(17.5*l/25),y+(6*l/25), x+(20*l/25),y+(3*l/25)};
    DrawQuad(VerticesTrapezium);

    GLfloat VerticesRectangle[]={ x+(9*l/25),y+(6*l/25), x+(9*l/25),y+(14*l/25),
                                  x+(16*l/25),y+(14*l/25), x+(16*l/25),y+(6*l/25)};
    DrawQuad(VerticesRectangle);

    GLfloat VerticesRectangle1[]={ x+(7*l/25),y+(14*l/25), x+(7*l/25),y+(16*l/25),
                                   x+(18*l/25),y+(16*l/25), x+(18*l/25),y+(14*l/25)};
    DrawQuad(VerticesRectangle1);

    GLfloat VerticesRectangle2[]={ x+(7*l/25),y+(16*l/25), x+(7*l/25),y+(19*l/25),
                                   x+(9*l/25),y+(19*l/25), x+(9*l/25),y+(16*l/25)};
    DrawQuad(VerticesRectangle2);

    GLfloat VerticesRectangle3[]={ x+(10*l/25),y+(16*l/25), x+(10*l/25),y+(19*l/25),
                                   x+(15*l/25),y+(19*l/25), x+(15*l/25),y+(16*l/25)};
    DrawQuad(VerticesRectangle3);

    GLfloat VerticesRectangle4[]={ x+(16*l/25),y+(16*l/25), x+(16*l/25),y+(19*l/25),
                                   x+(18*l/25),y+(19*l/25), x+(18*l/25),y+(16*l/25)};
    DrawQuad(VerticesRectangle4);
}

int Piece::Knight(GLfloat x, GLfloat y, GLfloat l)
{

}

int Piece::Bishop(GLfloat x, GLfloat y, GLfloat l)
{
    GLfloat VerticesRectangle[]={ x+(8*l/25),y+(3*l/25), x+(8*l/25),y+(5*l/25),
                                   x+(17*l/25),y+(5*l/25), x+(17*l/25),y+(3*l/25)};
    DrawQuad(VerticesRectangle);

    GLfloat VerticesRectangle1[]={ x+(8*l/25),y+(5*l/25), x+(10.5*l/25),y+(7*l/25),
                          x+(14.5*l/25),y+(7*l/25), x+(17*l/25),y+(5*l/25)};
    DrawQuad(VerticesRectangle1);

    GLfloat VerticesRectangle2[]={ x+(10.5*l/25),y+(7*l/25), x+(10.5*l/25),y+(15*l/25),
                          x+(14.5*l/25),y+(15*l/25), x+(14.5*l/25),y+(7*l/25)};
    DrawQuad(VerticesRectangle2);

    GLfloat VerticesRectangle3[]={ x+(10.5*l/25),y+(15*l/25), x+(9*l/25),y+(18*l/25),
                          x+(16*l/25),y+(18*l/25), x+(14.5*l/25),y+(15*l/25)};
    DrawQuad(VerticesRectangle3);

    GLfloat VerticesRectangle4[]={ x+(9*l/25),y+(18*l/25), x+(11.5*l/25),y+(21*l/25),
                          x+(13.5*l/25),y+(21*l/25), x+(16*l/25),y+(18*l/25)};
    DrawQuad(VerticesRectangle4);

    DrawCircleFilled(x+(12.5*l/25),y+(22*l/25), 1*l/25, 10);
}

int Piece::King(GLfloat x, GLfloat y, GLfloat l)
{
    GLfloat VerticesRectangle[]={ x+(7*l/25),y+(2*l/25), x+(7*l/25),y+(4*l/25),
                                   x+(18*l/25),y+(4*l/25), x+(18*l/25),y+(2*l/25)};
    DrawQuad(VerticesRectangle);

    GLfloat VerticesRectangle1[]={ x+(8*l/25),y+(4*l/25), x+(11*l/25),y+(11*l/25),
                          x+(14*l/25),y+(11*l/25), x+(17*l/25),y+(4*l/25)};
    DrawQuad(VerticesRectangle1);

    GLfloat VerticesRectangle2[]={ x+(11*l/25),y+(11*l/25), x+(11*l/25),y+(13*l/25),
                          x+(14*l/25),y+(13*l/25), x+(14*l/25),y+(11*l/25)};
    DrawQuad(VerticesRectangle2);

    GLfloat VerticesRectangle3[]={ x+(11*l/25),y+(13*l/25), x+(9*l/25),y+(18*l/25),
                          x+(16*l/25),y+(18*l/25), x+(14*l/25),y+(13*l/25)};
    DrawQuad(VerticesRectangle3);

    GLfloat VerticesRectangle4[]={ x+(10*l/25),y+(20*l/25), x+(10*l/25),y+(21*l/25),
                          x+(15*l/25),y+(21*l/25), x+(15*l/25),y+(20*l/25)};
    DrawQuad(VerticesRectangle4);

    GLfloat VerticesRectangle5[]={ x+(12*l/25),y+(18*l/25), x+(12*l/25),y+(23*l/25),
                          x+(13*l/25),y+(23*l/25), x+(13*l/25),y+(18*l/25)};
    DrawQuad(VerticesRectangle5);
}

int Piece::Queen(GLfloat x, GLfloat y, GLfloat l)
{
    GLfloat VerticesRectangle[]={ x+(7*l/25),y+(2*l/25), x+(7*l/25),y+(4*l/25),
                                  x+(18*l/25),y+(4*l/25), x+(18*l/25),y+(2*l/25)};
    DrawQuad(VerticesRectangle);

    GLfloat VerticesRectangle1[]={ x+(8*l/25),y+(4*l/25), x+(11*l/25),y+(11*l/25),
                                   x+(14*l/25),y+(11*l/25), x+(17*l/25),y+(4*l/25)};
    DrawQuad(VerticesRectangle1);

    GLfloat VerticesRectangle2[]={ x+(11*l/25),y+(11*l/25), x+(11*l/25),y+(13*l/25),
                                   x+(14*l/25),y+(13*l/25), x+(14*l/25),y+(11*l/25)};
    DrawQuad(VerticesRectangle2);

    GLfloat VerticesRectangle3[]={ x+(11*l/25),y+(13*l/25), x+(9*l/25),y+(18*l/25),
                                   x+(16*l/25),y+(18*l/25), x+(14*l/25),y+(13*l/25)};
    DrawQuad(VerticesRectangle3);

    GLfloat VerticesRectangle4[]={ x+(9*l/25),y+(18*l/25), x+(11*l/25),y+(20*l/25),
                                   x+(14*l/25),y+(20*l/25), x+(16*l/25),y+(18*l/25)};
    DrawQuad(VerticesRectangle4);

    DrawCircleFilled(x+(12.5*l/25),y+(21.5*l/25), 1.5*l/25, 10);
}
