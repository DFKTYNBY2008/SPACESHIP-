#include "Asteroid.h"



Asteroids::Asteroids(float x, float y, float radius, float speed) : speedY(speed), random(std::random_device{}())
{
    asteroid.setRadius(radius);
    asteroid.setOrigin(radius, radius);
    asteroid.setPosition(x, y);
    asteroid.setFillColor(sf::Color::Green);
    std::uniform_real_distribution<float> newSpeedX (-50.f, 50.f);
    speedX = newSpeedX(random);
}

void Asteroids::update(float dt)
{
    asteroid.move(speedX * dt, speedY * dt);
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

sf::FloatRect Asteroids::getBounds() const
{
    return asteroid.getGlobalBounds();
}
