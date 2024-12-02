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
#include "enemy.h"
//#include "game.h"


// character selection window and other initial operations
class FightWindow : public BaseWindow, public sf::RenderWindow {
public:
    /*FightWindow();*/
    FightWindow(sf::Vector2u& windowSize, int);
    void initializeComponents(sf::Vector2u&, int) override;
    void renderScreen(sf::RenderWindow& window) override;
    int handleInput(sf::RenderWindow&);
    void operator=(const FightWindow*);
    ~FightWindow();
    void updateLifeBar(float damage);
    sf::RectangleShape lifeBarOutline;
private:
    Player* p1;
    Enemy* enemy;
    sf::RectangleShape lifeBar;                            // Rectangle for the life bar
    sf::Clock clock;


};

#endif