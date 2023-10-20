#ifndef PLAY_H_INCLUDED
#define PLAY_H_INCLUDED

int const up = 1;
int const down = -1;
int const right = 2;
int const left = -2;
int const max_length = 30;

void initGrid(int x, int y);

void drawGrid();

void unit(int x, int y);

void drawSnake();
bool checkLose();
void drawFood();

void getRandomPoint(int& x, int& y);

#endif 

