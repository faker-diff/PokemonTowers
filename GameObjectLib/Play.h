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

    // Cr�ez une instance de Vague avec des param�tres sp�cifi�s 
    Vague vague1(1, 1, 1, 1);

    const std::vector<Mobs*>& mobsList = vague1.GetMobsList();
    sf::Clock clock;
    int currentMobIndex = 0;

    // Cr�e un texte pour afficher dans la bo�te de dialogue
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
        // V�rifiez si le mob actuel est mort ou a d�pass� 800 pixels en X
        if (currentMobIndex < mobsList.size()) {
            Mobs* mob = mobsList[currentMobIndex];

            if (mob->GetHealth() > 0 && mob->GetPositionX() < 1900) {
                // D�placez et affichez le mob
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
            // Tous les mobs sont spawn�s, la vague est termin�e
            window.close();
        }
        window.draw(backgroundImage);
    }
}
