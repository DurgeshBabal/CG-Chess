// main.cpp
// headers
#include <iostream>
#include <stdio.h>

// graphics headers
#include <GL/glut.h>

// static headers
#include <math.h>

// custom headers
#include "chessboard.h"
#include "menu.h"
#include "piece.h"
#include "shapes.h"


// Global definations or System wide configuration
char application_name[]="2D Chess";
int WindowsHeight = 670;
int WindowsWidth = 1024;
int ChessBoardSquareSize = 80;

void display()
{
    // clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // piece display
    Piece TestPiece;

    // BasicShapes testobject;
    // glColor3f(0,1,0);
    // testobject.DrawArcFilled(100,100,90,0,6.3,100);

    ChessBoard Board;
    Board.DrawChessBoard(250,10,ChessBoardSquareSize);

    // white side
    glColor3f(1,1,1);
    TestPiece.Pawn(250,10,ChessBoardSquareSize);
    TestPiece.Pawn(250,10+ChessBoardSquareSize,ChessBoardSquareSize);

    // black side
    glColor3f(0,0,0);
    TestPiece.Pawn(250+ChessBoardSquareSize,10,ChessBoardSquareSize);
    TestPiece.Pawn(250+ChessBoardSquareSize,10+ChessBoardSquareSize,ChessBoardSquareSize);
    // flush the buffer on the display
    glFlush();
}

// main of the application
int main(int argc, char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(WindowsWidth,WindowsHeight);
    glutInitWindowPosition(0,0);
    glutCreateWindow(application_name);

    CreateMainMenu();

    glutDisplayFunc(display);

    // configuration settings
    glClearColor(0.5,0.5,0.5,0.5);      // set background a grey
    // glColor3f(1,0,0);
    glPointSize(3);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,WindowsWidth,0,WindowsHeight);

    // Main Loop function
    glutMainLoop();
    return 0;
}
