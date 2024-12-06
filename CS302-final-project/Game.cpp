#include "Game.h"
#include "mapArrays.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <iostream>
// ******************************* Private Functions *******************************

void Game::initVariables()
{
	// ******************************* Normal Variables *******************************

	this->window = NULL;

	// Sets the video width and height
	this->video_mode.width = 512;
	this->video_mode.height = 256;

	this->currentMap = 0;
	this->totalMaps = 9;

	// Loading golf ball and texture
	this->ballTexture.loadFromFile("golf-ball.png");
	this->golfBall.setTexture(ballTexture);

	// Sets ball up at origin
	this->resetBallPosition();
	this->ballMovementTrue = false;



	// Create Hole on the screen
	this->hole.setRadius(10);
	this->hole.setFillColor(sf::Color::Black);
	this->hole.setPosition(400, 50);
}




void Game::initMaps()
{
	// ******************************* Levels *******************************

	// initializes arrays found in mapArrays.h
	mapArrays[0] = level1;
	mapArrays[1] = level2;
	mapArrays[2] = level3;
	mapArrays[3] = level4;
	mapArrays[4] = level5;
	mapArrays[5] = level6;
	mapArrays[6] = level7;
	mapArrays[7] = level8;
	mapArrays[8] = level9;
	
	// ******************************* Maps *******************************

	for (int i = 0; i < totalMaps; i++)
	{
		// Makes TileMap* and stores it in mapVector
		TileMap* map = new TileMap;
		// TODO: embed assets at build time
		map->load("graphics-vertex-array-tilemap-tileset.png", sf::Vector2u(32, 32), mapArrays[i], 16, 8);
		this->mapVector.push_back(map);
	}
}

void Game::initWindow()
{
	// Creates the window
	this->window = new sf::RenderWindow(this->video_mode, "Golf Sim");
	this->window->setFramerateLimit(60);
}

// ******************************* Constructors / Destructors *******************************

Game::Game()
{
	this->initVariables();
	this->initMaps();
	this->initWindow();

	std::cout << "Map #" << this->currentMap + 1 << "\n";
}

Game::~Game()
{
	delete this->window;
	for (auto tilemp : mapVector)
	{
		delete tilemp;
	}
}

// ******************************* Accessors *******************************

const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::isCollision() const
{
	return this->golfBall.getGlobalBounds().intersects(this->hole.getGlobalBounds());
}

// ******************************* Functions *******************************


static int shotCounter = 0;

void Game::pollEvents()
{
	// handle events
	while (this->window->pollEvent(this->ev))
	{

		if (this->ev.type == sf::Event::KeyPressed)
		{
			// Pressing R will reset the screen
			if (ev.key.code == sf::Keyboard::R)
			{
				this->resetBallPosition();
			}
			// Pressing N will move on
			else if (ev.key.code == sf::Keyboard::N)
			{
				this->updateMap();
			}
		}
		else if (this->ev.type == sf::Event::MouseButtonPressed)
		{
			// Initiate ball movement
			this->ballMovementTrue = !ballMovementTrue;
			mousePosition.x = this->ev.mouseButton.x;
			mousePosition.y = this->ev.mouseButton.y;
			if (this->ballMovementTrue) {
				// Get vector from ball pos to mouse pos
				sf::Vector2f ballPosition = golfBall.getPosition();
				ballMovementDir.x = (mousePosition.x - ballPosition.x);
				ballMovementDir.y = (mousePosition.y - ballPosition.y);
				// Set initial velocity as norm * 50
				float ballMovementNorm = sqrtf(powf(ballMovementDir.x, 2) + powf(ballMovementDir.y, 2));
				ballVelocity = 1;
				// Scale dir to a unit vector
				ballMovementDir.x /= ballMovementNorm;
				ballMovementDir.y /= ballMovementNorm;
				shotCounter++;
			}
		}
		if (this->ev.type == sf::Event::Closed || this->currentMap == 8)
		{
			this->window->close();
		}
	}
}

void Game::updateMap()
{
	// Updates things on map and prints map number 
	std::cout << "Map #" << this->currentMap + 2 << "\n";

	this->currentMap++;
	this->resetBallPosition();
}

void Game::moveGolfBall()
{
	// Calculates velocity x and y based on difference in position
	sf::Vector2f ballPosition = golfBall.getPosition();

	// Ball movement
	if (ballMovementTrue)
	{
		float x_velocity = std::max(ballMovementDir.x * ballVelocity, video_mode.width - ballPosition.x);
		float y_velocity = std::max(ballMovementDir.y * ballVelocity, video_mode.height - ballPosition.y);

		// Apply decel
		ballVelocity -= ballDecel;

		golfBall.move(x_velocity, y_velocity);

		// Finds tile position according to map and resets position if touching water/tree
		sf::Vector2f position = golfBall.getPosition();
		int xCoord = position.x / 32;
		int yCoord = position.y / 32;

		
		// Detect ball collision
		if (mapArrays[currentMap][yCoord * 16 + xCoord] == 2 || mapArrays[currentMap][yCoord * 16 + xCoord] == 1) {
			this->resetBallPosition();
		}
	}
}

void Game::resetBallPosition()
{
	// Call Reset for each map
	this->golfBall.setPosition(10.f, ((float)video_mode.height / 2));
	this->ballMovementTrue = false;
}


void Game::update()
{
	/* Every update each frame goes here */

	this->pollEvents();
	this->moveGolfBall();
}

void Game::render()
{
	this->window->clear();					            // Clears old frame for new render

	// Ball in the hole
	if (isCollision())
	{
		std::cout << "Total score: " << shotCounter << '\n';
		updateMap();
	}

	// All Drawing

	this->window->draw(*this->mapVector[currentMap]);   // Draws map
	this->window->draw(hole);				            // Draws hole
	this->window->draw(golfBall);			            // Draws golfBall

	this->window->display();
}
