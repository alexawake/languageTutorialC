#include <stdio.h>
#include <stdlib.h>

#define DIMX 10
#define DIMY 10

int labyrinth(int, int, int);
void print_feld ();

int feld [DIMX][DIMY] = {
   { 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
   { 0, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
   { 1, 0, 1, 0, 0, 1, 0, 0, 1, 0 },
   { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
   { 0, 1, 1, 0, 0, 0, 1, 1, 0, 1 },
   { 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
   { 1, 0, 0, 0, 0, 1, 1, 0, 1, 0 },
   { 0, 1, 0, 1, 0, 0, 0, 0, 1, 0 },
   { 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 },
   { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
   };

int main()
{
   labyrinth(9, 9, 1);
   print_feld ();
   system("pause");
}

int labyrinth(int x, int y, int nmov)
{
   if (x < DIMX - 1 && feld[x + 1][y] == 0) {
      x = x + 1;
      feld[x][y] = nmov;
   }
   else if (y < DIMY - 1 && feld[x][y + 1] == 0) {
      y = y + 1;
      feld[x][y] = nmov;
   }
   else if (x > 0 && feld[x - 1][y] == 0) {
      x = x - 1;
      feld[x][y] = nmov;
   }
   else if (y > 0 && feld[x][y - 1] == 0) {
      y = y - 1;
      feld[x][y] = nmov;
   }
   else
   {
      // Sackgasse!
      //
      feld[x][y] = -nmov;
      //nmov --;
      int maxi = 0;
      int xcan = x;
      int ycan = y;

      // calculate neighbour with highest nmov to go there
      //
      if (y > 0 && feld[x][y - 1] > maxi) {
         xcan = x;
         ycan = y - 1;
         maxi = feld[x][y - 1];
      }
      if (x > 0 && feld[x - 1][y] > maxi) {
         xcan = x - 1;
         ycan = y;
         maxi = feld[x - 1][y];
      }
      if (y + 1 < DIMY && feld[x][y + 1] > maxi) {
         xcan = x;
         ycan = y + 1;
         maxi = feld[x][y + 1];
      }
      if (x + 1 < DIMX && feld[x + 1][y] > maxi) {
         xcan = x + 1;
         ycan = y;
      }
      x = xcan;
      y = ycan;
   }
   printf("Positionen: x:%d | y:%d\n", x, y);
   if (x != 0 || y != 0)
   {
      labyrinth(x, y, nmov+1);
   }
   else
   {
      printf("Sucessful");
      return 1;
   }
}

void print_feld ()
{
   printf("\n");
   for (int i = 0; i < DIMX; i++)
   {
      for (int j = 0; j < DIMY; j++)
      {
         printf(" %3d", feld[i][j]);
      }
      printf("\n");
   }
}
