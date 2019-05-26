#include<stdio.h>

float Kapitalfunktion(float Kapital,  int Laufzeit, float Zinssatz)             //der Datentyp vor dem Namen (float Kapitalfunktion) bestimmt, in welchem Format der Wert zurC<ckgegeben wird, Variablen sollten anders heiCen
{                       //die Varialen habe ich hier direkt umbenannt und eingefC<hrt fC<r die Funktion
   
    int jahr;    //jahr ist die Laufvariable, also eine Zahl, diese ist jedoch nicht die Laufzeit

     for(jahr = 1; jahr<= Laufzeit; jahr++)                 //man startet im ersten Jahr, es sollte for Schleife verwendet werden, da kein Exponent mC6glich, Variable jahr steht fC<r Anzahl der DurchlC$ufe
     {
        printf("\nIhr Kapital im Jahr %d betraegt:", jahr); 
        Kapital =  Kapital*(1+ Zinssatz/100);                         //Funktion fuer die Berechnung des Kapitals
        printf("\t%.2f Euro", Kapital);                                // \t fuer Tab und .2lf fuer 2 Nachkommastellen
     }

    return Kapital;
}

void main()
{
    float Zins, Kapital, Grundkapital, Endsumme;  //variablen mit Kleinbuchstaben beginnen und anders benennen, als in den Funktionen, da sonst Verwechslungen moeglich
    int Laufzeit;

    printf("Geben sie ihr Grundkapital [in Euro] ein: ");
    scanf("%f", &Grundkapital);                     

    printf("\nGeben sie die Laufzeit [in Jahren] ein: ");
    scanf("%d", &Laufzeit);

    printf("\nGeben sie den Zinssatz [in Prozent] ein: ");
    scanf("%f", &Zins);                                                 //lf fuer double!

    Endsumme = Kapitalfunktion (Grundkapital, Laufzeit, Zins);  //damit werden die Werte an meine Funktion gegeben

    printf("\n\nAus%9.2f Euro wurden in %d Jahren: %9.2f Euro\n", Grundkapital, Laufzeit, Endsumme);
    printf("Glueckwunsch, da haste digge Cash gemacht ;) ");
}
