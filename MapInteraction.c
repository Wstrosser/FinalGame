//
// Created by Weston on 12/10/2019.
//

#ifndef MAPINTERACTION_C
#define MAPINTERACTION_C

#include "Map.c"
#include "Gods.c"
#include "PrintOuts.c"
#include "PlayerPrompts.c"

void statueEvent(int subType) {
    printGodsStatue(returnGodBlessing(subType));
    int choice = returnValidImport(2);
    switch (choice) {
        case 0:
            hasGodsBlessing(subType);
            break;
        case 1:
            break;
        case 2:
            //todo Combat of the Gods
            break;

    }

};

void shopEvent(int subType) {
    printShop(returnArmourType(subType));
    int choice = returnValidImport(1);
    if (choice == 1) {
        shopArmour(subType);
    }

}

void homeEvent(int subType) {
    printHome();
    int choice = returnValidImport(1);
    if (choice == 1) {
        //todo HomeEvent Random between .75 Good and .25 Bad
    }
}

void activateEvent(Tile currentTile) {
    if (currentTile.TileType != road) {
        switch (currentTile.TileType) {
            case statue:
                statueEvent(currentTile.tileSubType);
                break;
            case shop:
                shopEvent(currentTile.tileSubType);
                break;
            case home:
                homeEvent(currentTile.tileSubType);

        }
    }
}


#endif /* MAPINTERACTION_C */
