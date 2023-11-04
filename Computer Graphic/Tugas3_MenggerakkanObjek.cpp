#include <GL/glut.h>

void init() {
    // Set display window color to as glClearColor(R,G,B,Alpha)
    glClearColor(0.4, 0.4, 0.9, 0.0);
    // Set projection parameters.
    glMatrixMode(GL_PROJECTION);
    // Set 2D Transformation as gluOrtho2D(Min Width, Max Width, Min Height, Max Height)
    gluOrtho2D(0.0, 800, 0.0, 600);
}
void home() {
    //Roof
    glClear(GL_COLOR_BUFFER_BIT);     // Clear display window
    // Set line segment color as glColor3f(R,G,B)
    
    // line of bird 1
    glColor3f(0.3, 0.3, 0.3);
    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glVertex2i(200, 480);
    glVertex2i(220, 500);
    glVertex2i(230, 490);
    glVertex2i(240, 500);
    glVertex2i(260, 480);
    glEnd();
    // Process all OpenGL routine s as quickly as possible
    glFlush();
} 
void keyboard(unsigned char key, int x, int y) {
    /* kontrol tombol pada keyboard:
        "a" : kiri
        "d" : kanan
        "w" : atas
        "s" : bawah
        "q" : perbesar
        "e" : perkecil
    */
    switch (key) {
        case 'a' :
        case 'A' :
            glTranslatef(-5.0, 0.0, 0.0);
            break;

        case 'd' :
        case 'D' :
            glTranslatef(5.0, 0.0, 0.0);
            break;

        case 'w' :
        case 'W' :
            glTranslatef(0.0, 5.0, 0.0);
            break;
        
        case 's' :
        case 'S' :
            glTranslatef(0.0, -5.0, 0.0);
            break;
        
        case 'q' :
        case 'Q' :
            glScalef(1.1f, 1.1f, 0.f);
            break;

        case 'e' :
        case 'E' :
            glScalef(.9f, .9f, 0.f);
            break;
    }
    home();
}
int main(int argc, char ** argv) {

    // Initialize GLUT
    glutInit(&argc, argv);
    // Set display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Set top - left display window position.
    glutInitWindowPosition(100, 100);
    // Set display window width and height
    glutInitWindowSize(720, 480);
    // Create display window with the given title
    glutCreateWindow("Grafkom GT ");
    // Execute initialization procedure
    init();
    // Send graphics to display window
    glutDisplayFunc(home);
    // Display everything and wait.
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    
    return 0;
}