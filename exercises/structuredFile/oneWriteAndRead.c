#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//
//    file format : head + record + record + ....
//
//    where 
//
//           head         60 title
//                         4 record counter
//       
//           record       60 name
//                         4 classNo
//                        40 email
//       

typedef struct _head head;
struct _head 
{
   char title[80];
   int counter;
};

typedef struct _record record;
struct _record
{
   char name[60];
   int  classNo;
   char email[40];
};


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

   // read the whole file
   //
   fi = fopen (dbname, "rb");
   if (fi == NULL) 
   {
      printf ("cannot open database %s for read!\n", dbname);
      return 2;
   }

   // read header
   //
   printf ("reading databsase %s ...\n", dbname);
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
