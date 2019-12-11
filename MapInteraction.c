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
            printf("The gods are not accepting challengers right now.\n");
            //todo Combat of the Gods
            break;

    }

}

void shopEvent(int subType) {
    printShop(returnArmourType(subType));
    int choice = returnValidImport(1);
    if (choice == 0) {
        shopArmour(subType);
    }

}

void homeEvent(int subType) {
    printHome();
    int choice = returnValidImport(1);
    if (choice == 0) {
        printf("The home owner offered some training.\n");
        addStatPoint(subType);
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

void movePlayer() {
    int x = 15, y = 15, movesLeft = getPlayerValueAtN(Agility), movementCost = 1;
    printf("You were place in the center of town to explore until nightfall.\n"
           "It will become harder to move a you began to explore.\n");
    map[x][y].containsPlayer = true;
    while (movesLeft > movementCost) {
        printCardinalTile(returnTileType(map[x + 1][y].TileType),
                          returnTileType(map[x][y + 1].TileType),
                          returnTileType(map[x - 1][y].TileType),
                          returnTileType(map[x][y - 1].TileType));
        int choice = returnValidImport(3);
        switch (choice) {
            case 0:
                if (map[x + 1][y].passable == true) {
                    x++;
                    break;
                }
                continue;
            case 1:
                if (map[x][y + 1].passable == true) {
                    y++;
                    break;
                }
                continue;
            case 2:
                if (map[x - 1][y].passable == true) {
                    x--;
                    break;
                }
                continue;
            case 3:
                if (map[x][y - 1].passable == true) {
                    y--;
                    break;
                }
                continue;
        }
        clear();
        activateEvent(map[x][y]);
        movesLeft -= movementCost;
        movementCost++;

    }
    printf("Night fall has occurred, Good Night.\n");
    getchar();
    clear();
}

#endif /* MAPINTERACTION_C */
