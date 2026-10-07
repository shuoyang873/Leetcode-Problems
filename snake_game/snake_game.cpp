#include<iostream>
#include<conio.h>
#include<cstdio>
#include<windows.h>
#include<ctime>
#include<cstdlib>
using namespace std;

const int width = 30;
const int height = 20;
int ntail;
int headx, heady;
int tailx[100], taily[100];
int fruitx, fruity;
int score;
enum Direction{STOP=0,UP,DOWN,LEFT,RIGHT};
Direction dir;

void init() {
	srand(time(0));
	headx = width / 2;
	heady = height / 2;
	fruitx = rand() % width;
	fruity = rand() % height;
	ntail = 0;
	score = 0;
	dir = STOP;
}

void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':dir = LEFT; break;
		case'w':dir = UP; break;
		case'd':dir = RIGHT; break;
		case's':dir = DOWN; break;
		case'x':exit(0); break;
		}
	}
}

void draw() {
	system("cls");
	for (int i = 0; i < width + 2; i++) {
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width + 2; j++) {
			if (j == 0) {
				cout << "#";
			}
			else if (j == width + 1) {
				cout << "#";
			}
			else if (headx == j && heady == i) {
				cout << "O";
			}
			else if (fruitx == j && fruity == i) {
				cout << "F";
			}
			else {
				bool print = false;
				for (int k = 0; k < ntail; k++) {
					if (tailx[k] == j && taily[k] == i) {
						cout << "o";
						print = true;
					}
				}
				if (!print)cout << " ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++) {
		cout << "#";
	}
	cout << endl;
	cout << "score:" << score << endl;
	return;
}

void logic() {
	int prevx, prevy;
	prevx = headx;
	prevy = heady;

	switch (dir) {
	case UP:heady--; break;
	case LEFT:headx--; break;
	case RIGHT:headx++; break;
	case DOWN:heady++; break;
	default:break;
	}

	if (ntail > 0) {
		for (int i = ntail-1; i > 0; i--) {
			tailx[i] = tailx[i - 1];
			taily[i] = taily[i - 1];
		}
		tailx[0] = prevx;
		taily[0] = prevy;
	}

	if (headx < 0 || headx >= width || heady < 0 || heady >= height) {
		exit(0);
	}

	for (int i = 0; i < ntail; i++) {
		if (headx == tailx[i] && heady == taily[i]) {
			exit(0);
		}
	}

	if (headx == fruitx && heady == fruity) {
		score += 10;
		if (ntail > 0) {
			tailx[ntail] = tailx[ntail - 1];
			taily[ntail] = taily[ntail - 1];
		}
		else {
			tailx[0] = prevx;
			taily[0] = prevy;
		}
		ntail++;
		fruitx = rand() % width;
		fruity = rand() % height;
	}
}

int main() {
	init();
	while (true) {
		draw();
		Input();
		logic();
		Sleep(100);
	}
	return 0;
}