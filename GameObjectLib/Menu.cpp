#include "Menu.h"
#include <iostream>

Menu::Menu(float windowWidth, float windowHeight) {
    if (!font.loadFromFile("../Assets/font/PokemonSolid.ttf")) {
        std::cerr << "Erreur : Impossible de charger la police." << std::endl;
    }

    // Calculez la position horizontale (X) du centre de la fenêtre
    float centerX = windowWidth / 2;

    // Calculez la position verticale (Y) du centre de la fenêtre
    float centerY = windowHeight / 2.5;

    // Positionnez chaque élément de menu en fonction du centre de la fenêtre
    menu[Play].setFont(font);
    menu[Play].setFillColor(sf::Color::White);
    menu[Play].setString("Start");
    menu[Play].setCharacterSize(10);
    menu[Play].setPosition(sf::Vector2f(centerX, centerY));


    selected = Play;
}

void Menu::draw(sf::RenderWindow& window) {
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
        window.draw(menu[i]);
    }
}


