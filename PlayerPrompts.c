//
// Created by Weston on 11/5/2019.
//
#ifndef PLAYERPROMPTS_C
#define PLAYERPROMPTS_C

#include "PrintOuts.c"
#include "Player.c"
#include "Enemies.c"
#include "Misc.c"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


void addStatPoint(int nSkillPoints) {
    int choice = 0;
    if (nSkillPoints > 1) {
        printf("You have received %d skill points.\n", nSkillPoints);
    } else {
        printf("You have received a skill.\n");
    }
    printf("What skill would you like to upgrade?\n");
    do {
        printPlayerHeader(playerData);
        printStatUpgrade();
        choice = returnValidImport(6);
        if (choice == -1) {
            continue;
        }
        addSkillPoint(choice);
        nSkillPoints--;
        if (nSkillPoints > 1) {

            printf("Remaining skill point :%d\n", nSkillPoints);
        }
    } while (nSkillPoints > 0);
}

int getEnemyAttackChoice() {
    return rand() % 2;
} //Return 0 or 1 for enemyAttack Choice
int getPlayerDefenceChoice() {
    int choice;
    do {
        printDefending();
        choice = returnValidImport(1);
    } while (choice == -1);
    return choice;
} //Return 0 or 1 for defence choice
int getEnemyDefenceChoice() {
    return rand() % 2;
} //Return 0 or 1 for enemydefence choice
int getPlayerAttackChoice() {
    int choice;
    do {
        printPlayerAttack();
        choice = returnValidImport(1);
    } while (choice == -1);
    return choice;
} //Return 0 or 1 for attack choice
int returnDamage(int a, int d, double m) {
    double damage = (a * 10) / (d + 10) * m;
    return returnRoundedFloat((float) damage);
}

void attackingThePlayer() {
    int attackChoice = getEnemyAttackChoice();
    int defChoice = getPlayerDefenceChoice();
    double m;
    if (attackChoice == defChoice) {
        printf("The enemy blindsided you.\n");
        m = 0.75;
    } else {
        m = 0.25;
    }
    int dmg = returnDamage(
            getECombatAttackValue(attackChoice),
            getPCombatDefenceValue(defChoice),
            m
    );
    tempPlayerData[0] -= dmg;
    printf("%s%d damage.\n", "The enemy hit you for ", dmg);
}

void attackingTheEnemy() {
    int attackChoice = getPlayerAttackChoice();
    int defChoice = getEnemyDefenceChoice();
    double m;
    if (attackChoice == defChoice) {
        m = 0.25;
    } else {
        printf("You blindsided the enemy.\n");
        m = 0.75;
    }
    int dmg = returnDamage(
            getPCombatAttackValue(attackChoice),
            getECombatDefenceValue(defChoice),
            m
    );
    enemies[0] -= dmg;
    printf("%s%d damage.\n", "You a hit the enemy for ", dmg);
}

int combatScreen() { //Return 0 if the player continues and 1 if not
    setInitialEnemies();
    setTempPlayerData();
    placeArmourOnTemp();
    int speedAp = getPlayerValueAtN(Agility) / 10 + 1, speedAe = getEnemyValueAtN(Agility) / 10 + 1;
    int maxSpeedTotal = returnLCM(speedAp, speedAe);
    int speedE = maxSpeedTotal, speedP = maxSpeedTotal;

    do {
        system("clear");
        if (tempPlayerData[Health] <= 0) {
            return 1;
        } else if (speedP <= speedAp) {
            printCombatHeader(tempPlayerData, enemies);
            attackingTheEnemy();
            speedP = maxSpeedTotal;
            printf("Press ENTER key to Continue\n");
            getchar();
            getchar();
        } else {
            speedP -= speedAp;
        }
        if (enemies[Health] < 1) {
            printf("\nThe enemy won't fight another day.\n");
            printf("You received %d gold", avgBaseStats());
            modPlayerStats(7, avgBaseStats());
            return 0;
        } else if (speedE <= speedAe) {
            printCombatHeader(tempPlayerData, enemies);
            attackingThePlayer();
            speedE = maxSpeedTotal;
            printf("Press ENTER key to Continue\n");
            getchar();
            getchar();
        } else {
            speedE -= speedAe;
        }

    } while (tempPlayerData[0] > 0 && enemies[0]);
}

void swapArmourPrompt(armour armour) {
    printArmour(armour);
    printArmourSwap();
    int choice = returnValidImport(1);
    if (choice == 0) {
        printf("Armour Swapped\n");
        setArmour(armour);
    } else {
        printf("Armour Not Swapped\n");
    }
}

void hasGodsBlessing(int n) {
    char *GodsName = returnGodBlessing(n);
    if (hasBlessing(n) == true) {
        printGodsBlessing(GodsName);
        if (receiveArmour(n) == true) {
            printGodBlessedWArmour();
            swapArmourPrompt(returnGodsArmour(n));
        } else {
            printGodBlessedWStat();
            returnStatBlessing(playerData, n);
        }
    }
}

#endif /*PLAYERPROMPTS_C*/
