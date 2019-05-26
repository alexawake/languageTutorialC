#include <stdio.h>
#include <stdlib.h>
int lab [5][5] ={   0,0,0,1,0,
                    1,1,0,1,0,
                    0,1,0,1,0,
                    0,1,0,0,0,
                    1,1,1,1,1};

int step(int n, int k){
    if(n<0 || k<0){                 // Prüfen, ob außerhab des Feldes
        return 1;
    }

    if(n==0 && k==0){               //Endposition erreicht. Ziel erfüllt!
        return 0;
    }

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

}

int main()
{
    step(0, 4);                     //Startposition wird übergeben
}
