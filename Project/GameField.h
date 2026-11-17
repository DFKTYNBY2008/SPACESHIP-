#pragma once
#include <SFML/Graphics.hpp>

class GameField
{
private:
    sf::Vector2u size{800, 800};

public:
    GameField();

    void reset(sf::Vector2u windowSize);
    void update(float dt);
    void draw(sf::RenderTarget& target) const;
    bool checkCollision(const sf::FloatRect& rect) const;
    
};