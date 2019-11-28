#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Player.c"
#include "Enemies.c"
#include "Misc.c"
#include "PrintOuts.c"
#include "PlayerPrompts.c"
#include "Armour1.c"



void initailizingGame();

int main() {
    initailizingGame();
    //printIntroScreen();
    int i = 0;
    while (i < 16) {
        if (combatScreen() == 1)
            break;
        i++;
    }

    return 0;
    /*
    setFArmour();
    printAllArmourEquipped();
*/
}

void initailizingGame() {

    setInitialPlayerStats();
    setInitialEnemies();
}








