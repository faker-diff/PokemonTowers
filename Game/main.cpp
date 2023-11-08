#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Mobs.h"
#include "Vague.h"
#include "Scene.h"
#include "Menu.h"
#include "Play.h"
#include "Tuto.h"


int main() {

	sf::RenderWindow window(sf::VideoMode(500, 500), "Starting");

	sf::Music music;

	if (!music.openFromFile("../Assets/song/Conseil4.ogg")) {
		return -1;
	}

	music.setLoop(true);
	music.setVolume(50.0f);
	music.play();

	sf::Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("../assets/img/Starting.png")) {
		return -1; // Quittez le programme en cas d'erreur de chargement de l'image
	}

	sf::Sprite backgroundImage;
	backgroundImage.setTexture(backgroundTexture);

	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Return) {
					Tuto();
				}
				if (event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
			}
		}
		window.clear();
		window.draw(backgroundImage);
		menu.draw(window);
		window.display();
	}

    }




