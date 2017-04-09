// main.cpp

// headers
#include <stdio.h>

// graphics headers
#include <GL/glut.h>

// static headers
#include <math.h>

// custom class headers

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glFlush();
}

void myinit()
{
  glClearColor(1,1,1,1);
  glColor3f(1,0,0);
  glPointSize(3);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,500,0,500);
}

// main of the application
int main(int argc, char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Chess");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
