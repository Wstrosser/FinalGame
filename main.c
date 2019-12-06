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

void initailizingGame();

int main() {
    initailizingGame();
    //printIntroScreen();
    srand(time(0));
    int i = 0;
    for (i = 0; i < 10; i++) {
        combatScreen();
        hasGodsBlessing(1);
    }


}

void initailizingGame() {

    setInitialPlayerStats();
    setInitialEnemies();
}








