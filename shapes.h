// defines the primitive shapes
#ifndef SHAPES_H
#define SHAPES_H

#include <GL/glut.h>

class BasicShapes
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
        int DrawTriangle(GLfloat *vertices);

        // vertices = {x1,y1,x2,y2,x3,y3,x4,y4}
        int DrawQuad(GLfloat *vertices);

        // cx, cy = center x, y coordinates
        // r = radius
        // num_segments = number of segments it form to complete the circle (more segment better circle)
        int DrawCircle(float cx, float cy, float r, int num_segments);

        // cx, cy = center x, y coordinates
        // r = radius
        // num_segments = number of segments it form to complete the circle (more segment better circle)
        int DrawCircleFilled(float cx, float cy, float r, int num_segments);

        // cx, cy = center x, y coordinates
        // r = radius
        // start_angle =  starting angle
        // arc_angle = total angle for the arch
        // num_segments = number of segments it form to complete the circle (more segment better circle)
        int DrawArc(float cx, float cy, float r, float start_angle, float arc_angle, int num_segments);

};

#endif
