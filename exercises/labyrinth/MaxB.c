#include <stdio.h>


int solve(int field[7][7], int x, int y)
{
    if(field[x][y] == 4) //4 markiert Ziel, wenn dieses erreicht wird, Rückgabe 1
    {
        return 1;
    }
    else if(field[x+1][y] == 0)
    {
        if(solve(field, x+1, y) == 1)
        {
            printf("rechts");
        }
        else
        {
            x--;
        }
    }
    else if(field[x][y+1] == 0)
    {
        if(solve(field, x, y+1) == 1)
        {
            printf("hoch");
        }
        else
        {
            y--;
        }
    }
    else if(field[x-1][y] == 0)
    {
        if(solve(field, x-1, y) == 1)
        {
            printf("links");
        }
        else
        {
            x++;
        }
    }
    else if(field[x][y-1] == 0)
    {
        if(solve(field, x, y-1) == 1)
        {
            printf("runter");
        }
        else
        {
            y++;
        }
    }
    
    return 0; //wenn Funktion hier angelangt, ist Weg nicht richtig
    
    
}

int main()
{
    int field[7][7] =   {1, 1, 1, 1, 1, 1, 1,  //Mauer aus einsen um Labyrinth
                         1, 0, 0, 1, 1, 4, 1, 
                         1, 1, 0, 0, 1, 0, 1, 
                         1, 1, 1, 0, 1, 0, 1, 
                         1, 1, 1, 0, 1, 0, 1,
                         1, 0, 1, 0, 0, 0, 1,
                         1, 1, 1, 1, 1, 1, 1};
    
    if(solve(field, 1, 1) == 0)
    {
        printf("Fertig :)");
    }
    else
    {
        printf("Es gibt keinen Weg");
    }
    /*for(int i = 0, i <= 7, i++)
        {
            for(int j = 0, j <= 7, j++) 
                {
                    
                }
        }*/
    
}
