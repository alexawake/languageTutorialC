#include <stdio.h>

#define bool char
#define false 0
#define true 1

#define DIM 10

int field [DIM][DIM] = {
      { 0, 0, 0, 1, 0, 1, 0, 0, 1, 0 },
      { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 1, 0, 1, 0, 1, 0, 1, 0, 0 },
      { 0, 0, 0, 0, 0, 1, 0, 0, 1, 0 },
      { 1, 1, 1, 1, 0, 1, 0, 1, 1, 0 },
      { 0, 1, 0, 0, 0, 1, 0, 1, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
      { 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
      { 0, 0, 0, 1, 0, 0, 0, 1, 1, 0 },
      { 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
   };

bool legalmove (int i, int j)
{
   if (i < 0 || j < 0) return false;
   if (i >= DIM || j >= DIM) return false;
   return field[i][j] == 0;
}

bool step (int i, int j)
{
   if (!legalmove (i, j)) return false;

   // Check if exit reached
   //
   if (i == DIM-1 && j == DIM-1)
   {
      field[i][j] = 9;
      return true;
   }
   
   printf ("do step %d, %d\n", i, j);
   // mark it as walked
   field[i][j] = 1;
   
   // try all the possible ways recursively
   //
   if (step(i+1, j) ||
       step(i-1, j) ||
       step(i, j+1) ||
       step(i, j-1))
   {
       return true;
   }

   // mark it as cul-de-sac
   field[i][j] = -1;
   printf ("undo step %d, %d\n", i, j);

   return false;
}

int main (int nn, char ** aa)
{
   step (0, 0);
   for (int ii = 0; ii < DIM; ii ++)
   {
      for (int jj = 0; jj < DIM; jj ++)
         printf (" %d", field[ii][jj]);
      printf ("\n");
   }
}
