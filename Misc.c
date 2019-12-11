//
// Created by Weston on 11/5/2019.
//

#include <stdio.h>
#include <stdlib.h>

#ifndef MISC_C
#define MISC_C
typedef enum {
    false, true
} bool;

char *boolPrint(bool b) {
    return b == false ? "false" : "true";
}

enum Stats;

char *returnStat(enum Stats stats);

int max(int x, int y){
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

int fib(int n) {
    int a = 0, b = 1, c, i;
    if (n == 0)
        return a;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int return2Power(int n) {
    int i = 2;
    int number = 1;
    while (i < n) {
        i *= 2;
        number++;
    }
    return number;
}
#endif /* MISC_C */
