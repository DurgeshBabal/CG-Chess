// source for menu functions

#include "menu.h"

int Menu::IsInside(int MouseX, int MouseY)
{
    if(MouseX>x && MouseX<x+l)

}

int Menu::AddName(char TempName[], int TempFontSize, char TempFontFamily[])
{
    strcpy(TempName, Name);
    FontSize = TempFontSize;
    strcpy(TempFontFamily, FontFamily);

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
