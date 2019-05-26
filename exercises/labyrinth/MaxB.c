#include <stdio.h>


int solve(int field[7][7], int x, int y)
{
    if (field[x][y] == 4) //4 markiert Ziel, wenn dieses erreicht wird, Rückgabe 1
    {
        return 1;
    }

    // mark cell!
    field[x][y] = 2;

    if (field[x + 1][y] == 0)
    {
        if (solve(field, x + 1, y) == 1)
        {
            printf("rechts");
            return 1;
        }
    }

    if (field[x][y + 1] == 0)
    {
        if (solve(field, x, y + 1) == 1)
        {
            printf("hoch");
            return 1;
        }
    }

    if (field[x - 1][y] == 0)
    {
        if (solve(field, x - 1, y) == 1)
        {
            printf("links");
            return 1;
        }
    }

    if (field[x][y - 1] == 0)
    {
        if (solve(field, x, y - 1) == 1)
        {
            printf("runter");
            return 1;
        }
    }

    return 0; //wenn Funktion hier angelangt, ist Weg nicht richtig
}

int main()
{
    int field[7][7] = { 
        1, 1, 1, 1, 1, 1, 1,  //Mauer aus einsen um Labyrinth
        1, 0, 0, 1, 1, 4, 1,
        1, 1, 0, 0, 1, 0, 1,
        1, 0, 1, 0, 1, 0, 1,
        1, 0, 1, 0, 1, 0, 1,
        1, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1 };

    if (solve(field, 1, 1) == 0)
    {
        printf("Fertig :)");
    }
    else
    {
        printf("Es gibt keinen Weg");
    }
    for(int i = 0; i < 7; i++)
    {
      printf("\n");
      for(int j = 0; j < 7; j++)
      {
        printf(" %2d", field[i][j]);
      }
    }
}
