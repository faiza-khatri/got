#include <SFML/Graphics.hpp>
#include "characterSelectWindow.h"

int main() {
    // Create an instance of CharacterSelectWindow
    CharacterSelectWindow characterSelectWindow;

    // Set the window size and title
    characterSelectWindow.create(sf::VideoMode(800, 600), "Character Select");

    // Initialize the character list with portraits
    characterSelectWindow.initialize();

    // Main loop
    while (characterSelectWindow.isOpen()) {
        sf::Event event;
        while (characterSelectWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                characterSelectWindow.close();
            }
        }

        // Clear and draw the characters in the window
        characterSelectWindow.updateGraphics();

    }

    return 0;
}
