#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include "GameField.h"

class Game
{
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text scoreText;
    sf::Text timeText;
    GameField field;

    int score = 0;
    float scoreTimer = 0.f; 
    float Timer = 0.f;
    
public:
    Game();
    void run();
};