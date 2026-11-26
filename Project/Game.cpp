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
        }
        Timer += dt;
        score += field.getScore();
        field.update(dt);
        

        window.clear(sf::Color(10, 15, 30));
        field.draw(window);
        scoreText.setString("score: " + std::to_string(score));
        timeText.setString("time: " + Clock(Timer));
        window.draw(scoreText);
        window.draw(timeText);
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


    field.reset(window.getSize());
}
