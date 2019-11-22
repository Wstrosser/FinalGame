#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Player.c"
#include "Enemies.c"
#include "Misc.c"
#include "PrintOuts.c"
#include "PlayerPrompts.c"
#include "Armour1.c"

#define StartingStat 10

void initailizingGame();

int main() {
    initailizingGame();
    /*printIntroScreen();
    combatScreen();
    */
    setFArmour();
    printAllArmourEquipped();
}

void initailizingGame() {

    setInitialPlayerStats(playerData);
    setInitialEnemies();
}








