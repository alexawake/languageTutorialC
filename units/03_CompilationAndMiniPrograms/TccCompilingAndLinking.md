# Compiling with TCC

Tiny C compiler has many compiler and linker options. All options are listed
on calling tcc without parameters.

Here we are going to show four ways of compiling and running a C program. For
more options an details visit

        https://bellard.org/tcc/tcc-doc.html

## Test program to compile

Our test program will be a small compilation unit with a function and the main function

         // File : proba.c
         #include <stdio.h>

         void somefunction (const char * name)
         {
            printf ("call from %s\n", name);
         }

         int main (int nn, char ** aa)
         {
            somefunction ("main");
            return 0;
         }

or a version splitted in two files

         // File : prob1.c
         
         void somefunction (const char * name);

         int main (int nn, char ** aa)
         {
            somefunction ("main");
            return 0;
         }

and
         // File : prob2.c
         #include <stdio.h>

         void somefunction (const char * name)
         {
            printf ("call from %s\n", name);
         }


## Directly run it

This can be achieved using the option -run that compiles and runs the
c program without even generating an executable file for that.

      tcc -run proba.c
      call from main

## Compile and link one or more sources

Here we compile C source code and link it using one or more files. The command will be

      tcc proba.c -o proba.exe

or
      tcc prob1.c prob2.c -o proba.exe

both generate an executable called proba.exe

      proba.exe
      call from main

## Compile only, generating objects and link afterwards

With either

      tcc -c prob1.c
      tcc -c prob2.c
or
      tcc -c prob1.c prob2.c

we generate the object files prob1.o and prob2.o. And we link them together with

      tcc prob1.o prob2.o -o proba.exe

## Generating a library from object files

In this case let us generate a simple library called libpro.a containing just the object prob2.o

      tcc -ar libpro.a prob2.o

Now we can link the object file prob1.o against the library libpro.a

      tcc -L. -lpro prob1.o -o proba.exe

we specify the path where to search for libraries (-L.) and the library (libxxxx.a) to use
with -lpro (-lxxxx)
