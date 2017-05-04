// header for menu functions, Its not a class
#ifndef MENU_H
#define MENU_H

#include <GL/glut.h>
#include <stdlib.h>

/*
    Name = Name of the Entry
    x, y = starting coordinate of the menu entry (top left corner)
    l = height of the menu Entry
    FontSize = Font size of the menu
    FontFamily = Font Family of the menu
    ActionId = Action id which need to be triggred if the mouse clicked on this option
*/

class Menu
{
        char Name[20];
        GLfloat x;
        GLfloat y;
        GLfloat l;
        int FontSize;
        char FontFamily[30];
        int ActionId;
    public:
        // Menu();
        //
        // ~Menu() = default;
        // Menu(const Menu& other) = default;
        // Menu(Menu&& other) = default;
        // Menu& operator=(const Menu& other) = default;
        // Menu& operator=(Menu&& other) = default;

        // if the mouse clicked inside the menu then this function return ActionId else 0
        int IsInside(int x, int y);

        // to Add the Name with the font size and the font family, can be used to override if needed
        int AddName(char TempName[], int TempFontSize, char TempFontFamily[]);

        // to add the coordnates (top left coordinate), can be use to override the previous value
        int AddCoordinates(GLfloat tx, GLfloat ty, GLfloat tl);

        // to add action id to the object, can be used to override the the action if needed
        int AddActioId(int TempActionId);

};

// to generate the menu
//  MenuName[] = Name of the menu
//  x,y = the start coordnates of the menu
//  n = number of the items it contains

// to handle main menu function calls

#endif
