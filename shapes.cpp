// implementation of the class shapes
#include "shapes.h"

// vertices = {x1,y1,x2,y2,x3,y3};
int shapes::triangle(GLfloat *vertices)
{
    // glColor3f(1,1,0);
    // activate and specify pointer to vertex array
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, indices);
    // draw a triangle
    glDrawArrays(GL_TRIANGLES, 0, 3);
    // deactivate vertex arrays after drawing
    glDisableClientState(GL_VERTEX_ARRAY);
    return 1;       // sucessful
}

// vertices = {x1,y1,x2,y2,x3,y3,x4,y4};
int shapes::polygon(GLfloat *vertices)
{
    // activate and specify pointer to vertex array
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    // draw a polygon
    glDrawArrays(GL_QUADS, 0, 4);
    // deactivate vertex arrays after drawing
    glDisableClientState(GL_VERTEX_ARRAY);

    return 1;       // sucessful
}
