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

GamePlay BoardArray[8][8],temp;

// Objects
Menu MainMenu[5];

// menu array
char MainMenuList[5][20]={"New Game","Save Game","Load Game","About","Exit"};

// menu action array
int MainMenuActionArray[5] = {1, 2, 3, 4, 5};

// board clicks
int FirstClickI, FirstClickJ, SecondClickI, SecondClickJ, WaitingForSecondClick=0;
/*
void SaveGame()
{
    FILE *open;
    open = fopen("/savegame/save.bin", "w");
    if(open<0)
    {
        cout<<"\nError in opening the savegame file for writing";
        return;
    }
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            open.write((char*)&BoardArray[i][j],sizeof(BoardArray[i][j]))
        }
    }
    open.close();
}
*/
void MenuAction(int ActionId)
{
    switch(ActionId)
    {
        case 1:Populate(xstartcoordinate, ystartcoordinate, ChessBoardSquareSize, BoardArray, ActionId);
            glutPostRedisplay();
            break;
        //case 2:SaveGame(); break;
        /*case 3:Populate(xstartcoordinate, ystartcoordinate, ChessBoardSquareSize, BoardArray, ActionId);
            glutPostRedisplay();
            break;*/
        case 4:break;
        case 5: exit(0);break;
        default:break;
    }
}

