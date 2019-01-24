# mini programs



   https://en.cppreference.com/w/c
   
   
## Showing the program arguments

This example prints out all given arguments to the program when is called.

      #include <stdio.h>

      int main (int nn, char ** aa)
      {
         printf ("Program arguments :\n");
         for (int indx = 0; indx < nn; indx ++)
            printf ("%d) [%s]\n", indx, aa[indx]);
      }
      

      
## Reading a text file using fgets

This example reads all lines of a text file and print them out preceded from a line number.

For that we use the stdio functions

      FILE * fopen  (const char * filename, const char * mode);
      int    fgetc  (FILE * stream);
      char * fgets  (char * str, int count, FILE * stream);
      int    fclose (FILE * stream);

for more information see 

      https://en.cppreference.com/w/c/io
   


      #include <stdio.h>
      ...
      
      #define MAX_LEN 200

      const char * filename = "myfile.txt";
      char line [MAX_LEN + 1];
      
      FILE * hFile = fopen (filename, "r"); // mode "r" = read
      if (hFile == NULL)
      {
         printf ("Error file %s can not be opened!", filename);
         return;
      }
      
      int lineNr = 1;
      while (fgets (line, sizeof(line), hFile) != NULL)
         printf ("%d) %s\n", lineNr++, line);
         
      fclose (hFile);
      
## Reading a file in binary mode using fgetc


Now we are going to read byte by byte in binary mode and output the hex value if
the byte read is not in some range and as character otherwise.

The only differences with the previous example are

      
      ... fopen (filename, "rb");  // mode "rb" = read in binary way (just bytes)
      ...
      
      
      int byte;      
      while ((byte = fgetc (hFile)) != EOF)
         if (byte < 32 || byte > 'z')         
              printf ("[%x]", byte);
         else printf ("%c", byte);

      ...
         
