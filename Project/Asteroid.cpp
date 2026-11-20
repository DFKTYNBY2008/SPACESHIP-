#include "Asteroid.h"

Asteroids::Asteroids(float x, float y, float radius, float speed)
{
    asteroid.setRadius(radius);
    asteroid.setOrigin(radius, radius);
    asteroid.setPosition(x, y);
    asteroid.setFillColor(sf::Color(150, 150, 150));
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

bool Asteroids::isOffScreen(float screenHeight) const
{
    return asteroid.getPosition().y - asteroid.getRadius()>screenHeight;
}