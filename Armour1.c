//
// Created by Weston on 11/21/2019.
//
#ifndef ARMOUR1_C
#define ARMOUR1_C
typedef struct Armour armour;
static armour playerArmour[5];
enum ArmourID {
    Helm = 0, Chestplate, Legplates, GlovesR, GlovesL, Weapon;
};
typedef enum ArmourID armourID;
struct Armour {
    int boostValue;
    int statOne;
    int statTwo;
    armourID armourSlot;
};

int getArmourBoost(armourID armourId) {
    return playerArmour[armourId].boostValue;
}

int getBoostedStatOne(armourID armourId) {
    return playerArmour[armourId].statOne;
}

int getBoostedStatTwo(armourID armourId) {
    return playerArmour[armourId].statOne;
}

void printAllArmourEquipped() {

}

#endif // ARMOUR1_c
