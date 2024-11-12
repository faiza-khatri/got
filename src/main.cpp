#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Create a window
    auto window = sf::RenderWindow({ 1920u, 1080u }, "Ball");
    window.setFramerateLimit(144);

    // Create a ball (circle shape)
    sf::CircleShape ball(50.0f);  // Radius of 50 pixels
    ball.setFillColor(sf::Color::Red);  // Set color of the ball

    // Ball's initial position and velocity
    sf::Vector2f ballPosition(960.0f, 540.0f);  // Center of the screen
    sf::Vector2f velocity(5.0f, 5.0f);  // Movement speed in x and y direction

    // Set initial position of the ball
    ball.setPosition(ballPosition);

    sf::Texture texture;
    if (!texture.loadFromFile("D:\\oop\\clonedTemplateOOP\\pngImages\\pngwing.com.png")) {
        std::cerr << "Error loading image file" << std::endl;
        return -1;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);

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

        // Update ball position based on velocity
        ballPosition += velocity;
        ball.setPosition(ballPosition);

        // Check for collision with the window edges and reverse the velocity when it hits
        if (ballPosition.x <= 0 || ballPosition.x + ball.getGlobalBounds().width >= window.getSize().x)
        {
            velocity.x = -velocity.x;  // Reverse horizontal velocity
        }

        if (ballPosition.y <= 0 || ballPosition.y + ball.getGlobalBounds().height >= window.getSize().y)
        {
            velocity.y = -velocity.y;  // Reverse vertical velocity
        }

        // Clear the window, draw the ball, and display the updated content
        window.clear();
        window.draw(ball);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
