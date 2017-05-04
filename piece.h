// defines the Pieces used in chess
#ifndef PIECE_H
#define PIECE_H

#include "shapes.h"
#include <GL/glut.h>

class Piece :private BasicShapes
{
    public:
        // Piece();
        //
        // ~Piece() = default;
        // Piece(const Piece& other) = default;
        // Piece(Piece&& other) = default;
        // Piece& operator=(const Piece& other) = default;
        // Piece& operator=(Piece&& other) = default;

        // to render Pawn
        int Pawn(GLfloat x, GLfloat y, GLfloat l);

        // to render Rook
        int Rook(GLfloat x, GLfloat y, GLfloat l);

        // to render Knight
        int Knight(GLfloat x, GLfloat y, GLfloat l);

        // to render Bishop
        int Bishop(GLfloat x, GLfloat y, GLfloat l);

        // to render King
        int King(GLfloat x, GLfloat y, GLfloat l);

        // to render queen
        int Queen(GLfloat x, GLfloat y, GLfloat l);

};

#endif
