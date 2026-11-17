#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include "GameField.h"

class Game
{
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text hudText;
    GameField field;
    int score = 0;
    float scoreTimer = 0.f;
public:
    Game();
    void run();
};