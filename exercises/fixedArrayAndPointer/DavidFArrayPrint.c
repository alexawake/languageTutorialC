#include <stdio.h>
#include <stdlib.h>

typedef char myArray[3][20];

void showList(char List[3][20]){
   int counter;
   for (counter = 0; counter <3; counter++){
      printf("%s ", List[counter]);
   }
   printf ("\n");
}

void showList1(char ** pList){
   while(*pList != 0)
   {
      printf("%s ", *pList);
      pList ++;
   }
   printf ("\n");
}

int main()
{
   //Fill myArray
   myArray Array1 = {
      "Programmieren",
      "macht",
      "Spass"
   };

   // we need one element more
   // in these two cases we get Array2 of type char **
   //   
   // char * Array2[4] = { 
   char * Array2[] = {
      "Programmieren",
      "macht",
      "Spass",
      NULL
   };

   //Array1 Ausgabe
   showList(Array1);

   //Array1 Ausgabe über pointer

   showList1(Array2);
   getc(stdin);

   // This convertion (from myArray to char **) it does not work!
   // and showList1 would crash
   //
   // NO! showList1((char **)Array1);
}

//
//    ========= why we cannot cast char [3][20] to char ** ?
//
// 
//    in the case of Array1 we have following memory layout
//
//                              10         20         30    ...  60
//                    0123456789.0123456789.0123456789.012..  
//         Array1 -> [Programmieren0-------macht0----------  ... ]
//         
//    and the distance between Array[n] and Array[n+1] is always 20 !
//
//    but with Array2
//
//        Array2 -> [@str1][@str2][@str3][   0]
//
//       with @str1 -> "Programmieren"
//            @str2 -> "macht"
//            ...
//
//    here each element [@str] has the size of a pointer  (e.g 4 bytes)
//
//    if we force Array1 to have this layout then "Prog" would be interpreted as @str1
//    "ramm" as @str2 etc which whill be for sure invalid addresses!
//

