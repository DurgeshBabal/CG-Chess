// fucntions to display text on the screen

#include "text.h"

void DrawBitmapText(char *string,float x,float y)
{
	char *c;
	glRasterPos2f(x, y);

	for (c=string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
	}
}
