#pragma once
#include <SFML/Graphics.hpp>

class Ship
{
private:
    sf::RectangleShape ship;
    float speed = 500.f;
public:
    Ship();
    void reset(sf::Vector2u windowSize);
    void move(float dt, int direction, sf::Vector2u windowSize);
    void draw(sf::RenderTarget& target) const;

    sf::FloatRect getBounds() const;
};