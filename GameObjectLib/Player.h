#pragma once
#include "Vague.h"

class Player {
public:
    Player(int initialVie, int initialGold, int initialDiamond) {
        vie = initialVie;
        gold = initialGold;
        diamond = initialDiamond;
    }

private:
    int vie;
    int gold;
    int diamond;
};
