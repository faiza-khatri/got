#ifndef FIGHT_WINDOW
#define FIGHT_WINDOW

#include "baseWindow.h"
#include "player.h"

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Mouse.hpp>

// Character selection window and other initial operations
class FightWindow : public BaseWindow, public sf::RenderWindow {
public:
    FightWindow(sf::Vector2u& windowSize, int);            // Constructor
    void initializeComponents(sf::Vector2u&, int) override; // Initialize components
    void renderScreen(sf::RenderWindow& window) override;   // Render life bar and player sprite
    int handleInput(sf::RenderWindow&);                    // Handle player input
    void operator=(const FightWindow*);                    // Assignment operator
    void updateLifeBar(float damage);
    sf::RectangleShape lifeBarOutline;
    ~FightWindow();                                        // Destructor

private:
    Player* p1;                                            // Pointer to the player
    sf::RectangleShape lifeBar;                            // Rectangle for the life bar
    sf::Clock clock;
};

#endif
