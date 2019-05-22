#include <stdio.h>
#include <stdlib.h>

#define DIMX 4
#define DIMY 5

int labyrinth(int x, int y);

int feld[DIMX][DIMY] = {
    {0, 0, 0, 1, 1},
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
   if (feld[x + 1][y] == 0 && x < DIMX - 1 && (rand() % 2) == 1 ) {
      x = x + 1;
      feld[x][y] = 2;
   }
   else if (feld[x][y + 1] == 0 && y < DIMY - 1 && (rand() % 2) == 1 ) {
      y = y + 1;
      feld[x][y] = 2;
   }
   else if (feld[x - 1][y] == 0 && x - 1 > -1 && (rand() % 2) == 1) {
      x = x - 1;
      feld[x][y] = 2;
   }
   else if (feld[x][y - 1] == 0 && y - 1 > -1 && (rand() % 2) == 1) {
      y = y - 1;
      feld[x][y] = 2;
   }
   else if( !(feld[x][y - 1] == 0 && y - 1 > -1) &&
            !(feld[x - 1][y] == 0 && x - 1 > -1) &&
            !(feld[x][y + 1] == 0 && y < DIMY - 1) &&
            !(feld[x + 1][y] == 0 && x < DIMX - 1))
   {
      feld[x][y] = 1;

      if (feld[x][y - 1] == 2) {
         y = y - 1;
      }
      else if (feld[x][y + 1] == 2) {
         y = y + 1;
      }
      else if (feld[x + 1][y] == 2) {
         x = x + 1;
      }
      else if (feld[x - 1][y] == 2) {
         x = x - 1;
      }
      else
      {
         printf("**** Fehler in Algoritm!\n");
         return 0;
      }
   }
   printf("Positionen: x:%d | y:%d\n", x, y);
   if (x != 0 || y != 0)
      return labyrinth(x, y);
   else
   {
      printf("Sucessful");
      return 1;
   }
}
