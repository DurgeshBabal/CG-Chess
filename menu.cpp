// source for menu functions

#include "menu.h"

void CreateMainMenu()
{
    glutCreateMenu(MainMenu);
        glutAddMenuEntry("New Game", 1);
        glutAddMenuEntry("Exit", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void MainMenu(int id)
{
    switch (id)
    {
        case 1: // clear board
            break;
        case 2: exit(0); break; // exit the game
        default: break;
    }
    glutPostRedisplay();
}
