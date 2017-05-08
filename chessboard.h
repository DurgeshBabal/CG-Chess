// defines the chess board
// inherets the shapes class to use basic shapes
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <GL/glut.h>

#include "shapes.h"

class ChessBoard :private BasicShapes
{
        // to draw black square
        int BlackSquare(GLfloat *vertices);
        // to draw white square
        int WhiteSquare(GLfloat *vertices);

    public:
        // ChessBoard();
        //
        // ~ChessBoard() = default;
        // ChessBoard(const ChessBoard& other) = default;
        // ChessBoard(ChessBoard&& other) = default;
        // ChessBoard& operator=(const ChessBoard& other) = default;
        // ChessBoard& operator=(ChessBoard&& other) = default;

        int DrawChessBoard(GLfloat x0, GLfloat y0, GLfloat size);
};

#endif
