#include <stdio.h>

#define bool char
#define false 0
#define true 1

#define DIM 8

int field [DIM][DIM] = { 0 };
int failures = 0;

bool legalmove (int i, int k)
{
   if (i < 0 || k < 0) return false;
   if (i >= DIM || k >= DIM) return false;
   return field[i][k] == 0;
}

bool jump (int i, int k, int nmove)
{
   if (!legalmove (i, k)) return false;

   field[i][k] = nmove;

   // Check if finished (8 * 8 = 64 movement)
   //
   if (nmove >= DIM * DIM)
      return true;

   //printf ("do jump %d, %d\n", i, k);

   // try all the possible ways recursively
   //
   if (jump(i-1, k-2, nmove+1) ||
       jump(i-2, k-1, nmove+1) ||
       jump(i-2, k+1, nmove+1) ||
       jump(i-1, k+2, nmove+1) ||
       jump(i+2, k-1, nmove+1) ||
       jump(i+1, k+2, nmove+1) ||
       jump(i+2, k+1, nmove+1) ||
       jump(i+1, k-2, nmove+1)
      )
   {
       return true;
   }

   // unmark it for other possible path
   field[i][k] = 0;
   failures ++;

   return false;
}

int main (int nn, char ** aa)
{
   if (jump (0, 0, 1))
   {
      printf ("solution found with %.3f thousand backward moves!\n", (float) (failures / 1000.f));
   }
   else
   {
      printf ("no solution found!\n");
   }
   for (int ii = 0; ii < DIM; ii ++)
   {
      for (int kk = 0; kk < DIM; kk ++)
         printf (" %2d", field[ii][kk]);
      printf ("\n");
   }
}


/*

----------- try using

   if (jump(i-1, k-2, nmove+1) ||
       jump(i-2, k-1, nmove+1) ||
       jump(i-2, k+1, nmove+1) ||
       jump(i-1, k+2, nmove+1) ||
       jump(i+2, k-1, nmove+1) ||
       jump(i+1, k+2, nmove+1) ||
       jump(i+2, k+1, nmove+1) ||
       jump(i+1, k-2, nmove+1)
      )

solution found with 10941.215 thousand backward moves!
  1 12  9  6  3 16 23 20
  8  5  2 11 22 19 48 17
 13 10  7  4 15 24 21 50
 28 37 14 45 30 49 18 47
 41 32 29 36 25 46 51 60
 38 27 40 31 44 59 54 57
 33 42 63 26 35 56 61 52
 64 39 34 43 62 53 58 55


----------- try using

   if (jump(i-1, k-2, nmove+1) ||
       jump(i-2, k-1, nmove+1) ||
       jump(i-2, k+1, nmove+1) ||
       jump(i-1, k+2, nmove+1) ||
       jump(i+1, k+2, nmove+1) ||
       jump(i+2, k+1, nmove+1) ||
       jump(i+2, k-1, nmove+1) ||
       jump(i+1, k-2, nmove+1))

solution found with 251825.344 thousand backward moves!
  1  8 11 16  3 18 13 64
 10 27  2  7 12 15  4 19
 53 24  9 28 17  6 63 14
 26 39 52 23 62 29 20  5
 43 54 25 38 51 22 33 30
 40 57 42 61 32 35 48 21
 55 44 59 50 37 46 31 34
 58 41 56 45 60 49 36 47

----------- try using

   if (jump(i-1, k-2, nmove+1) ||
       jump(i-1, k+2, nmove+1) ||
       jump(i+1, k+2, nmove+1) ||
       jump(i-2, k+1, nmove+1) ||
       jump(i-2, k-1, nmove+1) ||
       jump(i+2, k+1, nmove+1) ||
       jump(i+2, k-1, nmove+1) ||
       jump(i+1, k-2, nmove+1)


   too much computation, will it stop ... ?

*/

