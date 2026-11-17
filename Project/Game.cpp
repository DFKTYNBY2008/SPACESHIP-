#include <string>
#include <stdexcept>
#include "Game.h"

void Game::run()
{
    sf::Clock clock;
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        scoreTimer += dt;
        while (scoreTimer >= 1.f)
        {
            scoreTimer -= 1.f;
            score += 10;
        }
        field.update(dt);
        

        window.clear(sf::Color(10, 15, 30));
        field.draw(window);
        hudText.setString("score: " + std::to_string(score));
        window.draw(hudText);
        window.display();
    }
            
}


Game::Game() : window(sf::VideoMode (1000, 1000), " ")
{
if (!font.loadFromFile("font.ttf"))
{
    throw std::runtime_error("font.ttf not found");
}

    hudText.setFont(font);
    hudText.setCharacterSize(30);
    hudText.setFillColor(sf::Color::White);
    hudText.setPosition(10, 10);

    field.reset(window.getSize());
}
