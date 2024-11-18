#include <SFML/Graphics.hpp>
#include "player.h"

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(1400, 1000), "Character Animation Test");

    // Create the player object
    Player player(100, 10, 20, "danaerys");  // Health, Speed, Attack Power, Name

    // Load textures (make sure you have the textures in place for the animation)
    /*player.loadCharVarTextures();*/

    //// Set up clock for frame timing
    //sf::Clock deltaClock;

    // Main game loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        player.handleInput();
        /*std::cout << player.getState() << std::endl;*/

        player.animate(false);

        // Clear the window
        window.clear(sf::Color::Black);

        // Draw the player (sprite)
        /*player.drawChar(window);*/
        /*if (player.getSprite() == nullptr) {
            std::cout << "sprite is null stupid." << std::endl;
        }*/
        window.draw(player.getSprite());

        // Display the updated content in the window
        window.display();

        //// Simulate frame duration
        //sf::Time deltaTime = deltaClock.restart();
    }

    return 0;
}
