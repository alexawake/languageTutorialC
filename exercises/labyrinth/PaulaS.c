#include <stdio.h>

#define MAXV 4
#define MAXH 5

int feld[MAXV][MAXH] =
{
    { 0, 0, 0, 1, 0 },
    { 1, 0, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 0, 0 }
};

int feld_offen[MAXV][MAXH] = 
{
    { 2, 2, 2, 2, 2 },
    { 2, 2, 2, 2, 2 },
    { 2, 2, 2, 2, 2 },
    { 2, 2, 2, 2, 2 }
};

//momentaner Standort
int v = 0;
int h = 0;

void show_offen()
{
    for (int vv = 0; vv < MAXV; vv++)
    {
        printf("\n");
        for (int hh = 0; hh < MAXH; hh++)
            printf(" %2d", feld_offen[vv][hh]);
    }
    printf("\n");
}

void schritt()
{
   int hn = h, vn = v;
   int eingabe;

   //Schritteingabe mit dem Nummernfeld
   printf("Geben Sie ihren nächsten Schritt ein (6, 4, 2 or 8): ");
   scanf("%d", &eingabe);
   switch (eingabe)
   {
    case 6: hn = h + 1; break;
    case 4: hn = h - 1; break;
    case 2: vn = v - 1; break;
    case 8: vn = v + 1; break;
    default: {
              printf("\nUngültige Eingabe!\n");
              return;
             }
    }

    //Prüfen, ob Schritt möglich ist
    if (hn < 0 || hn >= MAXH || vn < 0 || vn >= MAXV)
    {
        printf("Sie dürfen das Spielfeld nicht verlassen\n");
        return;
    }

    //Prüfen, ob Weg richtig ist
    if (feld[vn][hn] == 0)
    {
        h = hn;
        v = vn;
        printf("Sie sind ein Feld weiter gelaufen\n");
        feld_offen[vn][hn] = 0;
        show_offen();
        return;
    }

    if (feld[vn][hn] == 1)
    {
        printf("Dieser Schritt war falsch\n");
        feld_offen[vn][hn] = 1;
        show_offen();
        return;
    }
}


int main()
{
    while (1)
        schritt();
    return 0;
}
