// This program reads a file line by line and call the function sortWord 
// for each line. The method sortWord has to be implemented and it should  
// add the given word to a list using the structure Box. 
// 
 
 
 #include <stdio.h> 
 #include <string.h> 
    
 #define MAX_LEN 200 
 
 
// structure for a word, a counter and the pointer to next element 
// we start with the typedef since we need Box to be defined for the field "next" 
// 
 typedef struct sBox Box; 	//durch typedef abkürzen und nicht immer struct vor den Befehl schreiben müssen
 struct sBox 					//ansonsten immer schreiben müssen: struct.sbox * current => jetzt nur box
 { 									//sbox=Grundstruktur, wenn ich diese verwende muss ich neue Namen verteilen (z.B. topBox)
    char word[MAX_LEN]; 			//Inhalte der sbox Struktur,die später belegt werden können, hier z.B. der Name im Array
    int counter; 
    Box * next;    					//Verweis auf die nächste Box
 }; 
 
 
 // Top element which actually contain no word at all 
 // 
 Box topBox = { 0, 0, 0 }; //start"flagge", wird nicht aufgefüllt diese Box, gilt nur als Anfang der Kette, diese hat die Struktur wie die sbox
								//Inhalte von sbox belegen
 
 // method to add a Box with a word to the list  
 // or increment the counter of an existing one. 
 // 
 void addWord (char * pword) //die Reihenfolge der Wörter/Liste soll alphabetisch sortiert sein, Zeile für Zeile
 { 
    Box * current = &topBox  //Pointer verweist immer auf Inhalt der leeren Box, Startinitialisierung, 
							//Sternchen==> Pointer mache ich draus, "&" verweist auf adresse der leeren Box
	while(current->next != 0)	//current ist ein pointer, der auf meine aktuelle Box zeigt
	{
		if (strcmp(current->next->word,pword) >= 0)
		{
			Box * neu = (Box *)malloc(sizeof(Box)); //neuer Verweis auf den Inhalt der box über den pointer neu, malloc ist dyn. Speicheranfrage
			strcpy(neu->word,pword);
		
		
		
		}
	}
	
	
	
	
	
	
 } 
 
 
 // main program 
 //    - as argument receives a file name 
 //    - it read all its lines and call addWord for each one 
 //    - then it prints out the existing list 
 // 
 int main (int narg, char ** aarg) //doppelstern für den Filename
 { 
    if (narg < 2) 
    { 
       printf ("syntaxt: sort filename\n"); 
       return 0; 
    } 
     
    char line [MAX_LEN + 1]; 
     
    // open the file for read 
    // 
    FILE * hFile = fopen (aarg[1], "r"); // mode "r" = read, Die Datei wird geöffnet und ausgelesen
    if (hFile == NULL) 
    { 
       printf ("Error file %s can not be opened!", aarg[1]); //falls die Datei keine Zeichen enthält, tritt diese Meldung auf
       return 1; 
    } 
     
    // read all lines and call addWord for each one 
    // 
    while (fgets (line, sizeof(line), hFile) != NULL)  //Hier wird die Datei aufgesplittet und einzelne Sätze ausgelesen
    { 
       while (strlen(line) && line[strlen(line)-1] < 32)  //letzte line löschen, da nicht benötigt
          line[strlen(line)-1] = 0; 
       printf ("%s\n", line); 
       addWord (line); 	//Funktion aufrufen und gibt Variable line mit, "line" ist das Wort, wo wir gerade stehen, jedes mal für jedes Wort
    } 
    fclose (hFile);    
 
    // show the sorted list 
    // 
    printf ("\n--- sorted list:\n"); 
    Box * pt = topBox.next; 	//pointer der auf den Anfang verweist. Am Anfang wird leere top Box erzeugt
    while (pt != 0) 
    { 
       printf ("%s x %d\n", pt->word, pt->counter); // "-> " Bei Pointern 
       pt = pt->next; 
    } 
    printf ("\n--- done\n"); 
 } 
