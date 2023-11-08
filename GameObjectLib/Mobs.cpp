#include "Mobs.h"
#include <iostream>


Mobs::Mobs(const std::string& initialNom, float initialHealth, int initialDamage, int initialSpeed, float initialPositionX, float initialPositionY, const std::string& textureFile)
    : nom(initialNom), health(initialHealth), damage(initialDamage), speed(initialSpeed), position_x(initialPositionX), position_y(initialPositionY) {
    // Chargez la texture à partir du fichier
    if (!texture.loadFromFile(textureFile)) {
        std::cout << "erreur de chargement de la texture";
    }

    // Configurez le sprite avec la texture chargée
    sprite.setTexture(texture);
    sprite.setScale(3.0f, 3.0f);
}
std::string Mobs::GetNom() const {
    return nom;
}

float Mobs::GetHealth() const {
    return health;
}

int Mobs::GetDamage() const {
    return damage;
}

int Mobs::GetSpeed() const {
    return speed;
}

float Mobs::GetPositionX() const {
    return position_x;
}

float Mobs::GetPositionY() const {
    return position_y;
}

void Mobs::Move(float distanceX, float distanceY) {
    // Implémentez le déplacement spécifique à MobType1 ici
    // Par exemple, déplacez-le uniquement de gauche à droite
    position_x += distanceX;
    position_y += distanceY;
}

void Mobs::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Mobs::UpdateSpritePosition() {
    // Assurez-vous d'associer correctement la position du sprite à la position du mob
    sprite.setPosition(position_x, position_y);
}


MobType1::MobType1() : Mobs("Mob de type 1", 100.0f, 10, 5, 0.0f, 0.0f, "../Assets/img/Mob1.png") {
}

MobType2::MobType2() : Mobs("Mob de type 2", 120.0f, 15, 6, 100.0f, 100.0f, "../Assets/img/Mob2.png") {
}

MobType3::MobType3() : Mobs("Mob de type 3", 80.0f, 8, 7, 200.0f, 200.0f, "../Assets/img/Mob3.png") {
}

Boss::Boss() : Mobs("Boss", 500.0f, 50, 4, 300.0f, 300.0f, "../Assets/img/Boss.png") {
}