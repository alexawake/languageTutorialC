#include <stdio.h>

#define width   10
#define height  10

//creating new datatype
typedef struct {
   int x_position;
   int y_position;
   int n_movement;
}vektor;
vektor koordinates;

//forward initialization
vektor next_position       (vektor koordinates);
vektor check_surroundings  (vektor koordinates);
vektor move_backwards      (vektor koordinates);
char can_moveto            (vektor * koordinates, int incx, int incy);

void print_field();

//field declaration and initialization
int field [width][height] = {
   { 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
   { 0, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
   { 1, 0, 1, 0, 0, 1, 0, 0, 1, 0 },
   { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
   { 0, 1, 1, 0, 0, 0, 1, 1, 0, 1 },
   { 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
   { 1, 0, 0, 0, 0, 1, 1, 0, 1, 0 },
   { 0, 1, 0, 1, 0, 0, 0, 0, 1, 0 },
   { 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 },
   { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
   };


int main(void)
{
   print_field();
   koordinates.x_position = 0;
   koordinates.y_position = 0;
   koordinates.n_movement = 10;
   next_position(koordinates);
   print_field();
}


vektor next_position(vektor koordinates)
{
   if (koordinates.x_position == width - 1 && koordinates.y_position == height - 1)
   {
      return koordinates;
   }
   vektor coord = check_surroundings(koordinates);
   return next_position(coord);
}

char can_moveto (vektor * koordinates, int incx, int incy)
{
   if (koordinates->x_position + incx < width &&
       koordinates->y_position + incy < height && 
       koordinates->x_position + incx >= 0 &&
       koordinates->y_position + incy >= 0
       )
   {
      if (field[koordinates->x_position + incx][koordinates->y_position + incy] == 0)
      {
         // move it!
         koordinates->n_movement ++;
         koordinates->x_position += incx;
         koordinates->y_position += incy;
         field[koordinates->x_position][koordinates->y_position] = koordinates->n_movement;
         return 1;
      }
   }
   return 0;
}

vektor check_surroundings(vektor koordinates)
{
   print_field();
   //check right
   if (can_moveto (& koordinates, 1, 0))
      return koordinates;

   //check downwards
   if (can_moveto (& koordinates, 0, 1))
      return koordinates;

   //check left
   if (can_moveto (& koordinates, -1, 0))
      return koordinates;

   //check upwards
   if (can_moveto (& koordinates, 0, -1))
      return koordinates;

   //No way!
   field[koordinates.x_position][koordinates.y_position] = -1;
   return move_backwards (koordinates);
}

vektor move_backwards(vektor koordinates)
{
   print_field();

   koordinates.n_movement --;

   //check right
   if (koordinates.x_position + 1 < width)
   {
      if (field[koordinates.x_position + 1][koordinates.y_position] == koordinates.n_movement)
      {
         koordinates.x_position += 1;
         return koordinates;
      }
   }

   //check downwards
   if (koordinates.y_position + 1 < height)
   {
      if (field[koordinates.x_position][koordinates.y_position + 1] == koordinates.n_movement)
      {
         koordinates.y_position += 1;
         return koordinates;
      }
   }

   //check left
   if (koordinates.x_position > 0)
   {
      if (field[koordinates.x_position - 1][koordinates.y_position] == koordinates.n_movement)
      {
         koordinates.x_position -= 1;
         return koordinates;
      }
   }

   //check upwards
   if (koordinates.y_position != 0)
   {
      if (field[koordinates.x_position][koordinates.y_position - 1] == koordinates.n_movement)
      {
         koordinates.y_position -= 1;
         return koordinates;
      }
   }
   
   printf ("*** ERROR: cannot move_backwards (%d, %d, %d)\n", koordinates.x_position, koordinates.y_position, koordinates.n_movement);
   return koordinates;
}


//Feld Ausgabe
void print_field()
{
   printf("\n");
   for (int i = 0; i < height; i++)
   {
      for (int j = 0; j < width; j++)
      {
         printf(" %3d", field[i][j]);
      }
      printf("\n");
   }
}
