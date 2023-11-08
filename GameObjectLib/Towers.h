#pragma once
#include <string>
#include "Vague.h"

class Towers {
public:
    Towers(const std::string& initialNom, int initialDamage, int initialRange, int initialAtkSpeed, int initialPrice, float initialPositionX, float initialPositionY) {
        nom = initialNom;
        damage = initialDamage;
        range = initialRange;
        atk_speed = initialAtkSpeed;
        price = initialPrice;
        position_x = initialPositionX;
        position_y = initialPositionY;
    }

private:
    std::string nom;
    int damage;
    int range;
    int atk_speed;
    int price;
    float position_x;
    float position_y;
};

