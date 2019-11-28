//
// Created by Weston on 11/3/2019.
//
#include "Armour.c"


#ifndef PLAYER_C
#define PLAYER_C

#define StartingStat 10
int playerData[8];
static int tempPlayerData[6];

void setTempPlayerData();

enum Stats {
    Health = 0, Strength, Agility, Defence, MagicDefence, Magic, Intel, Completed
};

char *returnStat(enum Stats stats) {
    switch (stats) {
        case Health:
            return "Health";
        case Strength:
            return "Strength";
        case Agility:
            return "Agility";
        case Defence:
            return "Defence";
        case Magic:
            return "Magic Attack";
        case MagicDefence:
            return "Magical Defence";
        case Intel:
            return "Intel";
        default:
            return "";
    }

}


void modPlayerStats(int stat, int statChange) {
    int *ptr = &playerData[stat];
    *ptr += statChange;
}

void setInitialPlayerStats() {
    int i;
    for (i = 0; i <= 8; i++) {
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
    int i = 0, j = 6;
    while (i <= 6) {
        sum += playerData[i];
        i++;
    }
    return sum / 6;
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