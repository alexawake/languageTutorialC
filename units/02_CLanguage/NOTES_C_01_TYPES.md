# Types 

C is a typed language, variables have to be declared from a specific type.
Operation between variables and function calls (parameters) will be checked
to match the correct type by the compiler.

## Basic types in C

The basic types given in C are

      type name      size in
                     bytes    description
      ------------   -------  ---------------------------
      char             1      a char 0..255 (ascii table)
      short            2      short integer
      int              4      integer
      double           8      float point double precission
      void             -      actually not a type, used for functions
                              with no return or general pointers

types can be preceded by some modifiers

      modifiers
      -------------  ---------------------------
      const          make the variable read only
      signed         accept negative values as well
                     this the default set for numeric
                     types
      unsigned       only positive values
      register       deprecated, no effect on code
      volatile       deprecated, no effect on code
      auto           deprecated, not needed (different meaning in C++ !)
      static         the variable or function is not visible out of the compilation unit (different meaning in C++ !)
      extern         the variable or function is declared in another compilation unit

### Examples

     const int eigth = 8;
     unsigned long counter = 0;
     const unsigned double pi = 3.14159;
     extern int globalCounter;

## Custom types

### Enumeration

Enumeration is a custom type used for constant values of type integer or char

      enum ENUMERATION_NAME
      {
         ENUM_VALUE1 = cte1,
         ENUM_VALUE2 = cte2,
         ...
      };
      // convenient typedef :
      typedef enum ENUMERATION_NAME ENUMERATION_NAME;

For example

      enum Color {
         RED,
         BLUE,
         YELLOW,
      };
      typedef enum Color Color;

if no value is assigned then it will increment 1 each starting with 0.
The enum above could be achieved using variables as

      const int RED = 0;
      const int BLUE = 0;
      const int YELLOW = 0;
      
### Struct

A more powerful custom type is accomplished with the "struct" keyword where the type
define a set of fields to be contained in the variable.

      struct STRUCT_NAME
      {
         TYPE field1;
         TYPE field2;
         ...
      };
      // convenient typedef :
      typedef struct STRUCT_NAME STRUCT_NAME;

where TYPE is any type including custom types as well, so "structs" can be nested
thus allowing arbitrary complex structures of data.

Example:

      struct Point
      {
         double x;
         double y;
      };
      typedef struct Point Point;

      struct Rectangle
      {
         Point top_left;
         Point bottom_right;
      };
      typedef struct Rectangle Rectangle;


## Facilities with types

All types, even custom ones can be renamed, or better said, create an alias by using "typedef"

      typedef TYPE NEW_NAME_FOR_TYPE;

For all types the size can be evaluated by using "sizeof" which is actually not
a function but it can be used as a constant. It can be applied to a TYPE or a
VARIABLE which type size wants to be known.

      sizeof (TYPE)
      sizeof (VARIABLE)

Example

      printf ("size of Rectangle type %d", sizeof (Rectangle));
