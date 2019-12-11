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
    while (i == 0) {
        i = combatScreen();
        if (i == 1) {
            break;
        }
        movePlayer();

    }


}

void initailizingGame() {

    setInitialPlayerStats();
    setInitialEnemies();
    initailGrid();
}








