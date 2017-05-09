// header for menu functions, Its not a class
#ifndef MENU_H
#define MENU_H

#include <GL/glut.h>
#include <stdlib.h>
#include <string.h>

#include "shapes.h"
#include "text.h"

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
        GLfloat h;
        GLfloat w;
        int FontSize;
        char FontFamily[30];
        int ActionId;
    protected:

    public:
        Menu();
        //
        // ~Menu() = default;
        // Menu(const Menu& other) = default;
        // Menu(Menu&& other) = default;
        // Menu& operator=(const Menu& other) = default;
        // Menu& operator=(Menu&& other) = default;

        // if the mouse clicked inside the menu then this function return ActionId else 0
        int IsInside(int MouseX, int MouseY);

        // to Add the Name with the font size and the font family, can be used to override if needed
        int AddName(char TempName[], int TempFontSize = 14, char TempFontFamily[] = "GLUT_BITMAP_HELVETICA_")

        // to add the coordnates (top left coordinate), can be use to override the previous / default value
        int AddCoordinates(GLfloat tx, GLfloat ty, GLfloat th = 40, GLfloat tw = 100);

        // to add action id to the object, can be used to override the the action if needed
        int AddActioId(int TempActionId);

        // function to generate the menu element
        void DisplayMenuElement();

};

// Function to display menu
void DisplayMenu(Menu *MenuObject);

// Function to create menu
void CreateMenu(Menu *MenuObject, char **MenuElementList, int ActionList, GLfloat tx, GLfloat ty, GLfloat Height, GLfloat Width);

#endif
