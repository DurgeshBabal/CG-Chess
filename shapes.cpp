// implementation of the class shapess
#include "shapes.h"

/*
    tmatrix = {x1,y1,x2,y2,x3,y3};
*/
shapes::triange(GLfloat *vertices)
{
    // activate and specify pointer to vertex array
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    // draw a triangle
    glDrawArrays(GL_TRIANGLES, 0, 1);
    // deactivate vertex arrays after drawing
    glDisableClientState(GL_VERTEX_ARRAY);
}
