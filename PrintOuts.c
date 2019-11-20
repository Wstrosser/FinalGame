//
// Created by Weston on 11/9/2019.
//
#ifndef PRINTOUT_C
#define PRINTOUT_C

void printIntroScreen() {
    printf("Fight for the Right by Weston\n"
           "_______________________________\n\n");
    printf("Press ENTER key to Continue\n");
    getchar();
    printf(
            "In this game, you have been sentenced\n"
            "to a life of fighting for other's amusement\n"
            "with a few catches.\n"
            "_______________________________\n\n");
    printf("Press ENTER key to Continue\n");
    getchar();
    printf(
            "When you wake each morning, you will have\n"
            "fight an on par opponent. If you live\n"
            "you are given some freedoms until nightfall.\n"
            "Your health is restored at the end of each night.\n"
            "End of game can occur anywhere, in the arena or market\n"
            "At any prompts, you can press [/] for Information,\n"
            "[*] for equipment, and this game is\n"
            "meant to be played with a numpad.\n "
            "_______________________________\n\n");
    printf("Press ENTER key to Continue\n");
    getchar();
    system("clear");
}

void printPlayerHeader(int *array) {
    printf("Player Stats -\t");
    printf("%d:Health\t", array[0]);
    printf("%d:Strength\t", array[1]);
    printf("%d:Agility\t", array[2]);
    printf("%d:Defence\t", array[3]);
    printf("%d:MagicDefence\t", array[4]);
    printf("%d:Magic\t\n", array[5]);
}

void printEnemyHeader(int *array) {
    printf("Enemy Stats -\t ");
    printf("%d:Health\t", array[0]);
    printf("%d:Strength\t", array[1]);
    printf("%d:Agility\t", array[2]);
    printf("%d:Defence\t", array[3]);
    printf("%d:MagicDefence\t", array[4]);
    printf("%d:Magic\t\n", array[5]);
}

void printDefending() {
    printf("The Enemy is getting ready to attack!\nHow would you like to defend?\n");
    printf("[0] Physical\n[1] Magic");
}

void printPlayerAttack() {
    printf("You can attack.\nPick your choice of attack\n");
    printf("[0] Physical\n[1] Magic");
}

void printStatUpgrade() {
    printf("Press the number for the skill you would like to upgrade\n");
    printf("[0] Health\n");
    printf("[1] Strength\n");
    printf("[2] Agility\n");
    printf("[3] Defence\n");
    printf("[4] MagicDefence\n");
    printf("[5] MagicAttack\n");
}

void printCombatHeader() {
    system("clear");
    printPlayerHeader(tempPlayerData);
    printEnemyHeader(enemies);
}

void printEndGame() {
    system("clear");
    printf("Thank you for playing.\n");
}

#endif // PRINTOUT_C

