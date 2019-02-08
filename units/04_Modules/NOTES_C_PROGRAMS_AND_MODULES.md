##  PROGRAMS, COMPILATION UNITS AND MODULES

### The main function

In the end the final product of software are the programs or applications
which are physically a binary file that the operative system can execute
or simply executables. But the compiler can translate any C source 
code into a binary which is known as object (here not related with "object oriented" OO). 

So in order to generate an executable, the last step (link) requires an arbitrary
number of objects and one - and only one - containing the translation of the
funtion main (no main no fun).

### Separation in compilation units or modules

Dividing the software in multiple files is not a requirement of the compiler or
linker but it has more to do with human readability. It is a way of having the pieces 
organized by functionality, features etc.

Typically separation in files is done writing one unit or module in a C file containing
functions and declaration of variables either local to the module (static) or global and
accessible to any module (using extern) and a header file containing types and structures 
associated with the module. Then the header file is included at the beginning of the the C
file as well as in all other modules that uses this module, that is its types, structures or
functions.

### Example: Word counter

We want to build an application capable of reading a text file, separate all its words and count
the occurrence of each (frequency) and finally sort them by frequency.

We could write a C source file doing all the job but let us imagine following flow

      
      
      -----------                 --------------                 -----------------                  ---------------                   
      |  main.c  |--processFile-->| fileReader |--newFile------->| lineProcessor |----resetWords--->|wordProcessor |
      |          |                |            |--processLine--->|               |----processWord-->|              |
      ------------                |            |--endFile------->|               |----endWords----->|              |
                                  --------------                 -----------------                  ----------------
                                                                                                           |
                                                                                                        sortByFreq
                                                                                                           |
                                                                                                           v
                                                                                                       ----------
                                                                                                       | sorter |
                                                                                                       ----------
                                  
which leads to following modules


      Module            Purpose
      ------------      ---------------------------------
      main.c            call processFile with the file name enter as argument
      fileReader        read a text file and send all read lines to the lineProcessor
      lineProcessor     separate all words in a line and send them to wordProcessor
      wordProcessor     collect all words and count its frequency, call the sort function and list all words
      sorter            sort an array of words by frequency


writing a module is now a little bit easier since each solves only one specific task but in order have an 
application working with all modules we have to specify very well the interaction between modules. That is
the "interfaces" between modules and this is done in the header files.

### Proposed interface

Interaction between all modules as well as structures that need to be known are declared in 
header files. For this example we have


#### fileReader.h

      void processFile (char * fileName);

#### lineProcessor.h

      void newFile     ();
      void processLine (char * line);
      void endFile     ();
      
#### wordProcessor.h

      #define MAX_WORD 90

      struct wordFreq {
         char word[MAX_WORD];
         int count;
      };
      typedef struct wordFreq tWordFreq;

      void resetWords  ();
      void processWord (char * word);
      void endWords    ();
      
#### sorter.h

      void sortByFreq (tWordFreq * words);

Now it only remains implementing all the modules (C files)

