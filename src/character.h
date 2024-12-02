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
	std::map<std::string, std::array<sf::Texture, 8>> charVars;
	std::string selectedCharacter;
	sf::Vector2f position;
	bool facingRight;
	bool alive = true;

public:
	//Character(int hlth, int attackPwr, int spd, int st, sf::Sprite& sprt);
	/*void attack(bool flip);
	void defend(bool flip);*/
	/*void idle(bool flip);*/
	//int virtual changeState(sf::Vector2f&, Character*) = 0; // calls attack, defend etc
	void move(int, Character*); // -1 for left, 1 for right
	void animate(bool flip, std::string&, int, int);

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

	void setCharVar(std::map<std::string, std::array<sf::Texture, 8>>&);
	std::map<std::string, std::array<sf::Texture, 8>>& getCharVar();

	sf::Clock& getAnimationClock();
	void setAnimationClock(sf::Clock& clk);

	sf::Texture& getCharTexture();

	void setCharTexture(sf::Texture&);

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f&);

	bool isFacingRight();
	void setFacingRight(bool);
	void changeDirection();

	virtual ~Character() = 0;

	bool isAlive();
	void die();




};

#endif