//
// Created by Weston on 11/5/2019.
//
#ifndef DICE_C
#define DICE_C

#include <stdlib.h>

int rollDie(int sides) {
    //srand(time(0));
    return (rand() % sides + 1);
}

int sumOfRolls(int nDices, int sides) {
    int sum = 0, i = 0;
    for (i = 0; i < nDices; i++) {
        sum += rollDie(sides);
    }
    return sum;
}

#endif /* DICE_C */
