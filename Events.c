//
// Created by Weston on 11/19/2019.
//
#ifndef EVENTS_C
#define EVENTS_C


#include "Armour.c"
#include "Misc.c"

//TODO work on this a lot

enum godsBlessingID {
    Hermes = 0, Hephaestus, Ares, Cronos, Apollo,
    Dionysus, Prometheus, Poseidon, Hades, Zeus
};
typedef enum godsBlessingID ID;
struct godsBlessing {
    stats statOne;
    int statOneBoost;
    stats statTwo;
    int statTwoBoost;
    armourID armourId;
    int intelMin;
    double chanceForBlessing;
    double chanceForArmour;
    bool hasBlessed;
};
static struct godsBlessing godsArray[10] = {
        {Agility,  35, Intel,        15, Boots,
                                                     45,  75,  15, false}, //Hermes
        {Strength, 15, Defence,      15, Chestplate, 45,
                                                          75,  85, false}, //Hephaestus
        {Strength, 25, Health,       25, Legplates,
                                                     95,  15,  85, false}, //Ares
        {Strength, 10, Intel,        25, Helm,       105,
                                                          75,  25, false}, //Cronos
        {Health,   25, Intel,        20, Gloves,
                                                     85,  95,  10, false}, //Apollo
        {Defence,  15, MagicDefence, 15, Gloves,
                                                     45,  100, 85, false}, //Dionysus
        {Agility,  25, Intel,        35, Boots,
                                                     50,  28,  60, false},// Prometheus
        {Health,   15, MagicDefence, 35, Chestplate,
                                                     125, 85,  20, false}, //Poseidon
        {Defence,  35, MagicDefence, 25, Legplates,
                                                     65,  15,  85},//Hades
        {Strength, 45, Magic,        35, Helm,       105,
                                                          65,  15
        }
};

stats returnBoostOne(ID n) {
    return godsArray[n].statOne;
}

stats returnBoostTwo(ID n) {
    return godsArray[n].statTwo;
}

int returnBoostAmountOne(ID n) {
    return godsArray[n].statOneBoost;
}

int returnBoostAmountTwo(ID n) {
    return godsArray[n].statTwoBoost;
}

armourID returnArmourID(ID n) {
    return godsArray[n].armourId;
}

armour returnGodArmour(ID n) {
    armour newArmour;
    newArmour.statOne = returnBoostOne(n);
    newArmour.statTwo = returnBoostTwo(n);
    newArmour.boostValue = (returnBoostAmountOne(n) + returnBoostAmountTwo(n)) / 2;
    newArmour.armourSlot = returnArmourID(n);
    return newArmour;
}


#endif /* EVENTS_C */
