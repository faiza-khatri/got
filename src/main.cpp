#include <SFML/Graphics.hpp>


#include "game.h"

#include <iostream>
#include <filesystem>

int main() {
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");

    // Set the window size and title
    window.create(sf::VideoMode(800, 600), "Game");

    Game game(window.getSize());


    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            game.handleInput(window);
        }


        window.clear(sf::Color::Black);
        game.renderScreen(window);

        window.display();

    }


    return 0;
}