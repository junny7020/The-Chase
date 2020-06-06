#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define M 109
#define N 110
#define WW 119
#define AA 97
#define SS 115
#define DD 100

static int pw;
static int end, start;
static int ph;
static int aw, ah;

char Title[40][40]{
};


char map[16][16] = {
	{"000000000000000"},
	{"000000000000000"},
	{"000000000000000"},
	{"000000000000000"},
	{"000000000000000"},
	{"000000000000000"},
	{"000000000000000"},
	{"000000000000000"},
	{"000000000000000"},
	{"000000000000000"},
	{"000000000000000"},
	{"000000000000000"},
	{"000000000000000"},
	{"000000000000000"},
	{"000000000000000"},
};


void drawMap() {
	system("cls");
	int W, H;


	for (H = 0; H < 15; H++) {
		for (W = 0; W < 15; W++) {
			char temp = map[H][W];

			if (temp == '0') {
				printf("¡á");
			}
			else if (temp == 'b') {
				printf("¡à");
			}
			else if (temp == 'p') {
				printf("¢Â");
				pw = W;
				ph = H;
			}
			else if (temp == 'a') {
				printf("¢È");
				aw = W;
				ah = H;
			}
		}
		printf("\n");
	}
};

int dead(int distance) {
	if (distance <= 1) {
		system("cls");
		printf("A player is caught!!!");
		if (_kbhit()) {
			system("cls");
			printf("Continue?\nEnter: Y/N");
			char c = getchar();
			if (c == 'Y' || c == 'y') {
				int main(1);
			}
			if (c == 'N' || c == 'n') {
				int main(0);
			}
		}
	}
	return 0;
};

void drawTitle() {
	system("cls");
	int W, H;


	for (H = 0; H < 20; H++) {
		for (W = 0; W < 40; W++) {
			char temp = Title[H][W];
			if (H == 4 && W == 4) {
				printf("     ¡á¡à¡á¡á¡à¡á¡á¡á¡à¡á¡á¡à¡á");
			}
			if (H == 5 && W == 4) {
				printf("     ¡à¡à¡á¡à¡á¡à¡á¡à¡á¡á¡à¡à¡á");
			}
			if (H == 6 && W == 4) {
				printf("     ¡á¡á¡à¡á   CHASE  ¡á¡á¡à¡à");
			}
			if (H == 7 && W == 4) {
				printf("     ¡á¡à¡á¡á¡à¡à¡á¡á¡á¡à¡à¡á¡á");
			}
			if (H == 8 && W == 4) {
				printf("     ¡à¡à¡á¡à¡á¡á¡à¡á¡á¡à¡à¡à¡á");
			}
			if (H == 10 && W == 4) {
				printf("     Press any key to start!");
			}
			if (H == 12 && W == 4) {
				printf("     - Player 1 -   - Player 2 -");
			}
			if (H == 14 && W == 4) {
				printf("      ¡ã : UP        W : UP  ");
			}
			if (H == 15 && W == 4) {
				printf("      ¡å : DOWN      S : DOWN");
			}
			if (H == 16 && W == 4) {
				printf("      ¢¸ : LEFT      A : LEFT");
			}
			if (H == 17 && W == 4) {
				printf("      ¢º : RIGHT     D : RIGHT");
			}
			if (H == 18 && W == 4) {
				printf("      N : WALL");
			}
			if (H == 19 && W == 4) {
				printf("      M : TELEPORT");
			}
		}
		printf("\n");
	}
};


int main() {
	char any;
	map[14][14] = 'p';
	map[2][2] = 'a';
	srand(time(NULL));

	drawTitle();
	while (1) {
		any = _getch();
		drawMap();
		char key;
		while (1) {
			if (_kbhit()) {
				key = _getch();


				if (key == M) {
					int www = rand() % 15;
					int hhh = rand() % 15;
					map[ph][pw] = '0';
					map[hhh][www] = 'p';
					drawMap();
					break;
				}
				if (key == N) {
					for (int i = 0; i < 15; i++) {
						map[i][7] = 'b';
					}
					for (int i = 0; i < 15; i++) {
						map[7][i] = 'b';
					}
					start = time(NULL);
					drawMap();
					break;
				}
				switch (key) {
				case AA:
					if (map[ah][aw - 1] != '0') {
						goto A;
					}
					map[ah][aw] = '0';
					map[ah][aw - 1] = 'a';
					goto A;
				case DD:
					if (map[ah][aw + 1] != '0') {
						goto A;
					}
					map[ah][aw] = '0';
					map[ah][aw + 1] = 'a';
					goto A;
				case WW:
					if (map[ah - 1][aw] != '0') {
						goto A;
					}
					map[ah][aw] = '0';
					map[ah - 1][aw] = 'a';
					goto A;
				case SS:
					if (map[ah + 1][aw] != '0') {
						goto A;
					}
					map[ah][aw] = '0';
					map[ah + 1][aw] = 'a';
					goto A;
				}

				if (key == -32) {
					key = _getch();
					switch (key) {
					case LEFT:
						if (map[ph][pw - 1] != '0') {
							break;
						}
						map[ph][pw] = '0';
						map[ph][pw - 1] = 'p';
						break;
					case RIGHT:
						if (map[ph][pw + 1] != '0') {
							break;
						}
						map[ph][pw] = '0';
						map[ph][pw + 1] = 'p';
						break;
					case UP:
						if (map[ph - 1][pw] != '0') {
							break;
						}
						map[ph][pw] = '0';
						map[ph - 1][pw] = 'p';
						break;
					case DOWN:
						if (map[ph + 1][pw] != '0') {
							break;
						}
						map[ph][pw] = '0';
						map[ph + 1][pw] = 'p';
						break;
					}
				A:
					drawMap();
					if (abs(ph - ah) <= 1 && abs(pw - aw) <= 1) {
						dead(abs(ph - ah));
					}
					end = time(NULL);
					if (end - start == 5) {
						for (int i = 0; i < 15; i++) {
							map[i][7] = '0';
						}
						for (int i = 0; i < 15; i++) {
							map[7][i] = '0';
						}
					}
				}

			}

		}
	}
}