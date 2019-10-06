#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int x, y;
float i, j;

void myInit (void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(2.0);
    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(-780, 780, -420, 420);
}

void display (void)
{

    for (j = 0; j < 1000; j += 0.025)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);

        for (i = 0;i < 10;i += 0.001)
        {
            x = 200 * cos(i);
            y = 200 * sin(i);
            glVertex2i(x+j, y);
        }
        glEnd();
        glFlush();
    }
}

int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1360, 768);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Circle");

    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
}
