#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Initial window size
    int windowX = 800;
    int windowY = 600;
    sf::RenderWindow window(sf::VideoMode(windowX, windowY), "Dynamic Button Alignment");

    // Load background texture
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("C:\\Users\\hp\\Desktop\\HABIB\\oopClonedTemplate\\got\\pngImages\\start_scrn\\bg.png")) {
        std::cerr << "Error loading bg.png" << std::endl;
        return -1;
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    // Load button textures
    sf::Texture playTexture, exitTexture, cbTexture;
    if (!playTexture.loadFromFile("C:\\Users\\hp\\Desktop\\HABIB\\oopClonedTemplate\\got\\pngImages\\start_scrn\\play.png") ||
        !exitTexture.loadFromFile("C:\\Users\\hp\\Desktop\\HABIB\\oopClonedTemplate\\got\\pngImages\\start_scrn\\exit.png") ||
        !cbTexture.loadFromFile("C:\\Users\\hp\\Desktop\\HABIB\\oopClonedTemplate\\got\\pngImages\\start_scrn\\changebg.png")) {
        std::cerr << "Error loading button images" << std::endl;
        return -1;
    }

    sf::Sprite playButton(playTexture);
    sf::Sprite exitButton(exitTexture);
    sf::Sprite cbButton(cbTexture);

    // Function to position and scale buttons dynamically
    auto updateButtonPositions = [&](sf::Vector2u windowSize) {
        // Scale factors for buttons (relative to screen size)
        float buttonWidthFactor = 0.3f; // Buttons will be 30% of the screen width
        float buttonWidth = windowSize.x * buttonWidthFactor;
        float buttonHeight = buttonWidth * (playTexture.getSize().y / static_cast<float>(playTexture.getSize().x));

        // Scale Play and Exit buttons to the same size
        playButton.setScale(buttonWidth / playTexture.getSize().x, buttonHeight / playTexture.getSize().y);
        exitButton.setScale(playButton.getScale());

        // Scale Change Background button separately (but to the same 30% width)
        float cbButtonWidth = buttonWidth;
        float cbButtonHeight = cbButtonWidth * (cbTexture.getSize().y / static_cast<float>(cbTexture.getSize().x));
        cbButton.setScale(cbButtonWidth / cbTexture.getSize().x, cbButtonHeight / cbTexture.getSize().y);

        // Horizontal spacing between Play and Exit buttons
        float horizontalSpacing = windowSize.x * 0.05f;

        // Calculate positions
        float buttonY = windowSize.y * 0.5f; // Center vertically
        float playButtonX = (windowSize.x / 2.0f) - buttonWidth - (horizontalSpacing / 2.0f);
        float exitButtonX = (windowSize.x / 2.0f) + (horizontalSpacing / 2.0f);

        // Set positions
        playButton.setPosition(playButtonX, buttonY - (buttonHeight / 2.0f));
        exitButton.setPosition(exitButtonX, buttonY - (buttonHeight / 2.0f));

        // Change Background button position (below Play and Exit)
        float cbButtonX = (windowSize.x / 2.0f) - (cbButtonWidth / 2.0f);
        float cbButtonY = buttonY + buttonHeight + (windowSize.y * 0.05f); // Add vertical spacing
        cbButton.setPosition(cbButtonX, cbButtonY);
        };

    // Initial positioning
    updateButtonPositions(window.getSize());

    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Handle resizing
            if (event.type == sf::Event::Resized) {
                sf::Vector2u newSize(event.size.width, event.size.height);
                updateButtonPositions(newSize);
            }

            // Handle mouse clicks
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    if (playButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        std::cout << "Play button clicked. Starting the game!" << std::endl;
                    }
                    if (exitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        std::cout << "Exit button clicked. Exiting the game!" << std::endl;
                        window.close();
                    }
                    if (cbButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        std::cout << "Change Background button clicked. Changing the background!" << std::endl;
                    }
                }
            }
        }

        // Render everything
        window.clear();
        window.draw(backgroundSprite);
        window.draw(playButton);
        window.draw(exitButton);
        window.draw(cbButton);
        window.display();
    }

    return 0;
}
