#include <stdio.h>
#include <stdlib.h>

int labyrinth(int x, int y);

int feld[4][5] = {
               {0, 0, 0, 1, 0},
					{1, 0, 0, 1, 0},
					{0, 1, 0, 1, 0},
					{0, 1, 0, 0, 0} };


int main()
{
	labyrinth(0, 4);
	system("pause");
}

int labyrinth(int x, int y)
{
	if (feld[x + 1][y] == 0 && x + 1 < 5 && (rand() % 2) == 1 ) {
		x = x + 1;
		feld[x + 1][y] = 2;
	}
	else if (feld[x][y + 1] == 0 && y + 1 < 4 && (rand() % 2) == 1 ) {
		y = y + 1;
		feld[x][y + 1] = 2;
	}
	else if (feld[x - 1][y] == 0 && x - 1 > -1 && (rand() % 2) == 1) {
		x = x - 1;
		feld[x - 1][y] = 2;
	}
	else if (feld[x][y - 1] == 0 && y - 1 > -1 && (rand() % 2) == 1) {
		y = y - 1;
		feld[x][y - 1] = 2;
	}
	else if( !(feld[x][y - 1] == 0 && y - 1 > -1) && !(feld[x - 1][y] == 0 && x - 1 > -1) && !(feld[x][y + 1] == 0 && y + 1 < 4) && !(feld[x + 1][y] == 0 && x + 1 < 5)) {
		feld[x][y] = 1;
		for (int z = 0; z < 5; z++) {
			for (int z2 = 0; z2 < 4; z2++)
			{
				if (feld[z2][z] == 2) feld[z2][z] = 0;
			}
		}
		x = 0;
		y = 4;
	}
	printf("Positionen: x:%d | y:%d", x, y);
	if (x != 0 || y != 0) return labyrinth(x, y);
	else {
		printf("Sucessful");
		return 1;
	}
}
