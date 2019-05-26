#include <stdio.h>
/*Selectionsortimplementation: Die Menge der unsortierten Zahlen wird immer nach der kleinsten durchsucht und diese wird ans Ende der sortierten Zahlen angefügt.*/
/*Das Sortieren über zeiger ist mir leider nicht gelungen*/


int main(void) {
    unsigned short i;
    double unsorted[10];
    for (i=0; i<10; i++) {
        printf("Doublewert Nr %d eingeben: ", (i+1));
        scanf("%lf", &unsorted[i]); 
    }
    
    double smallest; 
    unsigned short index;
    unsigned short memorypointer;
        
    for (memorypointer=0; memorypointer < 10;memorypointer++) {
        smallest = unsorted[memorypointer];
        for (i=memorypointer+1;i<10;i++){
            if (unsorted[i] < smallest) {
                smallest = unsorted[i];
                index = i;
            }
        }
        if (smallest < unsorted [memorypointer]) {
            unsorted[index] = unsorted[memorypointer];
            unsorted[memorypointer] = smallest;
        }
    }
     for (i=0; i<10; i++) {
        printf("%lf\n", unsorted[i]);
    }
    printf("\n");
    return 0;
}
