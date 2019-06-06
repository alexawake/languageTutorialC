#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structured.h"

int main (int narg, char ** aarg)
{
   const char * dbname = "agenda.stx";
   
   // try to open db for write
   //
   FILE * fi = fopen (dbname, "w+");
   if (fi == NULL) 
   {
      printf ("Error cannot open database %s for write!", dbname);
      return 1;
   }   
   
   // write some header
   //
   head hea = { "this is my first db", 2 };
   fwrite  (&hea, sizeof(head), 1, fi);

   // write two records
   //
   record rec1 = { "Galea", 202, "galea@duals.de" };
   fwrite  (&rec1, sizeof(record), 1, fi);

   record rec2 = { "Jonnathan", 136, "jonn@hotmail.com" };
   fwrite  (&rec2, sizeof(record), 1, fi);
   
   fclose (fi);
   return 0;
}