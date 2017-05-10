// main.cpp
// headers
#include <iostream>
#include <stdio.h>

// graphics headers
#include <GL/glut.h>

// static headers
#include <math.h>

// custom headers
#include "action.h"
#include "chessboard.h"
#include "gameplay.h"
#include "menu.h"
#include "mouse.h"
#include "move.h"
#include "piece.h"
#include "shapes.h"


// Global definations or System wide configuration
char application_name[]="2D Chess";
int WindowsHeight = 670;
int WindowsWidth = 1024;

int ChessBoardSquareSize = 80;
int xstartcoordinate = 250;
int ystartcoordinate = 10;

GamePlay BoardArray[8][8];

// Objects
Menu MainMenu[5];

// menu array
char MainMenuList[5][20]={"New Game","Save Game","Load Game","About","Exit"};

// menu action array
int MainMenuActionArray[5] = {1, 2, 3, 4, 5};


// board clicks
int FirstClickI, FirstClickJ, SecondClickI, SecondClickJ, WaitingForSecondClick=0;


void MouseInput(int button, int state, int x, int y)
{
    int temp;
    if( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
    {
        if (WaitingForSecondClick == 1) goto boardclick;
        temp = MenuActionMouse(MainMenu, 5, x, WindowsHeight-y);
        printf("x = %d, my = %d, caly = %d \n ", x, y, WindowsHeight-y);
        if (temp > 0)
            MenuAction(temp);

        //  Check for click inside Board
        boardclick:
        if(temp == 0) // not clicked on menu
        {
            // if clicked on the Board
            if( ( x > xstartcoordinate && x < xstartcoordinate+(8*ChessBoardSquareSize) ) && ( y < ystartcoordinate && y > ystartcoordinate+(8*ChessBoardSquareSize) ) )
            {
                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < n; ++j)
                    {
                        /* code */
                    }
                }
                if (WaitingForSecondClick == 0)
                {

                }
            }
        }
    }
}

void display()
{
    // clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // piece display
    Piece TestPiece;

    // BasicShapes testobject;
    // glColor3f(0,1,0);
    // testobject.DrawArcFilled(100,100,90,0,6.3,100);

    DisplayMenu(MainMenu, 5);

    ChessBoard Board;
    Board.DrawChessBoard(250,10,ChessBoardSquareSize);

    // white side
    glColor3f(1,1,1);

    TestPiece.Knight(250,10,ChessBoardSquareSize);
    TestPiece.Knight(250,10+ChessBoardSquareSize,ChessBoardSquareSize);

    // black side
    glColor3f(0,0,0);
    TestPiece.Knight(250+ChessBoardSquareSize,10,ChessBoardSquareSize);
    TestPiece.Knight(250+ChessBoardSquareSize,10+ChessBoardSquareSize,ChessBoardSquareSize);

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

    CreateMenu(MainMenu, MainMenuList, MainMenuActionArray, 5, 50, 650, 40, 100);
    //CreateMainMenu();

    glutDisplayFunc(display);

    // mouse function
    //glfwSetMousePos(WindowsWidth/2, WindowsHeight/2);
    glutMouseFunc(MouseInput);

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
