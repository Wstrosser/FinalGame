#include <stdlib.h>

#ifndef ARMOUR_C
#define ARMOUR_C

//
// Created by Weston on 11/3/2019.
// TODO Delete and merge with Armour1
int getRandomArmourRarity(int rarity) {
    rarity = rand() % rarity;
    int numTwos = 1;
    while (rarity > 1) {
        numTwos++;
        rarity /= 2;
    }
    return numTwos;
}

int getRandomArmourType(int armour) {
    int armourType = armour % 6;
    int armourStats = 0;
    switch (armourType) {
        //Atk + Special +   Blessed Blade 1 5
        //Atk + Def +   	Spiked Shield 1 3
        //Def + SpD +	    Royal Robes   3 4
        //Agl + Def +	    Special Suit  2 3
        //Sp + Spd +	    Sacred Staff  4 5
        //H + Def +         Heavy Chest plate 0 3
        case 0:
            armourStats += 15;
            break;
        case 1:
            armourStats += 13;
            break;
        case 2:
            armourStats += 34;
            break;
        case 3:
            armourStats += 23;
            break;
        case 4:
            armourStats += 45;
            break;
        case 5:
            armourStats += 03;
        default:
            armourStats += 00;
    }
    return armourStats;

}

int getRandArmour(int avgStats) {
    int armour = 0;
    armour = (getRandomArmourRarity(avgStats) * 100) * (avgStats / 10) +
             getRandomArmourType(avgStats);

    return armour;
}

int getArmourBonusValue(int armour) {
    return armour / 100;
}

int getArmourStatOne(int armour) {
    return armour % 10;
}

int getArmourStatTwo(int armour) {
    return (armour % 100) / 10;
}


#endif /* ARMOUR_C */