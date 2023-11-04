#include <GL/glut.h> //Menyesuaikan

static int pundak = 0, siku = 0, jari_telunjuk = 0, jari_telunjuk_depan = 0, jari_telunjuk_bawah = 0, jari_telunjuk_bawah_depan = 0;
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(-3.0, 0.0, 0.0);

    glRotatef((GLfloat)pundak, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(1.0, 0.0, 0.0);

    glRotatef((GLfloat)siku, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    glRotatef(45, 0.0, 0.0, 1.0);
    glRotatef((GLfloat)jari_telunjuk, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.15, -0.5);
    glPushMatrix();
    glScalef(0.8, 0.2, 0.5);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0);
    glRotatef(-45, 0.0, 0.0, 1.0);
    glRotatef((GLfloat)jari_telunjuk_depan, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, -0.5);
    glPushMatrix();
    glScalef(0.8, 0.2, 0.5);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-45, 0.0, 0.0, 1.0);
    glRotatef((GLfloat)jari_telunjuk_bawah, 0.0, 0.0, 1.0);
    glTranslatef(0.5, -0.15, -0.5);
    glPushMatrix();
    glScalef(0.8, 0.2, 0.5);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0);
    glRotatef(45, 0.0, 0.0, 1.0);
    glRotatef((GLfloat)jari_telunjuk_bawah_depan, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, -0.5);
    glPushMatrix();
    glScalef(0.8, 0.2, 0.5);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':
        pundak = (pundak + 5) % 360;
        glutPostRedisplay();
        break;
    case 'd':
        pundak = (pundak - 5) % 360;
        glutPostRedisplay();
        break;
    case 'w':
        if (siku < 150)
            siku = (siku + 5) % 360;
        glutPostRedisplay();
        break;

    case 'e':
        if (siku > 0)
            siku = (siku - 5) % 360;
        glutPostRedisplay();
        break;

    case 'i':
        if (jari_telunjuk < 45)
            jari_telunjuk = (jari_telunjuk + 5) % 360;
        glutPostRedisplay();
        break;

    case 'I':
        if (jari_telunjuk > -45)
            jari_telunjuk = (jari_telunjuk - 5) % 360;
        glutPostRedisplay();
        break;

    case 'o':
        if (jari_telunjuk_depan < 45)
            jari_telunjuk_depan = (jari_telunjuk_depan - 5) % 360;
        glutPostRedisplay();
        break;

    case 'O':
        if (jari_telunjuk_depan > -45)
            jari_telunjuk_depan = (jari_telunjuk_depan + 5) % 360;
        glutPostRedisplay();
        break;

    case 'k':
        if (jari_telunjuk_bawah < 45)
            jari_telunjuk_bawah = (jari_telunjuk_bawah - 5) % 360;
        glutPostRedisplay();
        break;

    case 'K':
        if (jari_telunjuk_bawah > -45)
            jari_telunjuk_bawah = (jari_telunjuk_bawah + 5) % 360;
        glutPostRedisplay();
        break;

    case 'l':
        jari_telunjuk_bawah_depan = (jari_telunjuk_bawah_depan + 5) % 360;
        glutPostRedisplay();
        break;

    case 'L':
        jari_telunjuk_bawah_depan = (jari_telunjuk_bawah_depan - 5) % 360;
        glutPostRedisplay();
        break;

    default:
        break;
    }
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}