#include <SFML/Graphics.hpp>
#include "Ship.h"

Ship::Ship()
{
    ship.setSize({40.f, 40.f});
    ship.setOrigin({20.f, 20.f});
    ship.setFillColor(sf::Color(100, 180, 255));
}

void Ship::reset(sf::Vector2u windowSize)
{
    ship.setPosition(windowSize.x / 2.f, windowSize.y - 50.f);
}

void Ship::move(float dt, int direction, sf::Vector2u windowSize)
{
    ship.move(direction * speed * dt, 0.f);

    if (ship.getPosition().x < 20.f)
        ship.setPosition(20.f, ship.getPosition().y);
    
        if (ship.getPosition().x > windowSize.x - 20.f)
        ship.setPosition(windowSize.x - 20.f, ship.getPosition().y);
}

void Ship::draw(sf::RenderTarget &target) const
{
    target.draw(ship);
}

sf::FloatRect Ship::getBounds() const
{
    return ship.getGlobalBounds();
}
