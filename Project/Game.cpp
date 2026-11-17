#include <string>
#include <stdexcept>
#include "Game.h"

void run()
{
    sf::Clock clock;
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();

        sf::Event event;
        white (window.pollEvent(evwnt))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        scoreTimer += dt;
        While (scoreTimer >= 1.f)
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


Game::Game() : window(sf::VideoMode (800, 800), " ")
{
    if (!font.LoadFromFile("asswts//font/ttf"))
    {
        throw std::runtime_error("asswts//font/ttf not found")
    }

    hudText.setFont(font);
    hudText.setCharacterSize(20);
    hudText.setfillColor(sf::Color::White);
    hudText.setPosition(10, 10);

    field.reset(window.getSize());
}
