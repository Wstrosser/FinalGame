//
// Created by Weston on 11/3/2019.
//

#ifndef PLAYER_C
#define PLAYER_C

#include "Armour.c"
#include "Events.c"


#define StartingStat 10
int playerData[8];
/* 0-> Health
 * 1-> Strength
 * 2-> Speed
 * 3-> Defence
 * 4-> Magic Def
 * 5-> Magic Attack
 * 6-> Intel
 * 7-> Gold
 * 8-> Score
 * */
static int tempPlayerData[6];

void setTempPlayerData();

enum Stats;
typedef enum Stats stats;

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

void addSkillPoint(int stat) {
    int *ptr = playerData;
    *(ptr + stat) += 1;
    setTempPlayerData();
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
        return tempPlayerData[1];
    } else if (typeAttack == 1) {
        return tempPlayerData[5];
    } else return 0;
}

int getPCombatDefenceValue(int typeAttack) {
    if (typeAttack == 0) {
        return tempPlayerData[3];
    } else if (typeAttack == 1) {
        return tempPlayerData[4];
    } else return 0;
}

void placeArmourOnTemp() {
    int i;
    for (i = 0; i <= 5; i++) {
        tempPlayerData[
                playerArmour[i].statOne] += playerArmour[i].boostValue;
        tempPlayerData[
                playerArmour[i].statTwo] += playerArmour[i].boostValue;
    }
}

void applyGodsBoost(int n) {
    setArmour(returnGodArmour(n));
};
#endif /* PLAYER_C */