//
// Created by Weston on 11/21/2019.
//

#ifndef ARMOUR1_C
#define ARMOUR1_C

#include "Player.c"


/*TODO add random generated Armour
        merge player Array with Armour array
        create a way for enemies to have armour
 */
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
            return "Gloves";
        case Boots:
            return "Boots";
        case Weapon:
            return "Weapon";
        default:
            return "Null";
    }
}

enum Stats {
    Health = 0, Strength, Agility, Defence, MagicDefence, Magic, Intel, Completed
};
typedef enum Stats stats;

typedef struct Armour {
    int boostValue;
    stats statOne;
    stats statTwo;
    armourID armourSlot;
} armour;
static armour playerArmour[6] = {};

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


void setFArmour() {
    armour NewArmour = {13, Agility, Strength, Helm};
    playerArmour[0] = NewArmour;
    armour NewArmour2 = {8, Health, Magic, Chestplate};
    playerArmour[1] = NewArmour2;
}

void setArmour(armour newArmour) {
    playerArmour[newArmour.armourSlot] = newArmour;
}

#endif // ARMOUR1_c
