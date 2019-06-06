// Header contained the structures needed for
//    structuredWriter.c and structuredReader.c 
//

#ifndef STRUCTURED_H

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


#endif

