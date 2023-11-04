#include <Windows.h>
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/glu.h>
#include <iostream>

#define FROM_RIGHT      1 
#define FROM_LEFT       2 
#define FROM_TOP        3 
#define FROM_BOTTOM     4 

static int WINDOW_WIDTH, WINDOW_HEIGHT;

int playerResult = 0, playerMiss = 0, speed = 1;
static float Xspeed = 3, Yspeed = 3;
static float delta = 3;

char string[100];

struct RECTANGLE {
	float left, top, right, bottom;
};

RECTANGLE ball = { 100,100,120,120 };
RECTANGLE wall;
RECTANGLE player_1 = { 0,490,40,500 };

void DrawRectangle(RECTANGLE  rect) {
	glBegin(GL_QUADS);
	glVertex2f(rect.left, rect.bottom);     
	glVertex2f(rect.right, rect.bottom);
	glVertex2f(rect.right, rect.top);
	glVertex2f(rect.left, rect.top);
	glEnd();
}

// Bola bergerak sesuai waktu
void Timer(int v) {
	ball.left += Xspeed;
	ball.right += Xspeed;
	ball.top += Yspeed;
	ball.bottom += Yspeed;
	glutTimerFunc(speed, Timer, 1); 
}

// For Drawing text inside window
void DrawText(char*string, int x, int y) {
	char *c;
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(0.1, -0.1, 1);

	for (c = string; *c != '\0'; c++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
	}
	glPopMatrix();
}

int BallTouchingWalls(RECTANGLE ball, RECTANGLE wall) {
	if(ball.right >= wall.right)
		return FROM_RIGHT;
	if(ball.left <= wall.left)
		return FROM_LEFT;
	if(ball.top <= wall.top)
		return FROM_TOP;
	if(ball.bottom >= wall.bottom)
		return FROM_BOTTOM;

	else return 0;
}

bool BallTouchingPlayer(RECTANGLE ball, RECTANGLE player) {
	if(ball.bottom >= player.top && ball.left >= player.left && ball.right <= player.right) {
		playerResult++;
		return true;
	}
	return false;
}

// Key Board Messages 
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		exit(0);
		break;
	}
}

//Key Board Message 
void inputKey(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		break;
	case GLUT_KEY_RIGHT:
		break;
	case GLUT_KEY_UP:
		break;
	case GLUT_KEY_DOWN:
		break;
	}
}

//Key Board Message 
void upkey(int key, int x, int y) {
	switch (key) { }
}

// Mouse x position
static int mouse_x = 0;
void MouseMotion(int x, int y) { mouse_x = x; }

// OpenGL Setting
void Setting(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

// OnWindowResize 
void reshape(int w, int h) {
	WINDOW_WIDTH = w;
	WINDOW_HEIGHT = h;
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, h, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Render() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	sprintf(string, "Miss : %d ", playerMiss); 
	DrawText(string, 10, 80); 
	sprintf(string, "Success : %d ", playerResult);
	DrawText(string, 10, 120);
	
	// Wall adjustment
	wall.left = wall.top = 0;
	wall.right = WINDOW_WIDTH;
	wall.bottom = WINDOW_HEIGHT;

	DrawRectangle(ball);

	if(BallTouchingWalls(ball, wall) == FROM_RIGHT)
		Xspeed = -delta;

	if(BallTouchingWalls(ball, wall) == FROM_LEFT)
		Xspeed = delta;

	if(BallTouchingWalls(ball, wall) == FROM_TOP)
		Yspeed = delta;

	if(BallTouchingWalls(ball, wall) == FROM_BOTTOM) {
		Yspeed = -delta;
		playerMiss += 1;
	}

	DrawRectangle(player_1);
	player_1.left = mouse_x - 40;
	player_1.right = mouse_x + 40;

	if (BallTouchingPlayer(ball, player_1) == true)
		Yspeed = -delta;

	if(playerResult == 10 || playerMiss == 5) {
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();

		sprintf(string, "Player %s The Match!", (playerMiss == 5) ? "Losing" : "Winning"); 
		DrawText(string, 90, 200); 
		
		sprintf(string, "Match Ended!, Press Escape to close");
		DrawText(string, 90, 240);
	}
	glutSwapBuffers();
}


int main(int argc, char** argv) {
	// Initialize
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 500);
	glutInitWindowPosition(0, 0);

	// Create window
	glutCreateWindow("Tugas Akhir Komgraf");
	Setting();
	glutDisplayFunc(Render);
	glutIdleFunc(Render);
	glutTimerFunc(1, Timer, 1);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(inputKey);
	glutPassiveMotionFunc(MouseMotion);
	glutMainLoop();
	return 0;
}