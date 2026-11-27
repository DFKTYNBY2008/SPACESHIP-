#pragma once
#include <SFML/Graphics.hpp>
#include <random>

class Asteroids
{
private:
    sf::CircleShape asteroid;
    float speedY;
    float speedX;
    std::mt19937 random;

public:
    Asteroids(float x, float y, float radius,float speed);

    void update(float dt);
    void draw(sf::RenderTarget& target) const;

    sf::Vector2f getCenter() const;
    float getRadius() const;
    bool isOffScreen(sf::Vector2u fieldSize) const;
    sf::FloatRect getBounds() const;
};