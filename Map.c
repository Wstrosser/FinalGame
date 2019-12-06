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
} Tile;
static struct tile map[30][30];

void setStatues() {
    int i;
    for (i = 0; i <= 10;) {
        int x = (rand() % 30) + 1, y = (rand() % 30) + 1;
        if (map[x][y].TileType == 0) {
            Tile.xPos = x;
            Tile.yPos = y;
            Tile.TileType = statue;
            Tile.tileSubType = i;
            Tile.passable = false;
            Tile.containsPlayer = false;
            map[x][y] = Tile;
            i++;
        }
    }
}

void setShops() {

}

#endif /*MAP_C*/

