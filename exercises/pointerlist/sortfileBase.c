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
typedef struct sBox Box;
struct sBox
{
   char word[MAX_LEN];
   int counter;
   Box * next;   
};

// Top element which actually contain no word at all
//
Box topBox = { 0, 0, 0 };

// method to add a Box with a word to the list 
// or increment the counter of an existing one.
//
void addWord (char * word)
{
   //TODO
   //TODO
}

// main program
//    - as argument receives a file name
//    - it read all its lines and call addWord for each one
//    - then it prints out the existing list
//
int main (int narg, char ** aarg)
{
   if (narg < 2)
   {
      printf ("syntaxt: sort filename\n");
      return 0;
   }
   
   char line [MAX_LEN + 1];
   
   // open the file for read
   //
   FILE * hFile = fopen (aarg[1], "r"); // mode "r" = read
   if (hFile == NULL)
   {
      printf ("Error file %s can not be opened!", aarg[1]);
      return 1;
   }
   
   // read all lines and call addWord for each one
   //
   while (fgets (line, sizeof(line), hFile) != NULL)
   {
      while (strlen(line) && line[strlen(line)-1] < 32) 
         line[strlen(line)-1] = 0;
      printf ("%s\n", line);
      addWord (line);
   }
   fclose (hFile);   

   // show the sorted list
   //
   printf ("\n--- sorted list:\n");
   Box * pt = topBox.next;
   while (pt != 0)
   {
      printf ("%s x %d\n", pt->word, pt->counter);
      pt = pt->next;
   }
   printf ("\n--- done\n");
}
