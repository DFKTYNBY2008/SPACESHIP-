#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include "GameField.h"
#include "Ship.h"

class Game
{
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text scoreText;
    sf::Text timeText;
    GameField field;
    Ship ship;
    int score = 0; 
    float Timer = 0.f;
    
public:
    Game();
    void run();
};