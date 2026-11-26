#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include "Asteroid.h"

class GameField
{
private:
    sf::Vector2u size{1000, 1000};
    std::vector<Asteroids> asteroids;
    float spawnTimer = 0.f;
    std::mt19937 random;
    void spawnAsteroid();
    

public:
    GameField();

    void reset(sf::Vector2u windowSize);
    void update(float dt);
    void draw(sf::RenderTarget& target) const;
    bool checkCollision(const sf::FloatRect& rect) const;
    int getScore();
    int Score = 0;
    
};