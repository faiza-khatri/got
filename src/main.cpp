#include <SFML/Graphics.hpp>
#include "characterSelectWindow.h"

#include <iostream>
#include <filesystem>

int main() {
    // Create an instance of CharacterSelectWindow
    CharacterSelectWindow characterSelectWindow;

    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

    // Set the window size and title
    characterSelectWindow.create(sf::VideoMode(800, 600), "Character Select");


    // Main loop
    while (characterSelectWindow.isOpen()) {
       sf::Event event;
       while (characterSelectWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
              characterSelectWindow.close();
          }
        }

       // Clear and draw the characters in the window
       characterSelectWindow.handleInput();
        characterSelectWindow.updateGraphics();

    }


    return 0;
}
