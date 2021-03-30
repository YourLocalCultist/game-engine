#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include "game.cpp"

void gameLoop();
void reshape(int,int);
void timer(int);
Game game;

void init()
{
    glClearColor(0.1,0.4,0.1,1);
}

int main(int argc, char**argv)
{
    printf("Hello World!\n\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    //glutInitWindowPosition(300, 300);
    glutInitWindowSize(480, 300);

    glutCreateWindow("Game Engine");

    glutDisplayFunc(gameLoop);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);

    init();
    game.init();

    glutMainLoop();
}

void gameLoop() //Main game loop, i think
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    game.update();
    //draw
    /*glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2i(5,5);
    glEnd();*/

    glutSwapBuffers();
}

void reshape(int w, int h)//Resize window handler
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,w/4,0,w/4);
    glMatrixMode(GL_MODELVIEW);

}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
}
