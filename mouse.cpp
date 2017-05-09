// definations mouse functions

#include "mouse.h"

int MenuActionMouse(Menu *MenuObject, int size, int x, int y)
{
    int TempActionId = 0;
    for (int i = 0; i < size; ++i)
    {
        TempActionId = MenuObject[i].IsInside(x,y);
        if (TempActionId > 0)
            return TempActionId;
    }
    return 0;
}
