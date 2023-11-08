#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "Play.h"

void ShowDialogue(sf::RenderWindow& window, const std::string& text, const sf::Texture& dialogtexture) {

    sf::Sprite dialogImage;
   dialogImage.setTexture(dialogtexture);

    sf::Font font;
    if (!font.loadFromFile("../Assets/font/PokemonSolid.ttf")) {
        // Assurez-vous que le fichier arial.ttf est dans le répertoire de votre application
        return;
    }

    sf::Text dialogueText;
    dialogueText.setFont(font);
    dialogueText.setCharacterSize(24);
    dialogueText.setPosition(350, 650);
    dialogueText.setFillColor(sf::Color::Black);

    std::string fullText = text;
    std::string partialText = "";
    int textSpeed = 15; // Vitesse d'affichage en caractères par seconde

    sf::Clock clock;

    while (partialText.length() < fullText.length()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        float deltaTime = clock.restart().asSeconds();

        int charactersToAdd = static_cast<int>(textSpeed * deltaTime);
        if (charactersToAdd < 1) {
            charactersToAdd = 1;
        }

        partialText += fullText.substr(partialText.length(), charactersToAdd);

        window.clear();
        window.draw(dialogImage);
        dialogueText.setString(partialText);
        window.draw(dialogueText);
        window.display();

        sf::sleep(sf::milliseconds(50)); // Vous pouvez ajuster la durée du délai selon vos besoins
    }

    // Attendre que l'utilisateur appuie sur une touche
    bool keyPressed = false;
    while (!keyPressed) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
            if (event.type == sf::Event::KeyPressed) {
                keyPressed = true;
            }
        }
    }
}

void ShowPartialDialogue(sf::RenderWindow& window, const std::string& text, const sf::Texture& backgroundTexture, const sf::Texture& imageTexture) {

    sf::Sprite backgroundImage;
    backgroundImage.setTexture(backgroundTexture);

    sf::Sprite ImageImage;
    ImageImage.setTexture(imageTexture);

    sf::Font font;
    if (!font.loadFromFile("../Assets/font/arial.ttf")) {
        // Assurez-vous que le fichier arial.ttf est dans le répertoire de votre application
        return;
    }

    sf::Text dialogueText;
    dialogueText.setFont(font);
    dialogueText.setCharacterSize(24);
    dialogueText.setPosition(50, 50);
    dialogueText.setFillColor(sf::Color::Red);

    std::string fullText = text;
    std::string partialText = "";
    int textSpeed = 1; // Vitesse d'affichage en caractères par seconde

    sf::Clock clock;

    while (partialText.length() < fullText.length()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        float deltaTime = clock.restart().asSeconds();

        int charactersToAdd = static_cast<int>(textSpeed * deltaTime);
        if (charactersToAdd < 1) {
            charactersToAdd = 1;
        }

        partialText += fullText.substr(partialText.length(), charactersToAdd);

        window.clear();
        window.draw(backgroundImage);
        dialogueText.setString(partialText);
        window.draw(dialogueText);
        window.draw(ImageImage);  // Affichez l'image ici
        window.display();

        sf::sleep(sf::milliseconds(100)); // Vous pouvez ajuster la durée du délai selon vos besoins
    }
    bool keyPressed = false;
    while (!keyPressed) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
            if (event.type == sf::Event::KeyPressed) {
                keyPressed = true;
            }
        }
    }
}

void Tuto() {

    sf::RenderWindow window(sf::VideoMode(1900, 1000), "SFML Game");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("../Assets/img/background.png")) {

    }

    sf::Sprite backgroundImage;
    backgroundImage.setTexture(backgroundTexture);


    sf::Texture ImageTexture;
    if (ImageTexture.loadFromFile("../Assets/img/Tuto.png")) {
        // Gérez le cas où la texture de l'image ne peut pas être chargée
    }
    sf::Sprite ImageImage;
   ImageImage.setTexture(ImageTexture);


   sf::Texture DialogTexture;
   if (DialogTexture.loadFromFile("../Assets/img/Intro.png")) {
       // Gérez le cas où la texture de l'image ne peut pas être chargée
   }

   sf::Sprite DialogImage;
   DialogImage.setTexture(DialogTexture);

    ShowDialogue(window, "Bonjour jeune dresseur(e) ! Bienvenue dans le monde des Pokémons. \n Mon nom est Chen, je suis le professeur Pokémon. \n Oh je vois que tu détiens déjà un Pokémon Parfait ! <><>", DialogTexture);
    ShowDialogue(window, "Nous avons un gros probleme à Kanto. \n Depuis quelques jours des Pokémons spectres attaquent sans relache la tour de Kanto. \n Cette tour est un symbole pour tous les habitants. \n Aide moi à stopper tous les pokémons pour empecher la destruction de la tour. <><>", DialogTexture);
    ShowPartialDialogue(window, "Information", backgroundTexture, ImageTexture);
    ShowDialogue(window, "Voilà, je t'ai tranmis toutes les informations que je possédais. \n Va et sauve Kanto ! <><>", DialogTexture);
    Play(window);
  
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(backgroundImage);
        window.display();
    }
 }

