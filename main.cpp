// main.cpp
// headers
#include <iostream>
#include <stdio.h>

// graphics headers
#include <GL/glut.h>

// static headers
#include <math.h>

// custom headers
#include "shapes.h"

// Global definations
char application_name[]="2D Chess";

void display()
{
    // clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    shapes testshape;

    // GLfloat trianglevertices[]={100,100,300,100,200,400};
    // glColor3f(1,0,0);
    // testshape.triangle(trianglevertices);

    GLfloat squarevertices[]={100,100,400,100,400,400,100,400};
    glColor3f(1,0,0);
    testshape.polygon(squarevertices);

    //GLfloat v[3][2]={{100,100},{300,100},{200,400}};

    //testshape.square(trianglevertices);

    // flush the buffer on the display
    glFlush();
}

// main of the application
int main(int argc, char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow(application_name);
    glutDisplayFunc(display);

    // configuration settings
    glClearColor(0.5,0.5,0.5,0.5);      // set background a grey
    // glColor3f(1,0,0);
    glPointSize(3);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);

    // Main Loop function
    glutMainLoop();
    return 0;
}
