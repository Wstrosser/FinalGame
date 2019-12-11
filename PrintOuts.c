//
// Created by Weston on 11/9/2019.
//
#ifndef PRINTOUT_C
#define PRINTOUT_C

void printStatInfoScreen();

void clear() {
    printf("\nPress ENTER key to Continue\n");
    getchar();
    system("clear");
}

int returnValidImport(int maxChoice) {
    char choice;
    do {
        printf("Enter a valid choice\n");
        scanf(" %c", &choice);
        if (choice == '/') {
            printStatInfoScreen();
            return -1;
        }

    } while (choice < 48 || choice > 48 + maxChoice);
    return (choice - 48);
}

void printIntroScreen() {
    printf("Fight for the Right by Weston\n"
           "_______________________________\n\n");
    clear();
    printf(
            "In this game, you have been sentenced\n"
            "to a life of fighting for other's amusement\n"
            "with a few catches.\n"
            "_______________________________\n\n");
    clear();
    printf(
            "When you wake each morning, you will have\n"
            "fight an on par opponent. If you live\n"
            "you are given some freedoms until nightfall.\n"
            "Your health is restored at the end of each night.\n"
            "End of game can occur anywhere, in the arena or market\n"
            "At any prompts, you can press [/] for Information on stats,\n"
            "[*] for equipment, and this game is\n"
            "meant to be played with a numpad.\n "
            "_______________________________\n\n");
    clear();
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
    printf("[0] Physical\n[1] Magic\n");
}

void printPlayerAttack() {
    printf("You can attack.\nPick your choice of attack\n");
    printf("[0] Physical\n[1] Magic\n");
}

void printStatUpgrade() {
    printf("Press the number for the skill you would like to upgrade\n");
    printf("[0] Health\n");
    printf("[1] Strength\n");
    printf("[2] Agility\n");
    printf("[3] Defence\n");
    printf("[4] MagicDefence\n");
    printf("[5] MagicAttack\n");
    printf("[6] Intel\n");
}

void printCombatHeader(int tempPlayerData[], int enemies[]) {
    system("clear");
    printPlayerHeader(tempPlayerData);
    printEnemyHeader(enemies);
}

void printEndGame() {
    system("clear");
    printf("Thank you for playing.\n");
}

void printStatInfoScreen() {
    printf("Health: \tthe amount of damage you can take before a game over\n"
           "Strength: \tthe amount of damage you can deal with a physical attack\n"
           "Agility: \ta number to determine how often you can attack in combat\n"
           "Defence: \tthe amount the damage can be reduced by when physically attacked\n"
           "Magic Defence:\tthe amount the damage can be reduced by when magically attacked\n"
           "Magic Attack: \tthe amount of damage you can deal with a magical attack\n"
           "Intel: \ta number used in random events and determine the skill points granted\n");
    getchar();
    clear();
}

void printMainMenu() {
    printf("Would you like to start a new game?\n"
           "[0] Start New Game\n"
           "[1] Continue Game\n"
           "[2] Quit Game\n");
}

void printGodsBlessing(char *c) {
    printf("You have received %s blessing\n", c);
}

void printGodBlessedWStat() {
    printf("The gods have blessed your stats\n");
}

void printGodBlessedWArmour() {
    printf("The gods have blessed you with armour.\n");
}

void printArmourSwap() {
    printf("Would you like to swap your current armour?\n"
           "[0] Yes\n"
           "[1] No\n");

}

void printGodsStatue(char *gods) {
    printf("You approach the statue of %s.\n"
           "What would you like to do?\n"
           "[0] Request a blessing\n"
           "[1] Leave the statue\n"
           "[2] Challenge the god\n", gods);

}

void printShop(char *shopType) {
    printf("You approach a %s shop.\n"
           "What would you like to do?\n"
           "[0] See what the shop has to offer\n"
           "[1] Leave\n", shopType);

}

void printHome() {
    printf("You approach a home.\n"
           "What would you like to do?\n"
           "[0] Knock on the door\n"
           "[1] Leave\n");

}

void printCardinalTile(char *north, char *east, char *south, char *west) {
    printf("What direction would you like to go?\n");
    printf("[0] %s is north\n"
           "[1] %s is east\n"
           "[2] %s is south\n"
           "[3] %s is west\n",
           north, east, south, west);


}
#endif // PRINTOUT_C

