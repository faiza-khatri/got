#include <SFML/Graphics.hpp>
//#include "characterSelectWindow.h"
//#include "startScreen.h"
//#include "fightWindow.h"

#include "game.h"

#include <iostream>
#include <filesystem>

int main() {
    //Game game;
    //// Create an instance of CharacterSelectWindow
    //sf::Vector2u windowSize = { 800, 600 };
    //CharacterSelectWindow characterSelectWindow(windowSize);
    //StartScreen startScreen(windowSize);
    //FightWindow fightWindow(windowSize, game);
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
