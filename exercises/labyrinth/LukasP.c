#include <stdio.h>
#include <stdlib.h>

#define DIMX 4
#define DIMY 5

int labyrinth(int, int, int, int);

int feld[DIMX][DIMY] = {
    {0, 0, 0, 1, 1},
    {1, 0, 0, 1, 0},
    {0, 1, 0, 1, 0},
    {0, 1, 0, 0, 0} };


int main()
{
   labyrinth(0, 4, 0, 4);
   system("pause");
}

int labyrinth(int x, int y, int prevx, int prevy)
{
   int x2 = x;
   int y2 = y;

   if (feld[x + 1][y] == 0 && x < DIMX - 1 && (rand() % 2) == 1 ) {
      x2 = x + 1;
      feld[x2][y2] = 2;
   }
   else if (feld[x][y + 1] == 0 && y < DIMY - 1 && (rand() % 2) == 1 ) {
      y2 = y + 1;
      feld[x2][y2] = 2;
   }
   else if (feld[x - 1][y] == 0 && x - 1 > -1 && (rand() % 2) == 1) {
      x2= x - 1;
      feld[x2][y2] = 2;
   }
   else if (feld[x][y - 1] == 0 && y - 1 > -1 && (rand() % 2) == 1) {
      y2 = y - 1;
      feld[x2][y2] = 2;
   }
   else if( !(y > 0 && feld[x][y - 1] == 0) &&
            !(x > 0 && feld[x - 1][y] == 0) &&
            !(y + 1 < DIMY && feld[x][y + 1] == 0) &&
            !(x + 1 < DIMX && feld[x + 1][y] == 0))
   {
      feld[x][y] = 1;
      x = prevx;
      y = prevy;
   }
   printf("Positionen: x:%d | y:%d\n", x, y);
   if (x != 0 || y != 0)
      return labyrinth(x, y, x2, y2);
   else
   {
      printf("Sucessful");
      return 1;
   }
}
