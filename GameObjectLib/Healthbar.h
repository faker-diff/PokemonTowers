#pragma once
#include "SFML/Graphics.hpp"

class HealthBar : public sf::RectangleShape {
public:
    HealthBar(float width, float height) {
        bar.setSize(sf::Vector2f(width, height));
        bar.setFillColor(sf::Color::Red);
        bar.setOutlineColor(sf::Color::Black);
        bar.setOutlineThickness(2.0f);
        initialWidth = width;
    }

    void setPosition(float x, float y) {
        bar.setPosition(x, y);
    }

    void setSize(float width, float height) {
        bar.setSize(sf::Vector2f(width, height));
    }

    void setHealth(float health) {
        maxHealth = health;
        currentHealth = health;
    }

    void setCurrentHealth(int health) {
        // Mise ? jour de la valeur actuelle de sant? sans d?passer la valeur maximale
        currentHealth = std::min(health, maxHealth);
        float healthRatio = static_cast<float>(currentHealth) / static_cast<float>(maxHealth);
        bar.setSize(sf::Vector2f(healthRatio * initialWidth, bar.getSize().y));
    }

    void TakeDamage(int damage) {
        // R?duire la sant? en fonction des d?g?ts subis
        setCurrentHealth(currentHealth - damage);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(bar);
    }

private:
    int maxHealth;
    int currentHealth;
    int initialWidth;
    sf::RectangleShape bar;
};