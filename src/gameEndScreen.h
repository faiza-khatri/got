#ifndef  GAME_END
#define GAME_END

#include "baseWindow.h"

class EndScreen : public BaseWindow {
public:
    EndScreen(sf::Vector2u& windowSize, bool);
    void initializeComponents(sf::Vector2u&, int) override;
    void renderScreen(sf::RenderWindow& window) override;
    int handleInput(sf::RenderWindow&) override;
};




#endif