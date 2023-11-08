#pragma once
#include <string>
#include "SFML/Graphics.hpp"



class Mobs {
public:
    Mobs(const std::string& initialNom, float initialHealth, int initialDamage, int initialSpeed, float initialPositionX, float initialPositionY, const std::string& textureFile);
    std::string GetNom() const;
    float GetHealth() const;
    int GetDamage() const;
    int GetSpeed() const;
    float GetPositionX() const;
    float GetPositionY() const;
    void Move(float distanceX, float distanceY);
    void Draw(sf::RenderWindow& window);
    void Delete() { delete this; }
    void UpdateSpritePosition();

private:
    std::string nom;
    float health;
    int damage;
    int speed;
    float position_x;
    float position_y;
    sf::Sprite sprite;
    sf::Texture texture;
};

class MobType1 : public Mobs {
public:
    MobType1(float initialPositionX, float initialPositionY);
    MobType1();
};

class MobType2 : public Mobs {
public:
    MobType2(float initialPositionX, float initialPositionY);
    MobType2();
};

class MobType3 : public Mobs {
public:
    MobType3(float initialPositionX, float initialPositionY);
    MobType3();
};

class Boss : public Mobs {
public:
    Boss(float initialPositionX, float initialPositionY);
    Boss();
};
