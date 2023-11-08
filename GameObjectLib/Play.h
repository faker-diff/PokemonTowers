#pragma once
#include <SFML/Graphics.hpp>
#include "Healthbar.h"
#include "Mobs.h"
#include "Player.h"
#include "Towers.h"
#include "Vague.h"



void Play(sf::RenderWindow& window) {

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("../Assets/img/background.png")) {
       
    }

    sf::Sprite backgroundImage;
    backgroundImage.setTexture(backgroundTexture);

    // Créez une instance de Vague avec des paramètres spécifiés 
    Vague vague1(1, 1, 1, 1);

    const std::vector<Mobs*>& mobsList = vague1.GetMobsList();
    sf::Clock clock;
    int currentMobIndex = 0;

    // Crée un texte pour afficher dans la boîte de dialogue
    sf::Font font;
    if (!font.loadFromFile("../Assets/font/arial.ttf")) {
        
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        // Vérifiez si le mob actuel est mort ou a dépassé 800 pixels en X
        if (currentMobIndex < mobsList.size()) {
            Mobs* mob = mobsList[currentMobIndex];

            if (mob->GetHealth() > 0 && mob->GetPositionX() < 1900) {
                // Déplacez et affichez le mob
                sf::Time deltaTime = clock.restart();
                float distance = mob->GetSpeed() * deltaTime.asSeconds();
                mob->Move(distance, 0);

                mob->UpdateSpritePosition();
                mob->Draw(window);
                window.display();
            }
            else {
                delete mob;
                currentMobIndex++;
            }
        }
        else {
            // Tous les mobs sont spawnés, la vague est terminée
            window.close();
        }
        window.draw(backgroundImage);
    }
}
