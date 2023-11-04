#include <stdio.h>
#include <GL/glut.h>
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.f, 1.f, 1.f);
    glBegin(GL_POLYGON);
    glVertex2f(2.f, 4.f);
    glVertex2f(2.f, 6.f);
    glVertex2f(4.f, 7.f);
    glVertex2f(6.f, 6.f);
    glVertex2f(6.f, 4.f);
    glVertex2f(4.f, 3.f);
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(2.0, 4.0); // sisi kiri
    glVertex2f(2.0, 6.0);

    glVertex2f(2.0, 6.0); // sisi kiri atas
    glVertex2f(4.0, 7.0);

    glVertex2f(4.0, 7.0); // sisi kanan atas
    glVertex2f(6.0, 6.0);

    glVertex2f(6.0, 6.0); // sisi kanan
    glVertex2f(6.0, 4.0);

    glVertex2f(6.0, 4.0); // atas kanan
    glVertex2f(4.0, 3.0);

    glVertex2f(4.0, 3.0); // kiri bawah
    glVertex2f(2.0, 4.0);

    glVertex2f(4.0, 7.0); // atas ke bawah
    glVertex2f(4.0, 3.0);

    glVertex2f(6.0, 6.0); // kanan atas kiri bawah
    glVertex2f(2.0, 4.0);

    glVertex2f(2.0, 6.0); // atas kiri ke bawah kanan
    glVertex2f(6.0, 4.0);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    printf("hello world\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Polygon");

    glClearColor(0.3, 0.6, 0.2, 0.0);         // black background
    glMatrixMode(GL_PROJECTION);              // setup viewing projection
    glLoadIdentity();                         // start with identity matrix
    glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0); // setup a 10x10x2 viewing world

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}