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

        int Pawn(GLfloat x, GLfloat y, GLfloat l);

};

#endif
