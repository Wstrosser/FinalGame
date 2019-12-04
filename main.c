#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Player.c"
#include "Enemies.c"
#include "Misc.c"
#include "PrintOuts.c"
#include "PlayerPrompts.c"
#include "Armour.c"


void initailizingGame();

int main() {
    initailizingGame();
    //printIntroScreen();
    printAllArmourEquipped();
    int i;
    for (i = 0; i < 10; i++) {
        applyGodsBoost(i);
    }
    printAllArmourEquipped();
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








