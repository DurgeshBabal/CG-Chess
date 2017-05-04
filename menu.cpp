// source for menu functions

#include "menu.h"

int Menu::IsInside(int MouseX, int MouseY)
{
    if( ( MouseX > x && MouseX < x+l ) && ( MouseY < y && MouseY > y-l ) )
        return ActionId;
    return 0;
}

int Menu::AddName(char TempName[], int TempFontSize, char TempFontFamily[])
{
    strcpy(Name, TempName);
    FontSize = TempFontSize;
    strcpy(FontFamily, TempFontFamily);

    // operation sucessfull so return true
    return 1;
}

int Menu::AddCoordinates(GLfloat tx, GLfloat ty, GLfloat tl)
{
    x = tx;
    y = ty;
    l = tl;

    // operation sucessfull so return true
    return 1;
}

int Menu::AddActioId(int TempActionId)
{
    ActionId = TempActionId;

    // operation sucessfull so return true
}
