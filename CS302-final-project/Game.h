#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "TileMap.h"

/*
	Class that acts as the game engine.
	Wrapper class
*/

class Game {

private:

	// ******************************* Variables *******************************
	
	sf::RenderWindow *window;
	sf::VideoMode video_mode;
	sf::Event ev;

	int currentMap;
	int totalMaps;

	sf::Texture ballTexture;
	sf::Sprite golfBall;
	bool ballMovementTrue;
	sf::Vector2f ballMovementDir;
	int ballVelocity = 0;
	int ballAccel = 0;
	sf::Vector2f mousePosition;			// of mouse click

	sf::CircleShape hole;

	
	const int *mapArrays[9];
	std::vector<TileMap*> mapVector;
	// ******************************* Private Functions *******************************

	void initVariables();
	void initMaps();
	void initWindow();

public:

	// ******************************* Constructors / Destructors *******************************

	Game();
	virtual ~Game();

	// ******************************* Accessors *******************************

	const bool running() const;
	const bool isCollision() const;

	// ******************************* Functions *******************************

	void pollEvents();
	void updateMap();
	void moveGolfBall();
	
	void resetBallPosition();

	void update();
	void render();
};
