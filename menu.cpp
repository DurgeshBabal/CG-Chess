// source for menu functions

#include "menu.h"

Menu::Menu()
{
    strcpy(Name, "Menu item");
    x = 100;
    y = 100;
    h = 40;
    w = 100;
    FontSize = 14;
    strcpy(FontFamily, "GLUT_BITMAP_HELVETICA_");
    ActionId = 0;
}

int Menu::IsInside(int MouseX, int MouseY)
{
    if( ( MouseX > x && MouseX < x+w ) && ( MouseY < y && MouseY > y-h ) )
        return ActionId;
    return 0;
}

int Menu::AddName(char TempName[])
{
    strcpy(Name, TempName);

    // operation sucessfull so return true
    return 1;
}

int Menu::AddCoordinates(GLfloat tx, GLfloat ty, GLfloat th, GLfloat tw)
{
    x = tx;
    y = ty;
    h = th;
    w = tw;

    // operation sucessfull so return true
    return 1;
}

int Menu::AddActioId(int TempActionId)
{
    ActionId = TempActionId;

    // operation sucessfull so return true
}

void Menu::DisplayMenuElement()
{
    BasicShapes ShapesObjects;

    GLfloat Placeholder[] = {x,y, x+w,y, x+w,y-(h-h/10), x,y-(h-h/10)};

    glColor3f(1,0,0);
    ShapesObjects.DrawQuad(Placeholder);

    glColor3f(1,1,1);
    DrawBitmapText(Name, x+(w/10), y-(h/2));

}

void DisplayMenu(Menu *MenuObject, int size)
{
    for (int i=0; i < size ; ++i)
    {
        MenuObject[i].DisplayMenuElement();
    }
}

void CreateMenu(Menu *MenuObject, char (*MenuElementList)[20], int *ActionList, int size, GLfloat tx, GLfloat ty, GLfloat Height, GLfloat Width)
{
    GLfloat tempX = tx, tempY = ty;
    for (int i=0; i < size ; ++i)
    {
        MenuObject[i].AddName(MenuElementList[i]);
        MenuObject[i].AddCoordinates(tempX, tempY, Height, Width);
        MenuObject[i].AddActioId(ActionList[i]);
        tempY = tempY - Height;
    }
}
