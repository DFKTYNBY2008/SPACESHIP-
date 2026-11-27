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
    sf::Text pauseText;
    sf::Text endText;
    sf::Text livesText;

    GameField field;
    Ship ship;

    bool pause = false;
    bool game_over = false;
    int score = 0;
    int lives = 3;
    float Timer = 0.f;
    
public:
    Game();
    void run();
};