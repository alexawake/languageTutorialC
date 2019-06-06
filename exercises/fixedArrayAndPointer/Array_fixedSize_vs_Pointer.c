// Differences between multi dimension array with fix sizes and as pointer
//

#include <stdio.h>

int main(int argc, char ** argv)
{
    char arrHard[2][10] = { "FIRST", "SECOND" };
    char * arrPtr[] = { "first", "second" };

    // memory layout for arrHard
    //
    //              0123456789.123456789.
    // arrHard ->   FIRST0xxxxSECOND0xxxx

    char *p0 = (char *)arrHard;
    char *p1 = arrHard[0];
    char *p2 = arrHard[1];

    printf("\nfor char arrHard[2][10] ...\n");
    printf("sizeof arrHard      = %d\n", sizeof(arrHard));
    printf("sizeof arrHard[0]   = %d\n", sizeof(arrHard[0]));
    printf("addr arrHard        = %d\n", (int)p0);
    printf("addr arrHard[0]     = %d\n", (int)p1);
    printf("dist arrHard  p2-p1 = %d - %d = %d\n", (int)p2, (int)p1, (int)(p2 - p1));

    // memory layout for arrPtr (e.g. with sizeof(char *) equal 8)
    //
    //               01234567  89.12345
    // arrPtr  ->   [ @str1  ][  @str2 ]
    //
    // @str1   ->   "first"
    // @str2   ->   "seond"

    printf("\nfor char * arrPtr[] ...\n");
    p0 = (char *)arrPtr;
    p1 = arrPtr[0];
    p2 = arrPtr[1];
    printf("sizeof arrPtr      = %d\n", sizeof(arrPtr));
    printf("sizeof arrPtr[0]   = %d\n", sizeof(arrPtr[0]));
    printf("addr arrPtr        = %d\n", (int) p0);
    printf("addr arrPtr[0]     = %d\n", (int)p1);
    printf("dist arrPtr  p2-p1 = %d - %d = %d\n", (int)p2, (int)p1, (int)(p2 - p1));

    getc(stdin);
    return 0;
}


// ========== one possible output (absolute addresses may change)
//
//  for char arrHard[2][10] ...
//  sizeof arrHard        = 20
//  sizeof arrHard[0]     = 10
//  addr arrHard          = 6356752
//  addr arrHard[0]       = 6356752
//  dist arrHard  p2 - p1 = 6356762 - 6356752 = 10
//
//  for char * arrPtr[] ...
//  sizeof arrPtr        = 8
//  sizeof arrPtr[0]     = 4
//  addr arrPtr          = 6356744
//  addr arrPtr[0]       = 4214884
//  dist arrPtr  p2 - p1 = 4214890 - 4214884 = 6
//