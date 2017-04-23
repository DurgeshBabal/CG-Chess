// source for menu functions

#include "menu.h"

void CreateMainMenu()
{
    glutCreateMenu(MainMenu);
        glutAddMenuEntry("New Game", 1);
        glutAddMenuEntry("Exit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void MainMenu(int id)
{
    switch (id)
    {
        case 0: exit(0); break; // exit the game
            break;
        case 2:  // clear board
        default: break;
    }
    glutPostRedisplay();
}
