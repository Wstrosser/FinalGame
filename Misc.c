//
// Created by Weston on 11/5/2019.
//

#include <stdio.h>
#include <stdlib.h>

#ifndef MISC_C
#define MISC_C

int max(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

int min(int x, int y) {
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

int returnLCM(int x, int y) {
    int lar = max(x, y);
    int small = min(x, y);
    int i;
    for (i = lar;; i += lar) {
        if (i % small == 0)
            return i;
    }
}


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
