//
// Created by Weston on 11/3/2019.
//

#ifndef PLAYER_C
#define PLAYER_C

#include "Armour.c"
#include "Gods.c"
#include "Misc.c"
#include "PrintOuts.c"


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

void modPlayerStats(int stat, int statChange) {
    int *ptr = &playerData[stat];
    *ptr += statChange;
    setTempPlayerData();
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
    int i = 0;
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
    return tempPlayerData[(typeAttack == 0 ? 1 : 5)];
}

int getPCombatDefenceValue(int typeAttack) {
    return tempPlayerData[(typeAttack == 0 ? 3 : 4)];
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

void applyGodsArmour(int n) {
    armour newArmour = returnGodsArmour(n);
    setArmour(newArmour);
};


void printArmour(armour armour) {
    armourID temp = armour.armourSlot;
    printf("Found a %s that boosts %s and %s by %d.\n",
           returnArmourType(armour.armourSlot),
           returnStat(armour.statOne),
           returnStat(armour.statTwo),
           armour.boostValue);
    printf("Current %s boosts %s and %s by %d.\n",
           returnArmourType(temp),
           returnStat(playerArmour[temp].statOne),
           returnStat(playerArmour[temp].statTwo),
           playerArmour[temp].boostValue
    );
}
#endif /* PLAYER_C */
