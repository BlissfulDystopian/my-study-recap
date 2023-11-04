#include <stdio.h>
#include <GL/glut.h>
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);   
    glBegin(GL_LINES);
    glVertex3f(3.0, 3.0, 0.0); // sisi kiri
    glVertex3f(7.0, 3.0, 0.0);

    glVertex3f(7.0, 3.0, 0.0); // sisi atas
    glVertex3f(7.0, 7.0, 0.0);

    glVertex3f(7.0, 7.0, 0.0); // sisi kanan
    glVertex3f(3.0, 7.0, 0.0);

    glVertex3f(3.0, 7.0, 0.0); // sisi bawah
    glVertex3f(3.0, 3.0, 0.0);

    glVertex3f(3.0, 3.0, 0.0);
    glVertex3f(7.0, 7.0, 0.0);

    glVertex3f(3.0, 7.0, 0.0);
    glVertex3f(7.0, 3.0, 0.0);

    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    printf("hello world\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(300, 300);
    glutCreateWindow("square with x in the middle");

    glClearColor(1.0, 1.0, 1.0, 0.0);         // black background
    glMatrixMode(GL_PROJECTION);              // setup viewing projection
    glLoadIdentity();                         // start with identity matrix
    glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0); // setup a 10x10x2 viewing world

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}