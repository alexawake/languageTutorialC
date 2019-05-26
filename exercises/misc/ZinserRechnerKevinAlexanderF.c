#include<stdio.h>

int main()
{
    float Zins, Kapital, Grundkapital;  //variablen mit Kleinbuchstaben beginnen und anders benennen, als in den Funktionen, da sonst Verwechslungen mC6glich
    int Laufzeit, jahr; //jahr ist die Laufvariable, also eine Zahl

    printf("Geben sie ihr Grundkapital [in Euro] ein: ");
    scanf("%f", &Grundkapital);                            //10 Vorkomma-, 2 Nachkommastellen

    printf("\nGeben sie die Laufzeit [in Jahren] ein: ");
    scanf("%d", &Laufzeit);

    printf("\nGeben sie den Zinssatz [in Prozent] ein: ");
    scanf("%f", &Zins);                                      
                                                   
    Kapital=Grundkapital;                           //Zu Beginn ist die Variable kapital der Wert, den ich eingegeben habe

     for(jahr = 1; jahr<= Laufzeit; jahr++)                        //man startet im ersten Jahr, es sollte for Schleife verwendet werden, da kein Exponent mC6glich, Variable jahr steht fC<r Anzahl der DurchlC$ufe
     {
        printf("\nIhr Kapital im Jahr %d betraegt:", jahr);      //%2d, da das Jahr zweistellig werden kann (max= 99 jahre).
        Kapital =   Kapital*(1+ Zins/100);                         //Funktion fC<r die Berechnung des Kapitals
        printf("\t%9.2f Euro", Kapital);                                // \t fC<r Tab und .2lf fC<r 2 Nachkommastellen
     }

    printf("\n\nAus %9.2f Euro wurden in %d Jahren: %9.2f Euro\n", Grundkapital, Laufzeit, Kapital);
	
	return 0;
}
