#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Create a window
    auto window = sf::RenderWindow({ 1920u, 1080u }, "Ball");
    window.setFramerateLimit(144);

   

    sf::Texture idleTexture;
    sf::Texture attackTexture;

    if (!idleTexture.loadFromFile("D:\\oop\\clonedTemplateOOP\\pngImages\\Knight_1\\Protect.png") ||
        !attackTexture.loadFromFile("D:\\oop\\clonedTemplateOOP\\pngImages\\Knight_1\\Attack 1.png")) {
        std::cerr << "Unable to laod images";
        return 0;
    }

    sf::Sprite knightSprite;
    knightSprite.setTexture(idleTexture);

    knightSprite.setScale(3.0f, 3.0f);

    // Animation settings
    int idleFrameWidth = 86;
    int attackFrameWidth = 86;
    int frameHeight = 86;
    int idleFrames = 1;   // Number of frames in idle animation
    int attackFrames = 5; // Number of frames in attack animation
    int currentFrame = 0;
    float frameDuration = 0.15f;
    sf::Clock frameClock;

    bool attacking = false;
    bool attackComplete = false;

    // Main game loop
    while (window.isOpen())
    {
        for (auto event = sf::Event(); window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !attacking) {
            attacking = true;
            currentFrame = 0; // Reset to the first attack frame
            knightSprite.setTexture(attackTexture);
        }

        if (frameClock.getElapsedTime().asSeconds() >= frameDuration) {
            frameClock.restart();

            float frameWidth = attacking ? attackFrameWidth : idleFrameWidth;

            // Update frames based on whether we are attacking or idling
            if (attacking) {
                currentFrame = (currentFrame + 1) % attackFrames;
                knightSprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));

                // Return to idle when attack animation is done
                if (currentFrame == attackFrames - 1) {
                    attacking = false;
                    attackComplete = true;
                }
            }
            else {
                if (attackComplete) {
                    knightSprite.setTexture(idleTexture);
                    attackComplete = false;
                }
                currentFrame = (currentFrame + 1) % idleFrames;
                knightSprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));
            }
        }


        // Clear the window, and display the updated content
        window.clear();
        window.draw(knightSprite);

   

        window.display();
    }

    return 0;
}
