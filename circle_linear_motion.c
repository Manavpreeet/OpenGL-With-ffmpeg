#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

const char* cmd = "ffmpeg -r 60 -f rawvideo -pix_fmt rgba -s 1280x720 -i - "
                  "-threads 0 -preset fast -y -pix_fmt yuv420p -crf 21 -vf vflip output.mp4";

FILE* ffmpeg;

int* buffer ;

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

    for (j = 0; j < 1000; j += 0.125)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);

        for (i = 0;i < 10;i += 0.001)
        {


            x = 200 * cos(i);
            y = 200 * sin(i);
            glVertex2i(x+j, y);


        }
        glutSwapBuffers();
        glReadPixels(0, 0, 800, 600, GL_RGBA, GL_UNSIGNED_BYTE, buffer);

        fwrite(buffer, sizeof(int)*1280*720, 1, ffmpeg);

        glEnd();
        glFlush();
    }
}

int main (int argc, char** argv)
{
    buffer = (int*)malloc(800*600 * sizeof(int));
    ffmpeg =  popen(cmd, "w");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Circle");

    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    pclose(ffmpeg);
}
