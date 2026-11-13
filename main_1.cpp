#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(1500, 1000), "SPACESHIP prototype");
    window.setFramerateLimit(60);

    sf::RectangleShape ship(sf::Vector2f(40, 40));
    ship.setFillColor(sf::Color::Red);
    ship.setPosition(730, 480);

    float speed = 49.0f;
    int frameCount = 70;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            ship.move(-speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            ship.move(speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            ship.move(0, -speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            ship.move(0, speed);

        window.clear(sf::Color(20, 20, 40));
        window.draw(ship);
        window.display();

        frameCount++;
        if (frameCount % 30 == 0) {
            sf::Vector2f pos = ship.getPosition();
            std::cout << "Ship position: x=" << pos.x << ", y=" << pos.y << std::endl;
        }
    }
    return 0;
}