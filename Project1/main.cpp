#include <GL/glut.h>
#include "play.h"

#define FPS 5
extern short cDirection;

int index = 0;
bool gameOver = false;
int score = 0;

void renderScene(void);
void reshape(int w, int h);
void timer(int);
void enterKey(int,int,int);
void initialize();

int main(int argc, char** argv) {

	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Snake");


	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(reshape);
	glutTimerFunc(0, timer, 0);
	//glutKeyboardFunc();
	glutSpecialFunc(enterKey);
	initialize();

	// GLUT event processing cycle
	glutMainLoop();

	return 0;
}

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawGrid();
	drawSnake();
	drawFood();

	glutSwapBuffers();
	if (gameOver) {
		MessageBox(NULL, TEXT("Your score : "), TEXT("GAME OVER"), 0);
		exit(0);
	}
	
}

void initialize() {
	glClearColor(0, 0, 0, 1.0);
	initGrid(31, 31);
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//set up the projection
	glOrtho(0.0, 31.0, 0, 31.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer, 0);
}

void enterKey(int key, int, int)
{
	if (key == GLUT_KEY_DOWN) {
		if (cDirection != up) {
			cDirection = down;
		}
	}
	else if (key == GLUT_KEY_UP) {
		if (cDirection != down) {
			cDirection = up;
		}
	}
	else if (key == GLUT_KEY_LEFT) {
		if (cDirection != right) {
			cDirection = left;
		}
	}
	else if (key == GLUT_KEY_RIGHT) {
		if (cDirection != left) {
			cDirection = right;
		}
	}
}