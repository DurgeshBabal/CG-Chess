// defines the primitive shapes
#ifndef SHAPES_H
#define SHAPES_H

#include <GL/glut.h>

class shapes
{
        int x,y;    // mid point coordinates
    public:
        // contructors and destructors
        shapes();
        // ~shapes() = default;
        // shapes(const shapes& other) = default;
        // shapes(shapes&& other) = default;
        // shapes& operator=(const shapes& other) = default;
        // shapes& operator=(shapes&& other) = default;

        // custom function
        int triange(GLfloat *vertices);
};

#endif
