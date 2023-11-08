#include <SFML/Graphics.hpp>

class Menu {
public:
    enum Option {
        Play,
        Exit
    };

    Menu(float width, float height);

    void draw(sf::RenderWindow& window);

private:
    static const int MAX_NUMBER_OF_ITEMS = 3;

    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    int selected;
};

