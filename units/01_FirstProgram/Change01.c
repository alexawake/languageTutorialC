#include <stdio.h>

int InputMoney = 0;

int slot1E = 10;
int slot20C = 10;
int slot50C = 10;

int prepare1E = 0;
int prepare50C = 0;
int prepare20C = 0;

void input1Euro ()
{
   InputMoney = InputMoney + 100;
   slot1E ++;
}

void input50Cent ()
{
   InputMoney += 50;
   slot50C ++;
}

void input20Cent ()
{
   InputMoney += 20;
   slot20C ++;
}

void giveChange (int priceCents)
{
   int toChange = InputMoney - priceCents;
   
   if (toChange < 0)
   {
      printf ("Not enough money!");
      return;
   }
   while (toChange > 0)
   {
      if (slot1E - prepare1E > 0 && toChange / 100 > 0)
      {
         prepare1E ++;
         toChange -= 100;
      }
      else if (slot50C - prepare50C > 0 && toChange / 50 > 0)
      {
         prepare50C ++;
         toChange -= 50;
      }
      else if (slot20C - prepare20C > 0 && toChange / 20 > 0)
      {
         prepare20C ++;
         toChange -= 20;
      }
      else {
         printf ("No change possible!");
         return;
      }
   }
   
   printf ("Change possible:\n");
   printf ("   return %d x 1 euro\n", prepare1E);
   printf ("   return %d x 50 cent\n", prepare50C);
   printf ("   return %d x 20 cent\n", prepare20C);
}

int main ()
{
    input1Euro ();
    input1Euro ();
    input1Euro ();
    input50Cent ();
    input20Cent ();
    input20Cent ();

    giveChange (170);
    return 0;
}
