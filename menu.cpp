// source for menu functions

void MainMenu()
{
    glutCreateMenu(MainMenu);
        glutAddMenuEntry("New Game", 1);
        glutAddMenuEntry("Exit", 2);
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
}
