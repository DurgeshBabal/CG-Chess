// defines the primitive shapes
#ifndef SHAPES_H
#define SHAPES_H

#include <GL/glut.h>

class shapes
{
    public:
        // contructors and destructors
        //shapes();
        // ~shapes() = default;
        // shapes(const shapes& other) = default;
        // shapes(shapes&& other) = default;
        // shapes& operator=(const shapes& other) = default;
        // shapes& operator=(shapes&& other) = default;

        // custom function
        // vertices = {x1,y1,x2,y2,x3,y3}
        int triangle(GLfloat *vertices);
        // vertices = {x1,y1,x2,y2,x3,y3,x4,y4}
        int polygon(GLfloat *vertices);


};

#endif
