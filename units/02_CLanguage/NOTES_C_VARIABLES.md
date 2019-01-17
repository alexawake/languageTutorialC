#  Memory of a program: Variables and Arrays

Variables are the units of memory that the program can use. The size in bytes of a variable
is given by its type.


## Variable Declaration

Variables can be declared within a function, being then only valid and accessible in that function,
or outside any function, being then global and accessible by any function and even other modules.

It is possible to declare a variable in two forms

      TYPE VARIABLE_NAME ;
      TYPE VARIABLE_NAME = CONSTANT_VALUE_OR_EXPRESSION;


indeed the syntax admit declaring multiple variables of the same type separated by commas

      TYPE VAR1, VAR2, VAR3;

this "syntax sugar" is not used always since it is important also to make more readable the
declaration of each variable.

Examples

      const int RED = 100;
      double a, b, c;

## Variable assignement

Variables are "filled" using the assignment operator "="

      VARIABLE = CONSTANT_OR_EXPRESSION_OF_THE_SAME_TYPE_OF_THE_VARIABLE;

more variables of the same can be initialized to the same value in a chain of "=" operators

      VARIABLE1 = VARIABLE2 = VARIABLE... = CTE_OR_EXPRESSION;

some examples

      a = 3.14;
      b = sin(a) - c * 6.;


## Arrays

Among single variables there is also the possibility of creating a set of N, being N a constant integer number,
variables just using a single name. This is called "array"

      TYPE ARRAY_NAME [N];

a variable declared in this way is actually N variables of type TYPE, each of them
accessible using a index between 0 and N-1 (in total N elements)

### IMPORTANT NOTE!

   Accessing an array with an invalid index (negative index or index >= N) is always an error
   and may cause an arbitrary malfunction, damage of the data being used by the program and
   also the program to crash.

   Therefore is a task of the developer to make all necessary checks before accessing arrays
   and pointers (see later)

### Size of an array#

In C there is no way to know the size of an array but using the tricky formula

      sizeof (ARRAY_NAME) / sizeof(ARRAY_BASE_TYPE)

another way is to give sizes using a define

Examples:

      #define MAX_LENGTH 80

      char myname [MAX_LENGTH + 1];


      int coeff [200];

      coeff[0] = 0;
      coeff[1] = 1;
      coeff[2] = -1;
      coeff[3] = coeff[1] * 2;

      printf ("coefficients size = %d, element size = %d\n", sizeof(coefficients), sizeof(int));
      printf ("size of coefficients array = %d\n", sizeof(coefficients)/sizeof(int));

### char array: strings

An array of "char" is called "string" and the content is a text. It has to be finished with a 0 (NULL)
which is called "null terminated string".

Example:

      char myname [40];

      myname [0] = 'A'; // a constant char can be written using '' or an integer between 0 and 255
      myname [1] = 'l';
      myname [2] = 'e';
      myname [3] = 'x';
      myname [4] = 0;

strings can be manipulated using string library (string.h) and always with care of not writing
outside the size of the string!

      #include <string.h>
      ...

      strcpy (myname, "Alex");         // copy the string (constant using "")
      strcat (myname, " Xalabarder");  // concatenate (add the two strings)


### Arrays of multiple dimensions

Arrays can have multiple dimensions as well, for example

      int matrix[3][3] = {
                       { 1, 0, 0 },
                       { 0, 1, 0 },
                       { 0, 0, 1 },
                       } ;

following code would initialize the matrix with the same values

      int matrix[3][3] = { 0 };
      matrix[0][0] = matrix[1][1] = matrix[2][2] = 1;

note that the first possible index for rows and columns in this array
is 0 and the last one 2.
