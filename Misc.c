//
// Created by Weston on 11/5/2019.
//

#include <stdio.h>
#include <stdlib.h>

#ifndef MISC_C
#define MISC_C


void printIntArray(int array[], int sizeArray) {
    int i;
    for (i = 0; i < sizeArray; i++) {
        printf("Number %d: %d, ", i, array[i]);
    }
    printf("\n");
}

int getRootRoundedUp(int n) {
    int i;
    for (i = 0; i * i < n; i++) {

    }
    return i;
}

int returnRoundedFloat(float n) {
    int i = 0;
    for (i = 0; i < n; i++) {}
    return i;
}

#endif /* MISC_C */
