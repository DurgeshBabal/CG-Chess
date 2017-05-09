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

int Menu::AddName(char TempName[], int TempFontSize = 14, char TempFontFamily[] = "GLUT_BITMAP_HELVETICA_")
{
    strcpy(Name, TempName);
    FontSize = TempFontSize;
    strcpy(FontFamily, TempFontFamily);

    // operation sucessfull so return true
    return 1;
}

int Menu::AddCoordinates(GLfloat tx, GLfloat ty, GLfloat th = 40, GLfloat tw = 100)
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

    GLfloat Placeholder[] = {x,y, x+w,y, x+w,y-h, x,y-h};

    glColor3f(1,0,0);
    ShapesObjects.DrawQuad(Placeholder);

    glColor3f(0,0,1);
    DrawBitmapText(Name, x+(w/10), y-(h/2));

}

void DisplayMenu(Menu *MenuObject)
{
    for(auto MenuElement : MenuObject)
    {
        MenuElement.DisplayMenuElement()
    }
}

void CreateMenu(Menu *MenuObject, char **MenuElementList, int ActionList, GLfloat tx, GLfloat ty, GLfloat Height, GLfloat Width)
{
    int i = 0;
    GLfloat tempX = tx, tempY = ty;
    for (auto MenuElement : MenuElementList)
    {
        MenuObject[i].AddName(MenuElement);
        MenuObject[i].AddCoordinates(tempX, tempY, Height, Width);
        MenuObject[i].AddActioId(ActionList[i]);
        tempY = tempY - Height;
    }
}
