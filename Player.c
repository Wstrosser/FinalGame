//
// Created by Weston on 11/3/2019.
//
#include "Armour.c"


#ifndef PLAYER_C
#define PLAYER_C

#define StartingStat 10
static int playerData[10];
static int tempPlayerData[6];

void setTempPlayerData();

enum stats {
    Health = 0, Strength, Agility, Defence, MagicDefence, Magic, Intel, Equipment, Pet, Completed
};


void modPlayerStats(int stat, int statChange) {
    int *ptr = &playerData[stat];
    *ptr += statChange;
}

void setInitialPlayerStats(int pInt[10]) {
    int i;
    for (i = 0; i <= 10; i++) {
        if (i <= 6) {
            int *ptr = &playerData[i];
            *ptr = StartingStat;
        } else {
            int *ptr = &playerData[i];
            *ptr = 0;
        }
    }
    setTempPlayerData();
}

int avgBaseStats() {
    int sum = 0;
    int i = 6, j = 6;
    while (i > 0) {
        sum += playerData[i];
        i--;
    }
    return sum / j;
}

void removeArmour() {
    if (playerData[8] != 0) {
        int armourValue = playerData[8];
        int statOne = getArmourStatOne(armourValue);
        int statTwo = getArmourStatTwo(armourValue);
        playerData[statOne] -= getArmourBonusValue(armourValue);
        playerData[statTwo] -= getArmourBonusValue(armourValue);
    }
}

void equipArmour() {
    int armourValue = playerData[8];
    int statOne = getArmourStatOne(armourValue);
    int statTwo = getArmourStatTwo(armourValue);
    playerData[statOne] += getArmourBonusValue(armourValue);
    playerData[statTwo] += getArmourBonusValue(armourValue);
}

void setArmour(int armour) {
    int *ptr = &playerData[8];
    if (armour != playerData[8]) {
        removeArmour();
        *ptr = armour;
        equipArmour();
    }
}

void addSkillPoint(int stat) {
    int *ptr = playerData;
    *(ptr + stat) += 1;
    setTempPlayerData();
}

void addRandomArmour() {
    int randomArmour = getRandArmour(avgBaseStats());
}

void setTempPlayerData() {
    int i = 0;
    for (i = 0; i <= 5; i++) {
        tempPlayerData[i] = playerData[i];
    }
}

int getPlayerValueAtN(int n) {
    return playerData[n];
}

int getPCombatAttackValue(int typeAttack) {
    if (typeAttack == 0) {
        return playerData[1];
    } else if (typeAttack == 1) {
        return playerData[5];
    } else return 0;
}

int getPCombatDefenceValue(int typeAttack) {
    if (typeAttack == 0) {
        return playerData[3];
    } else if (typeAttack == 1) {
        return playerData[4];
    } else return 0;
}


#endif /* PLAYER_C */