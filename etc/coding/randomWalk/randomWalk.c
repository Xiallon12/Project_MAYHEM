#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ALPHABET 36
#define SIZE 15
#define DIRECTIONS 4


int main(void) {
	int x, y;
	char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char grid[SIZE][SIZE];
	srand((unsigned) time(NULL));
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			grid[i][j] = '.';
		}
	}
	x = rand()%SIZE;
	y = rand()%SIZE;
	grid[x][y] = alphabet[0];
	for (int letter = 1, direction; letter < ALPHABET; letter++) {
		int tries=0, used[DIRECTIONS]={0};
		while (tries < DIRECTIONS) {
			direction = rand()%DIRECTIONS; // 0 is right, 1 is up, 2 is left, 3 is down
			if (!(used[direction])) {
				switch (direction) {

					case 0:
						if (x!=SIZE-1 && grid[x+1][y] == '.') {
							x += 1;
							grid[x][y] = alphabet[letter];
							tries = 5;
							break;
						}
						else {
							tries += 1;
							used[direction] += 1;
							continue;
						}

					case 1:
						if (y!=0 && grid[x][y-1] == '.') {
							y -= 1;
							grid[x][y] = alphabet[letter];
							tries = 5;
							break;
						}
						else {
							tries += 1;
							used[direction] += 1;
							continue;
						}

					case 2:
						if (x!=0 && grid[x-1][y] == '.') {
							x -= 1;
							grid[x][y] = alphabet[letter];
							tries = 5;
							break;
						}
						else {
							tries += 1;
							used[direction] += 1;
							continue;
						}

					case 3:
						if (y!=SIZE-1 && grid[x][y+1] == '.') {
							y += 1;
							grid[x][y] = alphabet[letter];
							tries = 5;
							break;
						}
						else {
							tries += 1;
							used[direction] += 1;
							continue;
						}
					}
				}
		}
		if (tries == 4) break;
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%c ", grid[i][j]);
		}
		printf("\n");
	}
	
}


	
	
