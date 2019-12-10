//
// Created by Weston on 11/4/2019.
//
#ifndef ENEMIES_C
#define ENEMIES_C

#include "Player.c"
#include "Misc.c"

int getSumEnemiesStats();

int enemies[6];

void setInitialEnemies() {
    int avgStats = avgBaseStats();
    int *ptr = enemies;
    int i;
    for (i = 0; i <= 6; i++) {
        int r = rand() % (2 * getRootRoundedUp(avgStats));
        switch (i) {
            case 0 :
                *ptr = (avgStats + getRootRoundedUp(avgStats) - r);
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5 :
                *(ptr + i) = 2 * (avgStats) + getRootRoundedUp(avgStats) - r - *(ptr + i - 1);
                break;
            case 6:
                *(ptr + i) = avgStats * 6 - getSumEnemiesStats();
            default:
                break;

        }
    }

}

int getSumEnemiesStats() {
    int avg = 0, i = 0;
    for (i = 0; i < 6; i++) {
        avg += enemies[i];
    }
    return avg;
}

int getEnemyValueAtN(int n) {
    return enemies[n];
}

int getECombatAttackValue(int typeAttack) {
    if (typeAttack == 0) {
        return enemies[1];
    } else if (typeAttack == 1) {
        return enemies[5];
    } else return 0;
}

int getECombatDefenceValue(int typeAttack) {
    if (typeAttack == 0) {
        return enemies[3];
    } else if (typeAttack == 1) {
        return enemies[4];
    } else return 0;
}

#endif //ENEMIES_C