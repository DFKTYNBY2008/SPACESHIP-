#include "GameField.h"
#include <algorithm>

void GameField::spawnAsteroid()
{
    float radius = 30.f;
    std::uniform_real_distribution<float> newSpeed (200.f, 800.f);


    std::uniform_real_distribution<float> newPosition(radius, size.x - radius);
    asteroids.emplace_back(newPosition(random), -radius, radius, newSpeed(random));
}

GameField::GameField() : random(std::random_device{}())
{
}

void GameField::reset(sf::Vector2u windowSize)
{
    asteroids.clear();
    spawnTimer = 0.f;
    size = windowSize;
}

void GameField::update(float dt)
{
    spawnTimer += dt;
    if (spawnTimer > 0.2f)
    {
        spawnTimer = 0.f;
        spawnAsteroid();
    }

    for (auto& a : asteroids)
    {
        a.update(dt);
    }

    for (int i = 0; i < asteroids.size(); ++i)
    {
        if (asteroids[i].isOffScreen(size))
        {
            Score += 3;
            asteroids.erase(asteroids.begin() + i);
            i--;
        }
    };
   
}


void GameField::draw(sf::RenderTarget &target) const
{
    for (const auto& a : asteroids)
    {
        a.draw(target);
    }
}

bool GameField::checkCollision(const sf::FloatRect &rect) const
{
    for (const auto& a : asteroids)
    {
        if (rect.intersects(a.getBounds()))
        {
            return true;
        }
    }
    return false;
}

int GameField::getScore()
{
    int result = Score;
    Score = 0;
    return result;
}
