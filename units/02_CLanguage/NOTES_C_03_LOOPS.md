# Program Flow and Loops

The program flow can be guided by conditions using several statements

## if-else statement

The syntax for the "if" statement is

      if (CONDITION)
          STATEMENT_TRUE;
      else
          STATEMENT_FALSE;

where the "else" and its associated statement is optional.

This will execute the STATEMENT_TRUE if CONDITION evaluates to "true" and
STATEMENT_FALSE otherwise.

Example


      if (number < 100)
         printf ("less than 100");
      else
         printf ("bigger or equal to 100");


Note that STATEMENT_TRUE and STATEMENT_FALSE is any statement or a group of them
using curly braces "{ }" (begin and end of group)

      {
         STATEMENT1;
         STATEMENT2;
         ..
      }

and of course if-else statement is also possible, thus making a chain

      if (CONDITION1)
         STATE1;
      else if (CONDITION2)
         STATE2;
      else if (CONDITION3)
         STATE3;
      else
         STATE4;

## switch-case statement

A switch-case statement evaluates a value and executes different statements depending
of some defined cases. The syntax is

      switch (CONSTANT_VALUE)
      {
         case VALUE1:
            STATEMENT_1;
            break;
         case VALUE2:
            STATEMENT_2;
            break;
         ...
         default:
            STATEMENT_OTHERWISE;
            break;
      }

if the body of a specific "case" does not end with "break" the flow will continue
in next case body even if the case does not match!

for example

      switch (letter)
      {
         case 'a':
            print ("it is an 'a' for sure\n");
         case 'A':
            print ("it is an 'a' or an 'A', I know\n");
            break;
         default:
            print ("don't know what it is");
            break;
      }


## Loops

A loop is basically executing an statement or a set of them, called body loop, until one
condition is achieved or the loop is exited using "break" or "return" from the function
containing the loop.


### while loop

The while loop executes the loop until the condition evaluates to false

      while (CONDITION)
         BODY_STATEMENT;

### do-while loop

The only difference with the while loop is that here the body is at least once
independently from the condition, since this is evaluated later.

      do
         BODY_STATEMENT;
      while (CONDITION);

### for loop

This is a very used kind of loop, the general syntax is


      for (INITIAL_STATEMENT; CONDITION; AFTER_STEP_STATEMENT)
         BODY_STATEMENT;

the most times is used with a range of integers, for instance all indexes of an array

      int ii;
      for (ii = 0; ii < N; ii ++)
         myarray[ii] = ii * 10;

in this case the statement is executed for ii taking all the values from 0 to N-1


### Exiting the loop

In any loop, reaching a statement "break" in the body causes the loop to terminate immediately.

The statement "continue" jumps to the end of the body and continues with the next iteration
of the loop.

Of course, if the loop is within a function the statement return will exits the loop as well as
the function at that point.

## Conditions and boolean arithmetic

C has no boolean type (true or false) but "char" is used instead being the values 0 equivalent to "false"
and any other "true". Conditions has to end in a boolean value either through a numeric
value or an boolean expression where following operators over the operands "a" and "b" can be used

         ! a      not (where !true is false and !false is true)
         a == b   equal
         a != b   different
         a >  b   greater than
         a >= b   greater than or equal
         a <  b   less than
         a <= b   less than or equal
         a && b   logical and (&& avoids the evaluation of the second operator if first is 0)
         a || b   logical or  (|| avoids the evaluation of the second operator if first is 1)
         a ^  b   logical xor

where "a" and "b" has to have same or convertible type.

But note that many types DO NOT support these operators. For instance arrays cannot be compared
and therefore strings also not, this is allowed in many languages and in C it has to be taken
into account.

The way to compare two strings in C is using "strcmp" and can be summarized as follows

      str1 equal to str2         strcmp(str1, str2) == 0
      str1 greater than str2     strcmp(str1, str2) > 0
      str1 less than str2        strcmp(str1, str2) < 0

### Note about && and ||

Usually using && or || is faster than using single & or | but it is od special importance
to pay attention in what to do when evaluating boolean functions. For example


         if (evaluate_A () && evaluate_B ()) ...
         
will only call evaluate_B if evaluate_A returns "true", while

         if (evaluate_A () & evaluate_B ()) ...
         
will call both functions and the make the logical operation AND with the results.

Similarly for 
         
         if (evaluate_A () || evaluate_B ()) ...
         
here evaluate_B only will be called when evaluate_A returns "false", and with

         if (evaluate_A () | evaluate_B ()) ...
         
both will be called regardless of its returned values.

