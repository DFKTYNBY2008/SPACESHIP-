#include <string>
#include <stdexcept>
#include "Game.h"
#include <sstream>

std::string Clock (float timer)
{
    int seconds = static_cast<int>(timer);
    int minutes = (seconds % 3600) / 60;
    seconds = seconds % 60;

    std::ostringstream oss;
    oss << (minutes < 10 ? "0" : "") << minutes << ":"
        << (seconds < 10 ? "0" : "") << seconds;

    return oss.str();
}


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

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    pause = !pause;
                }
            }
        }
        if (!pause)
        {
            Timer += dt;
            score += field.getScore();
            field.update(dt);

            int direction = 0;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                direction = -1;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                direction = 1;
            }
            ship.move(dt, direction, window.getSize());
        }

        window.clear(sf::Color(10, 15, 30));
        field.draw(window);
        ship.draw(window);
        scoreText.setString("score: " + std::to_string(score));
        timeText.setString("time: " + Clock(Timer));
        window.draw(scoreText);
        window.draw(timeText);


        if (pause)
        {
            pauseText.setString("PAUSE");
            window.draw(pauseText);
        }
        window.display();
    }
    
    
}


Game::Game() : window(sf::VideoMode (1000, 1000), " ")
{
if (!font.loadFromFile("font.ttf"))
{
    throw std::runtime_error("font.ttf not found");
}

    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);
    
    timeText.setFont(font);
    timeText.setCharacterSize(30);
    timeText.setFillColor(sf::Color::White);
    timeText.setPosition(830, 10);

    pauseText.setFont(font);
    pauseText.setCharacterSize(100);
    pauseText.setFillColor(sf::Color::White);
    pauseText.setPosition(350, 430);


    field.reset(window.getSize());
    ship.reset(window.getSize());
}
