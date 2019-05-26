#include <stdio.h>

int feld[6][4] = { 0 };
feld[0][1] = 1;
feld[4][0] = 1;
feld[4][1] = 1;
feld[4][2] = 1;
feld[2][1] = 1;
feld[2][2] = 1;
feld[3][1] = 1;

bool step(int i, int j)
{
   if (feld[i][j]  )

   if (i == 0 && j == 0)
   {
      return true;
   }
   if (feld[i][j] == 1)
   {
      return false;
   }
   if (step(i, j + 1))
   {
      printf("step(i, j+1)")
   }
   if (step(i, j - 1))
   {

   }
   if (step(i + 1, j))
   {

   }
   if (step(i - 1, j))
   {

   }
}

int main()
{
   step(0, 5);

   system("pause");
}
