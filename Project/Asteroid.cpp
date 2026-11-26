#include "Asteroid.h"

Asteroids::Asteroids(float x, float y, float radius, float speed) : speed(speed)
{
    asteroid.setRadius(radius);
    asteroid.setOrigin(radius, radius);
    asteroid.setPosition(x, y);
    asteroid.setFillColor(sf::Color::Green);
}

void Asteroids::update(float dt)
{
    asteroid.move(0.f, speed * dt);
}

void Asteroids::draw(sf::RenderTarget &target) const
{
    target.draw(asteroid);
}

sf::Vector2f Asteroids::getCenter() const
{
    return asteroid.getPosition();
}

float Asteroids::getRadius() const
{
    return asteroid.getRadius();
}

bool Asteroids::isOffScreen(sf::Vector2u fieldSize) const
{
    float fieldDelAsteroid = 100.f;

    sf::Vector2f position = asteroid.getPosition();
    float radius = asteroid.getRadius();

    return position.y - radius > fieldSize.y + fieldDelAsteroid ||
           position.x - radius > fieldSize.x + fieldDelAsteroid ||
           position.x + radius < -fieldDelAsteroid ||
           position.y + radius < -fieldDelAsteroid;
}