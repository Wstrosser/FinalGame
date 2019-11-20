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

int validatingInput(int max) {
    int choice = 0;
    do {
        scanf("%d", &choice);
        if (choice < 0 || choice > max) {
            printf("Please Enter a valid choice\n");
        }
    } while (isdigit(choice) && (choice < 0 || choice > 5));

};

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
        do {
            if (choice < 0 || choice > 5) {
                printf("Please Enter a valid choice\n");
            }
            scanf("%d", &choice);
        } while (isdigit(choice) && (choice < 0 || choice > 5));
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
    printDefending();
    int choice = 0;
    do {
        printf("\nEnter a valid choice\n");
        scanf("%d", &choice);
    } while (isdigit(choice) != 0 || choice < 0 || choice > 1);
    return choice;
} //Return 0 or 1 for defence choice
int getEnemyDefenceChoice() {
    return rand() % 2;
} //Return 0 or 1 for enemydefence choice
int getPlayerAttackChoice() {
    printPlayerAttack();
    int choice = 0;
    do {
        printf("\nEnter a valid choice\n");
        scanf("%d", &choice);
    } while (isdigit(choice) != 0 || choice < 0 || choice > 1);
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
    int maxSpeedTotal = getPlayerValueAtN(2) * getEnemyValueAtN(2);
    int speedE = maxSpeedTotal, speedP = maxSpeedTotal;
    do {
        system("clear");
        if (playerData[0] <= 0) {
            return 1;
        } else if (speedP == 0) {
            printCombatHeader();
            attackingTheEnemy();
            speedP = maxSpeedTotal;
            printf("Press ENTER key to Continue\n");
            getchar();
            getchar();
        } else {
            speedP -= getPlayerValueAtN(Agility);
        }
        if (enemies[0] < 1) {
            printf("\nThe enemy won't fight another day.\n");
            setInitialEnemies();
            return 0;
        } else if (speedE == 0) {
            printCombatHeader();
            attackingThePlayer();
            speedE = maxSpeedTotal;
            printf("Press ENTER key to Continue\n");
            getchar();
            getchar();
        } else {
            speedE -= getEnemyValueAtN(Agility);
        }

    } while (tempPlayerData[0] > 0 && enemies[0]);
}


#endif /*PLAYERPROMPTS_C*/
