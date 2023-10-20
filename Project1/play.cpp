#include <GL/glut.h>
#include "play.h"
#include <ctime>

int gridX;
int gridY;
int snake_len = 2;
short cDirection = right;
int posX[30] = { 15, 15 };
int posY[30] = { 15, 15 };
bool food = true;
int foodX, foodY;

extern bool gameOver;
extern int score;


void initGrid(int x, int y)
{
	gridX = x;
	gridY = y;
}

void drawGrid() 
{
	for (int i = 1; i < gridX - 1; i++) {
		for (int j = 1; j < gridY - 1; j++) {
			unit(i, j);
		}
	}
}

void unit(int x, int y)
{
	glLineWidth(1.0);
	glColor4f(1, 1, 1, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x + 1, y);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x, y + 1);
	glEnd();

}

void drawSnake() {
	for (int i = snake_len - 1; i > 0; i--) {
		posX[i] = posX[i - 1];
		posY[i] = posY[i - 1];
	}
	if (cDirection == up) {
		posY[0]++;
	}
	else if (cDirection == down) {
		posY[0]--;
	}
	else if (cDirection == left) {
		posX[0]--;
	}else{
		posX[0]++;
	}
	for(int i = 0; i < snake_len; i++)
	{
		if (i == 0) {
			glColor3f(0, 1, 0);
		}
		else {
			glColor3f(0, 0, 1);
		}
		glRectd(posX[i], posY[i], posX[i] + 1, posY[i] + 1);
	}
	gameOver = checkLose();

	if (posX[0] == foodX && posY[0] == foodY) {
		score++;
		snake_len++;
		if (snake_len > max_length) {
			snake_len = max_length;
		}
		food = true;
	}

}

bool checkLose() {
	if (posX[0] == gridX - 1 || posX[0] == 0 || posY[0] == gridY - 1 || posY[0] == 0)return true;
	return false;
}

void drawFood() {
	if (food) {
		getRandomPoint(foodX, foodY);
	}
	food = false;
	glColor3f(1, 0, 0);
	glRectd(foodX, foodY, foodX + 1, foodY + 1);
}

void getRandomPoint(int &x, int &y) {
	//our map width = height
	int upperBound = gridX - 2;
	int lowerBound = 1;
	srand(time(NULL));
	x = lowerBound + rand() % (upperBound - lowerBound);
	y = lowerBound + rand() % (upperBound - lowerBound);
}
