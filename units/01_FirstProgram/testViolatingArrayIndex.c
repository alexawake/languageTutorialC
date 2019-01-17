//
// The result of this test might vary between compilers
// it can affect the previous variable to the array, the
// next one or any of them!
//

#include <stdio.h>

void somefunc(int first, int mid[3], int last)
{
    mid[3] = 44; // violation of array index (0..2)
    printf("somefunc() first %d last %d\n", first, last);
}

int main()
{
    int first = 111;
    int midarr [3] = { 0, 0, 0 };
    int last = 999;
    
    midarr [3] = 55; // violation of array index (0..2)

    printf("main() first %d last %d\n", first, last);
    somefunc (first, midarr, last);

    return 0;
}
