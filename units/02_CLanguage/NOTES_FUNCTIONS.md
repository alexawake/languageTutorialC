# Functions

In C we actually have code only in functions.

## Definition of a function

The general syntax is for defining a function is


      TYPE_TO_RETURN FUNCTION_NAME (PARAMETERS)
      {
         BODY_STATEMENTS;
      }
      
If TYPE is "void" then the function actually does not return any value,
otherwise in all paths for exiting the function a value of type TYPE has to
be return and for that the statement "return" is used.

PARAMETERS can be empty (or void) or have one or more parameter separated by commas

      TYPE1 parameter1, TYPE2 parameter2, ...

Parameters are like variables of the function (only visible inside it) that takes
its value from the caller of the function.

Example

      char isPositiveAndGreatThan (int a, int b)
      {
         if (a < 0) return 0;
         if (a > b) return 1;
         return 0;
      }

      char res = isPositiveAndGreatThan (10, -2);

a will take in this call the value 10 and b -2, the function will return 1 that
will be stored in the variable res.

Exercise : write the same function using one single statement.


## Declaration of functions

While compiling code and a function call is found, for example

      ...
      a = somefunction (b, c);
      ..
      
the compiler has to know at least the type returned by the function as well as 
the number and types of the parameters. So can the compiler check that all the
types are the correct ones and generate the code for the jump to the function. The
code of the function itself is not needed at this point as it can be linked later.

In order to have this information, either we define the function before the call - which
is the usual way for small programs - or we show just the declaration of the function.

The declaration of the function is just the first line ended with ;

      TYPE_TO_RETURN FUNCTION_NAME (PARAMETERS);
      
that is, the same as in the definition but with no body.

This is what the header files (.h) contains: declaration of functions along with all types
that also has to be known by the compiler.

