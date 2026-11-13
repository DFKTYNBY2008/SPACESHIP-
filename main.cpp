#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    std::cout << "SFML test started successfully!" << std::endl;
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "SPACESHIP test");
    sf::Event event;
    
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        window.display();
    }
    return 0;
}
