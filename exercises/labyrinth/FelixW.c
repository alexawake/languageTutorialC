#include <stdio.h>

#define bool char
#define true 1
#define false 0

int feld[6][4] = { 0 };

bool step(int i, int j)
{
   if (i < 0 || j < 0 || i >= 6 || j >= 4) return false;

   if (i == 0 && j == 0)
   {
      feld[i][j] = 9;
      return true;
   }
   if (feld[i][j] != 0)
   {
      return false;
   }

   feld[i][j] = 2;

   if (step(i, j + 1))
   {
      return true;
   }
   if (step(i, j - 1))
   {
      return true;
   }
   if (step(i + 1, j))
   {
      return true;
   }
   if (step(i - 1, j))
   {
      return true;
   }

   return false;
}

void show ()
{
   for (int i = 0; i < 6; i ++)
   {
      printf ("\n");
      for (int j = 0; j < 4; j ++)
         printf (" %2d", feld[i][j]);         
   }
}

int main()
{
   feld[0][1] = 1;
   feld[4][0] = 1;
   feld[4][1] = 1;
   feld[4][2] = 1;
   feld[2][1] = 1;
   feld[2][2] = 1;
   feld[3][1] = 1;
   step(0, 3);
   show ();

   // system("pause");
}
