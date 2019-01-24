# Pointers

## Variable address and pointers

All variables have a memory address that can be retrieved with the operator &
preceding the variable name

      & VARIABLE

this address cannot be changed but can be stored in a variable of type pointer.

We could think of using a define like this if wanted

      #define addressof(v) &(v)


## Declaring a pointer

As for variables the pointers are also associated to a specific TYPE. The declaration
of a pointer of a specific type is

      TYPE * POINTER_NAME;

so now the variable POINTER_NAME can hold the address of any variable of type TYPE.

for example

      int a = 88;
      int * ptr = & a;  // now ptr stores the address of a

## Use of a pointer

A pointer getting the address of a variable

      POINTER = & VARIABLE;

Accessing the variable pointed by the pointer (dereferencing)

      * POINTER = VALUE;   // same as VARIABLE = VALUE; as long as POINTER points to VARIABLE
      VAR2 = * POINTER;    // same as VAR2 = VARIABLE;  as long as POINTER points to VARIABLE

Also a define like this could be helpful

      #define pointedVar(p) *(p)

A sample program to show this

      #include <stdio.h>

      #define addressof(v) &(v)
      #define pointedVar(p) *(p)

      void main ()
      {
         int a = 50;
         int b = 60;

         int * iptr = addressof(a);

         pointedVar(iptr) += 5;
         iptr = addressof(b);

         printf ("a = %d, b = %d, pointedVar(iptr) = %d\n", a, b, pointedVar(iptr));
      }

with output

      a = 55, b = 60, pointedVar(iptr) = 60

the code written in plain C

      ...
         int * iptr = & a;

         *iptr += 5;
         iptr = & b;

         printf ("a = %d, b = %d, *iptr = %d\n", a, b, *iptr);
      ...


## Pointer arithmetic

All pointers of all types store an address, therefore all have the same size (sizeof).
Once a pointer has an address this can be changed but always in sizeof(TYPE) units.

That is a pointer to a type TYPE incremented in one adds indeed to its previous address the
quantity of sizeof(TYPE)

      TYPE * POINTER;

      POINTER ++; // same as address of previous value of POINTER plus sizeof(TYPE)

the test program

      #include <stdio.h>

      void main ()
      {
         int a = 50;
         int * iptr1 = &a;
         int * iptr2 = iptr1 + 1;

         printf ("iptr1 %ld\n", iptr1);
         printf ("iptr2 %ld\n", iptr2);
      }

may output something like

      iptr1 140734006612012
      iptr2 140734006612016

another example incrementing pointers of different types

         #include <stdio.h>

         struct obj {
             char somebuffer[150];
         };
         typedef struct obj tobj;

         int main()
         {
             // Note! These addresses are not allowed, used only
             //       to demonstrate the increment of pointers!
             int * ptrInt = 0;
             tobj * ptrObj = 0;

             for (int ii = 0; ii < 5; ii ++)
             {
                 printf("inc %d) ptrInt %ld ptrObj %ld\n", ii,  ptrInt, ptrObj);
                 ptrInt ++;
                 ptrObj ++;
             }
             return 0;
         }

has the output

         inc 0) ptrInt 0 ptrObj 0
         inc 1) ptrInt 4 ptrObj 150
         inc 2) ptrInt 8 ptrObj 300
         inc 3) ptrInt 12 ptrObj 450
         inc 4) ptrInt 16 ptrObj 600

## Pointer and arrays

Having pointers this arithmetic make them actually very similar to arrays of the type they point to.

So if we have an array of some type and a pointer to that type

      int arr[10];
      int * pArr = & arr[0];

we can do either

      arr[5] = 66;

or

      *(pArr + 5) = 66;

furthermore, the following is also allowed in C

      pArr = arr; // same as & arr[0]
      pArr[5] = 66;
      *(arr + 5) = 66;

from here we have that in C an array is actually a pointer to its first element.

