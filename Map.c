//
// Created by Weston on 12/5/2019.
//
#ifndef MAP_C
#define MAP_C

#include "Misc.c"

enum tiletype {
    blank = 0, road, statue, home, fountain, shop
};
typedef enum tiletype tileType;

char *returnTileType(tileType TT) {
    switch (TT) {
        case blank:
            return "Blank";
        case road:
            return "Road";
        case statue:
            return "Statue";
        case home:
            return "Home";
        case fountain:
            return "Fountain";
        case shop:
            return "Shop";
    }
}

struct tile {
    int xPos;
    int yPos;
    tileType TileType;
    int tileSubType;
    bool passable;
    bool containsPlayer;
};
typedef struct tile Tile;
static struct tile map[31][31];

bool validTilePlacement(int x, int y) {
    if (map[x][y].TileType != blank) {
        return false;
    }
    if (map[x + 1][y].TileType == road) {
        return true;
    } else if (map[x - 1][y].TileType == road) {
        return true;
    } else if (map[x][y - 1].TileType == road) {
        return true;
    } else if (map[x][y + 1].TileType == road) {
        return true;
    }
    return false;

}

void setStatues() {
    Tile tileTemp;
    int i;
    for (i = 0; i <= 10;) {
        int x = (rand() % 30) + 1, y = (rand() % 30) + 1;
        if (validTilePlacement(x, y) == true) {
            tileTemp.xPos = x;
            tileTemp.yPos = y;
            tileTemp.TileType = statue;
            tileTemp.tileSubType = i;
            tileTemp.passable = true;
            tileTemp.containsPlayer = false;
            map[x][y] = tileTemp;
            i++;

        }
    }
}

void createPath() {
    int i;
    struct tile pathTile;
    pathTile.TileType = road;
    pathTile.passable = true;
    pathTile.tileSubType = 0;
    pathTile.containsPlayer = false;

    for (i = 0; i <= 30; i += 5) {
        int j = 0;
        for (j = 0; j <= 30; j++) {
            pathTile.xPos = i;
            pathTile.yPos = j;
            map[i][j] = pathTile;
            pathTile.xPos = j;
            pathTile.yPos = i;
            map[j][i] = pathTile;

        }
    }
}

void setMarkets() {
    Tile tileTemp;
    int i, j;
    for (j = 0; j < 5; j++) {
        for (i = 0; i <= 6;) {
            int x = (rand() % 30) + 1, y = (rand() % 30) + 1;
            if (validTilePlacement(x, y) == true) {
                tileTemp.xPos = x;
                tileTemp.yPos = y;
                tileTemp.TileType = shop;
                tileTemp.tileSubType = i;
                tileTemp.passable = true;
                tileTemp.containsPlayer = false;
                map[x][y] = tileTemp;
                i++;

            }
        }
    }
}

void printMap() {

    createPath();
    setMarkets();
    setStatues();
    int i, j;
    for (i = 0; i <= 30; i++) {
        for (j = 0; j <= 30; j++) {
            printf("| %d.%d ", map[i][j].TileType, map[i][j].tileSubType);
        }
        printf("\n");
    }
}

#endif /*MAP_C*/

