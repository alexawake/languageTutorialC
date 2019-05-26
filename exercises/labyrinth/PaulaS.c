#include <stdio.h>

main()
{

   int feld[4][5] =
   {
      { 0, 0, 0, 1, 0 },
      { 1, 0, 0, 1, 0 },
      { 0, 1, 0, 1, 0 },
      { 0, 1, 0, 0, 0 }
   };

   int feld_offen[4][5] = { 2 };

   //momentaner Standort
   int v = 0;
   int h = 0;
   int hn, vn;
   int eingabe;

   //Schritteingabe mit dem Nummernfeld
   printf("Geben Sie ihren nächsten Schritt ein");
   scanf_s("%d", &eingabe);
   switch (eingabe)
       {
      case 6: hn = h + 1;
      case 4: hn = h - 1;
      case 2: vn = v - 1;
      case 8: vn = v + 1;
      default: printf("Ungültige Eingabe");
       }

   //Prüfen, ob Schritt möglich ist
   if (hn < 0 || hn > 4 || vn < 0 || vn > 5)
   {
      printf("Sie dürfen das Spielfeld nicht verlassen");
   }

   //Prüfen, ob Weg richtig ist
   if (feld[vn][hn] == 0)
   {
      h = hn;
      v = vn;
      printf("Sie sind ein Feld weiter gelaufen");
      feld_offen[vn][hn] = 0;
      printf("%d", feld_offen);
   }

   if (feld[vn][hn] == 1)
   {
      h = hn;
      v = vn;
      printf("Dieser Schritt war falsch");
      feld_offen[vn][hn] = 1;
      printf("%d", feld_offen);
   }
   system("pause");
}
