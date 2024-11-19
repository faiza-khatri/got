#ifndef  FIGHT_WINDOW
#define FIGHT_WINDOW

#include "baseWindow.h"
#include "player.h"


#include <map>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Mouse.hpp>

#include "player.h"
#include "game.h"


// character selection window and other initial operations
class FightWindow : public BaseWindow, public sf::RenderWindow {
public:
    FightWindow(sf::Vector2u&, Game& game);
    void initializeComponents(sf::Vector2u&) override;
    void renderScreen(sf::RenderWindow& window) override;
    void handleInput(sf::RenderWindow&, Game& game);
    ~FightWindow();
private:
    Player* p1;
};

#endif