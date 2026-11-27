#include <string>
#include <stdexcept>
#include "Game.h"
#include <sstream>
#include "Ship.h"


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
      
            if (field.checkCollision(ship.getBounds()))
            {
                lives--;
                field.reset(window.getSize());
                if (lives == 0)
                {
                    game_over = true;
                };
            };
        }
   
        window.clear(sf::Color(10, 15, 30));
        field.draw(window); 
        ship.draw(window);

        scoreText.setString("score: " + std::to_string(score));
        timeText.setString("time: " + Clock(Timer));
        if (lives > 1)
        {
            livesText.setString("lives: " + std::to_string(lives));
        }
        else 
        {
            livesText.setString("live: " + std::to_string(lives));
        }
        window.draw(scoreText);
        window.draw(timeText);
        window.draw(livesText);


        if (game_over)
        {
            pause = true;
           
        }
        if (pause && game_over)
        {
            endText.setString("Game over!!!");
            window.draw(endText);
        }
        if (pause && !game_over)
        {
            pauseText.setString("PAUSE");
            window.draw(pauseText);
            ship.reset(window.getSize());
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

    endText.setFont(font);
    endText.setCharacterSize(100);
    endText.setFillColor(sf::Color::White);
    endText.setPosition(220, 410);

    livesText.setFont(font);
    livesText.setCharacterSize(30);
    livesText.setFillColor(sf::Color::White);
    livesText.setPosition(450, 10);

    field.reset(window.getSize());
    ship.reset(window.getSize());
}
