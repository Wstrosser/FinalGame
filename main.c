#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Player.c"
#include "Enemies.c"
#include "Misc.c"
#include "PrintOuts.c"
#include "PlayerPrompts.c"
#include "Armour.c"
#include "Map.c"
#include "MapInteraction.c"

void initailizingGame();

int main() {
    initailizingGame();
    //printIntroScreen();
    srand(time(0));
    int i = 0;
    while (i < 6) {

        shopArmour(i);
        printAllArmourEquipped();
        i++;
    }
    getchar();


}

void initailizingGame() {

    setInitialPlayerStats();
    setInitialEnemies();
}








