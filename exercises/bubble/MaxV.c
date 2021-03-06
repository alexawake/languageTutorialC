#include <stdio.h>
#include <string.h>

int bubble(const char** dicc, int* inde);
void show(const char ** dic, int * inde);
int run = 1;

int index2[] =
{
   0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
};

int N = sizeof(index2) / sizeof(int);

const char * dicc[] = {
   "paula",
   "schaut",
   "über",
   "die",
   "Schulter",
   "muss",
   "ich",
   "das",
   "alles",
   "in",
   "anführungsstriche",
   "schreiben"
};

int NDICC = sizeof(dicc) / sizeof(char *);


int main(void)
{
   while(run)
   {
      run = bubble(dicc, index2);
      printf("\n\n");
      show(dicc, index2);
   }
   //system("pause");
}

int bubble(const char** dic, int* inde)
{
   int counter = 0;
   int temp;
   for (int i = 0; i+1 < N; i++)
   {
      if (inde[i] < NDICC &&
          inde[i + 1] < NDICC &&
          strlen(dic[inde[i]]) > strlen(dic[inde[i + 1]]))
      {
         printf("\t%d > %d\n", strlen(dic[inde[i]]), strlen(dic[inde[i + 1]]));
         temp = inde[i + 1];
         inde[i + 1] = inde[i];
         inde[i] = temp;
         counter++;
      }
   }
   return counter;
}

void show(const char ** dic, int * inde)
{
   for (int i = 0; i < N; i++)
   {
      printf("%s\n", dic[inde[i]]);
   }
}
