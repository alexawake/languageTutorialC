#include <stdio.h>
#include <stdlib.h>
int lab [5][5] ={   0,0,0,1,0,
                    1,1,0,1,0,
                    0,0,0,1,0,
                    0,0,0,0,0,
                    1,0,1,0,1};

int step(int n, int k)
{
    if(n>=5 || k>=5){       // Prüfen, ob außerhab des Feldes
        return 1;
    }
    if(n<0 || k<0){                 // Prüfen, ob außerhab des Feldes
        return 1;
    }
    if(lab[n][k] != 0){             // Prüfen, ob Feld nicht erlaubt ist
        return 1;
    }

    if(n==0 && k==0){               //Endposition erreicht. Ziel erfüllt!
        lab[n][k] = 9;
        return 0;
    }

    lab[n][k] = 2;   // markieren als Pfad Versucht

    if(step(n,k-1) == 0){           //Links prüfen ob frei ist
        return 0;
    }

     if(step(n-1,k) == 0){           //Oben prüfen ob frei ist
        return 0;
    }

     if(step(n,k+1) == 0){           //Rechts prüfen ob frei ist
        return 0;
    }

     if(step(n+1,k) == 0){           //Unten prüfen ob frei ist
        return 0;
    }

    lab[n][k] = 3;   // markieren als kein Erfolg!
    return 1;
}

void showlab ()
{
   int nn;
   int kk;
   for (nn = 0; nn < 5; nn ++)
   {
      printf ("\n");
      for (kk = 0; kk < 5; kk ++)
         printf (" %2d", lab[nn][kk]);
   }
   printf ("\n");
}

int main()
{
   step(0, 4);                     //Startposition wird übergeben
   showlab ();
}
