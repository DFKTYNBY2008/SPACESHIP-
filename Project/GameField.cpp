#include "GameField.h"

GameField::GameField()
{
}

void GameField::reset(sf::Vector2u windowSize)
{
    size = windowSize;
}

void GameField::update(float dt)
{
}

void GameField::draw(sf::RenderTarget &target) const
{
}

bool GameField::checkCollision(const sf::FloatRect &rect) const
{
    return false;
}
