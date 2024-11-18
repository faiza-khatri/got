#ifndef CHARACTER
#define CHARACTER

#include <string>
#include <map>
#include <array>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Character {
	/* virtual class for every character on the screen */
private:
	std::string name;
	int health;
	int attackPower;
	int speed;
	int state; // -1 for defensive, 0 for idle, 1 for offensive
	sf::Sprite sprite;
	sf::Clock animationClock; // Tracks time for frame updates
	float elapsedTime;
	int currentFrame;     // Index of the current frame
	int totalFrames = 0;      // Total frames in the animation
	sf::Texture charTexture;
	std::map<std::string, std::array<sf::Texture, 3>> charVars;
	std::string selectedCharacter;

public:
	//Character(int hlth, int attackPwr, int spd, int st, sf::Sprite& sprt);
	/*void attack(bool flip);
	void defend(bool flip);*/
	/*void idle(bool flip);*/
	void virtual changeState() = 0; // calls attack, defend etc
	void move(int); // -1 for left, 1 for right
	void animate(bool flip);
	/*void updateState(bool);*/
	void loadCharVarTextures(std::string&);
	void drawChar(sf::RenderWindow& window);

	std::string& getName();
	void setName(std::string&);

	std::string& getSelectedCharacter();
	void setSelectedCharacter(std::string&);

	int getHealth();
	void setHealth(int);

	int getAttackPower();
	void setAttackPower(int);

	int getSpeed();
	void setSpeed(int);

	int getState();
	void setState(int);

	int getCurrentFrame();
	void setCurrentFrame(int);

	float getElapsedTime();
	void setElapsedTime(float);

	sf::Sprite& getSprite();
	void setSprite(sf::Sprite&);

	sf::Texture& getTexture();
	void setTexture(sf::Texture&);

	void setCharVar(std::map<std::string, std::array<sf::Texture, 3>>&);
	std::map<std::string, std::array<sf::Texture, 3>>& getCharVar();

	sf::Clock& getAnimationClock();
	void setAnimationClock(sf::Clock& clk);

	sf::Texture& getCharTexture();

	void setCharTexture(sf::Texture&);

	virtual ~Character() = 0;




};

#endif