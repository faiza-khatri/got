#include <SFML/Graphics.hpp>
#include "characterSelectWindow.h"
#include "startScreen.h"
#include "fightWindow.h"
#include "GameOverWindow.h"
#include <iostream>
#include <filesystem>

int main() {
    Game game;
    sf::Vector2u windowSize = { 800, 600 };
    CharacterSelectWindow characterSelectWindow(windowSize);
    StartScreen startScreen(windowSize);
    FightWindow fightWindow(windowSize, game);
    GameOverWindow gameOverWindow(windowSize);  
    sf::RenderWindow window(sf::VideoMode(800, 600), "Character select test");
    

    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

    // Set the window size and title
    window.create(sf::VideoMode(800, 600), "Character Select");

    game.setCurrentState(3);
    // Main loop
    while (window.isOpen()) {
       sf::Event event;
       while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
              window.close();
          }
            if (game.getCurrentState() == 0) {
                startScreen.handleInput(window, game);
            }
            else if (game.getCurrentState() == 1) {
                characterSelectWindow.handleInput(window, game);
            }
            else if (game.getCurrentState() == 2) {
                fightWindow.handleInput(window, game);
            }
        }

       
       window.clear(sf::Color::Black);

       // Render based on the current game state
       if (game.getCurrentState() == 0) {
           startScreen.renderScreen(window);
       }
       else if (game.getCurrentState() == 1) {
           characterSelectWindow.renderScreen(window);
       }
       else if (game.getCurrentState() == 2) {
           fightWindow.renderScreen(window);
       }
       else if (game.getCurrentState() == 3) {
           gameOverWindow.renderScreen(window);  // Render the game over screen
       }

       window.display();
    }

    return 0;
}
