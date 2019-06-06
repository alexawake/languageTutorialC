#include <stdio.h>
#include <stdlib.h>

typedef char myArray [3][20];

void showList(char List[3][20]){
   int counter;
   for(counter = 0; counter <3; counter ++){
      printf("%s ", List[counter]);
   }
}

void showList1(char ** pList){
    //while(*pList != 0){
    printf("%s", *pList);
    //pList ++;
    //}
}

int main()
{
   //Fill myArray
   myArray Array1 = {
       "Programmieren",
       "macht",
       "Spass"
   };

   char Array2[3][20] = {
       "Programmieren",
       "macht",
       "Spass",
       "0"
   };

   char **pArray2 = (char **) Array2;

   //Array1 Ausgabe
   showList(Array1);

   //Array1 Ausgabe über pointer
   showList1(pArray2);
}
