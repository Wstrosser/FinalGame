//
// Created by Weston on 11/21/2019.
//

#ifndef ARMOUR1_C
#define ARMOUR1_C

#include "Player.c"
#include "Misc.c"

/*TODO add random generated Armour
        merge player Array with Armour array
        create a way for enemies to have armour
 */
int getPlayerValueAtN(int n);

typedef enum ArmourID armourID;

enum ArmourID {
    Helm, Chestplate, Legplates, Gloves, Boots, Weapon
};

char *returnArmourType(armourID armourId) {
    switch (armourId) {
        case Helm:
            return "Helm";
        case Chestplate:
            return "Chestplate";
        case Legplates:
            return "Legplates";
        case Gloves:
            return "Pair of Gloves";
        case Boots:
            return "Pair of Boots";
        case Weapon:
            return "Weapon";
        default:
            return "Null";
    }
}

enum Stats {
    Health = 0, Strength, Agility, Defence, MagicDefence, Magic, Intel, Completed
};


char *returnStat(enum Stats stats) {
    switch (stats) {
        case Health:
            return "Health";
        case Strength:
            return "Strength";
        case Agility:
            return "Agility";
        case Defence:
            return "Defence";
        case Magic:
            return "Magic Attack";
        case MagicDefence:
            return "Magical Defence";
        case Intel:
            return "Intel";
        default:
            return "";
    }

}

typedef enum Stats stats;

typedef struct Armour {
    int boostValue;
    stats statOne;
    stats statTwo;
    armourID armourSlot;
} armour;
static armour playerArmour[6];

int getArmourBoost(armourID armourId) {
    return playerArmour[armourId].boostValue;
}

int getBoostedStatOne(armourID armourId) {
    return playerArmour[armourId].statOne;
}

int getBoostedStatTwo(armourID armourId) {
    return playerArmour[armourId].statTwo;
}

void printAllArmourEquipped() {
    int i;
    for (i = 0; i <= 5; i++) {
        printf("Slot id: %d BonusValue: %d "
               "StatOne: %d StatTwo: %d \n",
               i,
               getArmourBoost(i),
               getBoostedStatOne(i),
               getBoostedStatTwo(i));

    }
}

void printSwapArmour(armour armour) {
    armourID temp = armour.armourSlot;
    printf("Found a %s that boosts %s and %s by %d.\n",
           returnArmourType(armour.armourSlot),
           returnStat(armour.statOne),
           returnStat(armour.statTwo),
           armour.boostValue);
    printf("Current %s boosts %s and %s by %d.\n",
           returnArmourType(temp),
           returnStat(playerArmour[temp].statOne),
           returnStat(playerArmour[temp].statTwo),
           playerArmour[temp].boostValue
    );
}

void printArmour(armour *armour) {
    int i = 0;
    while (i < 3) {

        printf("[%d] %s that boosts %s and %s by %d.\n",
               i,
               returnArmourType(armour[i].armourSlot),
               returnStat(armour[i].statOne),
               returnStat(armour[i].statTwo),
               armour[i].boostValue);
        i++;
    }
    printf("[3] Leave Shop\n");
}

void setArmour(armour newArmour) {
    armourID temp = newArmour.armourSlot;
    playerArmour[temp] = newArmour;
}

int avgArmourStats() {
    int sum = 0, i;
    for (i = 1; i <= 6; i++) {
        sum += playerArmour[i].boostValue;
    }
    return sum / 6;

}

int returnValidImport(int maxChoice);

void swapArmourPrompt(armour armour);

void shopArmour(armourID id) {
    armour shopArmour[3];
    int i = 0;
    while (i < 3) {
        int maxBoostValue = avgArmourStats() * 1.25;
        shopArmour[i].armourSlot = id;
        shopArmour[i].boostValue = rand() % maxBoostValue + 10;
        shopArmour[i].statTwo = rand() % 7;
        shopArmour[i].statOne = rand() % 7;
        i++;
    }
    printArmour(shopArmour);
    int choice = returnValidImport(3);
    if (choice != 3) {
        swapArmourPrompt(shopArmour[choice]);
    }
}

#endif // ARMOUR1_c
