// implementation of the class shapes
#include "shapes.h"
#include <math.h>

// vertices = {x1,y1,x2,y2,x3,y3};
int BasicShapes::DrawTriangle(GLfloat *vertices)
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
int BasicShapes::DrawQuad(GLfloat *vertices)
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

// cx, cy = center x, y coordinates
// r = radius
// num_segments = number of segments it form to complete the circle (more segment better circle)
int BasicShapes::DrawCircle(float cx, float cy, float r, int num_segments)
{
	float theta = 2 * 3.1415926 / float(num_segments);
	float c = cosf(theta);//precalculate the sine and cosine
	float s = sinf(theta);
	float t;

	float x = r;//we start at angle = 0
	float y = 0;

	glBegin(GL_LINE_LOOP);
	for(int ii = 0; ii < num_segments; ii++)
	{
		glVertex2f(x + cx, y + cy);//output vertex

		//apply the rotation matrix
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	}
	glEnd();
    return 1;
}

// cx, cy = center x, y coordinates
// r = radius
// num_segments = number of segments it form to complete the circle (more segment better circle)
int BasicShapes::DrawCircleFilled(float cx, float cy, float r, int num_segments)
{
	float theta = 2 * 3.1415926 / float(num_segments);
	float c = cosf(theta);//precalculate the sine and cosine
	float s = sinf(theta);
	float t;

	float x = r;//we start at angle = 0
	float y = 0;

	glBegin(GL_POLYGON);
	for(int ii = 0; ii < num_segments; ii++)
	{
		glVertex2f(x + cx, y + cy);//output vertex

		//apply the rotation matrix
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	}
	glEnd();
    return 1;
}

// cx, cy = center x, y coordinates
// r = radius
// start_angle =  starting angle
// arc_angle = total angle for the arch 
// num_segments = number of segments it form to complete the circle (more segment better circle)
int BasicShapes::DrawArc(float cx, float cy, float r, float start_angle, float arc_angle, int num_segments)
{
	float theta = arc_angle / float(num_segments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open

	float tangetial_factor = tanf(theta);

	float radial_factor = cosf(theta);


	float x = r * cosf(start_angle); //we now start at the start angle
	float y = r * sinf(start_angle);

	glBegin(GL_LINE_STRIP); //since the arc is not a closed curve, this is a strip now
	for(int ii = 0; ii < num_segments; ii++)
	{
		glVertex2f(x + cx, y + cy);

		float tx = -y;
		float ty = x;

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;

		x *= radial_factor;
		y *= radial_factor;
	}
	glEnd();
    return 1;
}
