#include "GameField.h"

GameField::GameField()
{
    // генерация рандомного числа, связанного с появленим метеоритов
}

void GameField::reset(sf::Vector2u windowSize)
{
    // уничтежение метеоритов, вышетших за пределы 
    size = windowSize;
}

void GameField::update(float dt)
{
    // создание новых астероидов
}

void GameField::draw(sf::RenderTarget &target) const
{
    // отрисовка метеоритов и текста
}

bool GameField::checkCollision(const sf::FloatRect &rect) const
{
    // проверка столкновений
    return false;
}