void MouseInput(int button, int state, int x, int y)
{
    int temp = 0;
    if( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
    {
        printf("Click = %d\n", WaitingForSecondClick);
        int clickedY = y;
        y = WindowsHeight-y;
        if (WaitingForSecondClick == 1) goto boardclick;
        temp = MenuActionMouse(MainMenu, 5, x, y);
        printf("x = %d, my = %d, caly = %d \n ", x, y, clickedY);
        if (temp > 0)
            MenuAction(temp);

        //  Check for click inside Board
        boardclick:
        if(temp == 0) // not clicked on menu
        {
            if (0)
            {
                printf("x > xstartcoordinate  = %d \n x < xstartcoordinate+(8*ChessBoardSquareSize) = %d \n y > ystartcoordinate = %d \n y < ystartcoordinate+(8*ChessBoardSquareSize) = %d \n",x > xstartcoordinate, x < xstartcoordinate+(8*ChessBoardSquareSize), y > ystartcoordinate, y < ystartcoordinate+(8*ChessBoardSquareSize) );
                printf("outside menu & going to board\n");
            }

            // if clicked on the Board
            if( ( x > xstartcoordinate && x < xstartcoordinate+(8*ChessBoardSquareSize) ) && ( y > ystartcoordinate && y < ystartcoordinate+(8*ChessBoardSquareSize) ) )
            {
                printf("Clicked on board\n");
                if (WaitingForSecondClick == 1)
                {
                    printf("Waiting For Second Click\n");
                    for (int i = 0; i < 8; ++i)
                    {
                        for (int j = 0; j < 8; ++j)
                        {
                            if (BoardArray[i][j].IsInside(x,y,ChessBoardSquareSize))
                            {
                                SecondClickI = BoardArray[i][j].GetSquareIdX();
                                SecondClickJ = BoardArray[i][j].GetSquareIdY();
                                printf("si = %d sj = %d\n", SecondClickI, SecondClickJ);
                                // put the action here
                                int temparry[] = {FirstClickI, FirstClickJ, SecondClickI, SecondClickJ};
                                int tempMove = Move(temparry, BoardArray);
                                printf("Move = %d\n",tempMove );
                                if (tempMove)
                                {
                                    BoardArray[SecondClickI][SecondClickJ].SetPieceId(BoardArray[FirstClickI][FirstClickJ].GetPieceId());
                                    BoardArray[FirstClickI][FirstClickJ].SetPieceId(0);
                                }
                                // reset the click
                                WaitingForSecondClick = 0;
                                printf("Click changed\n");
                                glutPostRedisplay();
                            }
                        }
                    }
                }
                else if (WaitingForSecondClick == 0)
                {
                    printf("Waiting For First Click\n");
                    for (int i = 0; i < 8; ++i)
                    {
                        for (int j = 0; j < 8; ++j)
                        {
                            if (BoardArray[i][j].IsInside(x,y,ChessBoardSquareSize))
                            {
                                FirstClickI = BoardArray[i][j].GetSquareIdX();
                                FirstClickJ = BoardArray[i][j].GetSquareIdY();
                                printf("fi = %d fj = %d\n", FirstClickI, FirstClickJ);
                                WaitingForSecondClick = 1;
                                glutPostRedisplay();
                            }
                        }
                    }
                }

            }
            else printf("Clicked outside board\n");
        }
    }
}

void printBoardArray()
{
    for (int i = 0; i < 8; i++) {
        for (int j=0; j < 8; j++) {
            printf("SquareIdX: %d ",BoardArray[i][j].GetSquareIdX());
            printf("SquareIdY: %d ",BoardArray[i][j].GetSquareIdY());
            printf("X-coordinate: %d ",BoardArray[i][j].GetX());
            printf("Y-coordinate: %d ",BoardArray[i][j].GetY());
            printf("PieceId: %d \n",BoardArray[i][j].GetPieceId());
        }
    }
}

void generate(Piece PieceGenerate)
{
    int i,j;

    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            switch(BoardArray[i][j].GetPieceId())
            {
                case -6:    glColor3f(0,0,0);
                            PieceGenerate.King(BoardArray[i][j].GetX(), BoardArray[i][j].GetY(), ChessBoardSquareSize);
                            break;
                case -5:    glColor3f(0,0,0);
                            PieceGenerate.Queen(BoardArray[i][j].GetX(), BoardArray[i][j].GetY(), ChessBoardSquareSize);
                            break;
                case -4:    glColor3f(0,0,0);
                            PieceGenerate.Bishop(BoardArray[i][j].GetX(), BoardArray[i][j].GetY(), ChessBoardSquareSize);
                            break;
                case -3:    glColor3f(0,0,0);
                            PieceGenerate.Knight(BoardArray[i][j].GetX(), BoardArray[i][j].GetY(), ChessBoardSquareSize);
                            break;
                case -2:    glColor3f(0,0,0);
                            PieceGenerate.Rook(BoardArray[i][j].GetX(), BoardArray[i][j].GetY(), ChessBoardSquareSize);
                            break;
                case -1:    glColor3f(0,0,0);
                            PieceGenerate.Pawn(BoardArray[i][j].GetX(), BoardArray[i][j].GetY(), ChessBoardSquareSize);
                            break;
                case 1:     glColor3f(1,1,1);
                            PieceGenerate.Pawn(BoardArray[i][j].GetX(), BoardArray[i][j].GetY(), ChessBoardSquareSize);
                            break;
                case 2:     glColor3f(1,1,1);
                            PieceGenerate.Rook(BoardArray[i][j].GetX(), BoardArray[i][j].GetY(), ChessBoardSquareSize);
                            break;
                case 3:     glColor3f(1,1,1);
                            PieceGenerate.Knight(BoardArray[i][j].GetX(), BoardArray[i][j].GetY(), ChessBoardSquareSize);
                            break;
                case 4:     glColor3f(1,1,1);
                            PieceGenerate.Bishop(BoardArray[i][j].GetX(), BoardArray[i][j].GetY(), ChessBoardSquareSize);
                            break;
                case 5:     glColor3f(1,1,1);
                            PieceGenerate.Queen(BoardArray[i][j].GetX(), BoardArray[i][j].GetY(), ChessBoardSquareSize);
                            break;
                case 6:     glColor3f(1,1,1);
                            PieceGenerate.King(BoardArray[i][j].GetX(), BoardArray[i][j].GetY(), ChessBoardSquareSize);
                            break;
            }
        }
    }
}

void display()
{
    // clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    DisplayMenu(MainMenu, 5);

    ChessBoard Board;
    Board.DrawChessBoard(xstartcoordinate,ystartcoordinate,ChessBoardSquareSize);

    //Populate(xstartcoordinate, ystartcoordinate, ChessBoardSquareSize, BoardArray);

    //printBoardArray();

    Piece PieceGenerate;
    generate(PieceGenerate);

    // BasicShapes testobject;
    // glColor3f(0,1,0);
    // testobject.DrawArcFilled(100,100,90,0,6.3,100);
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
