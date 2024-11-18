#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Attack Animation Test");

    // Load the sprite sheet
    sf::Texture attackTexture;
    if (!attackTexture.loadFromFile("D:\\oop\\clonedTemplateOOP\\pngImages\\player\\brienne\\Attack.png")) {
        std::cout << "Error loading Attack.png" << std::endl;
        return -1;
    }

    // Create a sprite and assign the texture
    sf::Sprite attackSprite;
    attackSprite.setScale(5.0f, 5.0f);
    attackSprite.setTexture(attackTexture);

    // Define the frame size (based on your sprite sheet's dimensions)
    const int frameWidth = 86;  // Width of a single frame
    const int frameHeight = 86; // Height of a single frame
    const int numFrames = 5;    // Total number of frames in the animation
    const float frameDuration = 0.15f; // Time per frame in seconds

    // Set the initial frame
    int currentFrame = 0;
    attackSprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
    attackSprite.setPosition(350.0f, 250.0f); // Center the sprite in the window

    // Animation timer
    sf::Clock clock;
    float elapsedTime = 0.0f;

    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Update the animation
        elapsedTime += clock.restart().asSeconds();
        if (elapsedTime >= frameDuration) {
            elapsedTime = 0.0f;

            // Advance to the next frame
            currentFrame = (currentFrame + 1) % numFrames;
            attackSprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));
        }

        // Clear the window and draw the sprite
        window.clear(sf::Color::Black);
        window.draw(attackSprite);
        window.display();
    }

    return 0;
}
