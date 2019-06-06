#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structured.h"

int main (int narg, char ** aarg)
{
   const char * dbname = "agenda.stx";
   
   // read the whole file
   //
   FILE * fi = fopen (dbname, "rb");
   if (fi == NULL) 
   {
      printf ("cannot open database %s for read!\n", dbname);
      return 2;
   }

   printf ("reading databsase %s ...\n", dbname);

   // read header
   //
   head hea;
   fread (&hea, sizeof(head), 1, fi);

   printf (" title         : %s\n", hea.title);
   printf (" count records : %d\n", hea.counter);
   
   int nn = 0;
   
   // read all records
   //
   record rec;
   while (nn++ < hea.counter)
   {
      fread (&rec, sizeof(record), 1, fi);
      printf ("\n");
      printf ("   rec # %d\n", nn);
      printf ("   name    : %s\n", rec.name);
      printf ("   classNo : %d\n", rec.classNo);
      printf ("   email   : %s\n", rec.email);
   }
   fclose (fi);
   
   return 0;
}