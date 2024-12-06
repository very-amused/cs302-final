#include "Game.h"
#include "mapArrays.h"
#include <iostream>
// ******************************* Private Functions *******************************

void Game::initVariables()
{
	// ******************************* Normal Variables *******************************

	this->window = NULL;

	// Sets the video width and height
	this->video_mode.width = 512;
	this->video_mode.height = 256;

	this->currMapNum = 0;
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
	this->resetHolePosition();
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

	std::cout << "Map #" << this->currMapNum + 1 << "\n";
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
		currPosition.x = this->ev.mouseMove.x;
		currPosition.y = this->ev.mouseMove.y;

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
			this->ballMovementTrue = !ballMovementTrue;
			if (this->ballMovementTrue) {
				shotCounter++;
			}
			mousePosition.x = this->ev.mouseButton.x;
			mousePosition.y = this->ev.mouseButton.y;
		}
		if (this->ev.type == sf::Event::Closed || this->currMapNum == 8)
		{
			this->window->close();
		}
	}
}

void Game::moveGolfBall()
{
	// Calculates velocity x and y based on difference in position
	sf::Vector2f ballPosition = golfBall.getPosition();
	float x_velocity = (mousePosition.x - ballPosition.x) / 50;
	float y_velocity = (mousePosition.y - ballPosition.y) / 50;

	// Stupid movement
	if (ballMovementTrue)
	{

		golfBall.move(x_velocity, y_velocity);

		// Finds tile position according to map and resets position if touching water/tree
		sf::Vector2f position = golfBall.getPosition();
		int xCoord = position.x / 32;
		int yCoord = position.y / 32;

		
		if (mapArrays[currMapNum][yCoord * 16 + xCoord] == 2 || mapArrays[currMapNum][yCoord * 16 + xCoord] == 1) {
			this->resetBallPosition();
		}
	}
}

void Game::updateMap()
{
	// Updates things on map and prints map number 
	std::cout << "Map #" << this->currMapNum + 2 << "\n";

	this->currMapNum++;
	this->resetBallPosition();
	this->resetHolePosition();
}

void Game::resetBallPosition()
{
	// Call Reset for each map
	
	if (this->currMapNum == 0)
	{
		this->golfBall.setPosition(sf::Vector2f(10.f, 110.f));
	}
	else if (this->currMapNum == 1)
	{
		this->golfBall.setPosition(sf::Vector2f(70.f, 200.f));
	}
	else if (this->currMapNum == 2)
	{
		this->golfBall.setPosition(sf::Vector2f(10.f, 110.f));
	}
	else if (this->currMapNum == 3)
	{
		this->golfBall.setPosition(sf::Vector2f(9.f, 137.f));
	}
	else if (this->currMapNum == 4)
	{
		this->golfBall.setPosition(sf::Vector2f(100.f, 200.f));
	}
	else if (this->currMapNum == 5)
	{
		this->golfBall.setPosition(sf::Vector2f(8.f, 142.f));
	}
	else if (this->currMapNum == 6)
	{
		this->golfBall.setPosition(sf::Vector2f(10.f, 110.f));
	}
	else if (this->currMapNum == 7)
	{
		this->golfBall.setPosition(sf::Vector2f(10.f, 110.f));
	}
	else if (this->currMapNum == 8)
	{
		this->golfBall.setPosition(sf::Vector2f(10.f, 110.f));
	}

	
	this->ballMovementTrue = false;
}

void Game::resetHolePosition()
{
	// Call Reset for each map
	if (this->currMapNum == 0)
	{
		this->hole.setPosition(sf::Vector2f(485.f, 70.f));
	}
	else if (this->currMapNum == 1)
	{
		this->hole.setPosition(sf::Vector2f(490.f, 135.f));
	}
	else if (this->currMapNum == 2)
	{
		this->hole.setPosition(sf::Vector2f(485.f, 103.f));
	}
	else if (this->currMapNum == 3)
	{
		this->hole.setPosition(sf::Vector2f(455.f, 102.f));
	}
	else if (this->currMapNum == 4)
	{
		this->hole.setPosition(sf::Vector2f(485.f, 103.f));
	}
	else if (this->currMapNum == 5)
	{
		this->hole.setPosition(sf::Vector2f(485.f, 103.f));
	}
	else if (this->currMapNum == 6)
	{
		this->hole.setPosition(sf::Vector2f(490.f, 10.f));
	}
	else if (this->currMapNum == 7)
	{
		this->hole.setPosition(sf::Vector2f(490.f, 80.f));
	}
	else if (this->currMapNum == 8)
	{
		this->hole.setPosition(sf::Vector2f(490.f, 80.f));
	}
}


void Game::update()
{
	/* Every update each frame goes here */

	this->pollEvents();
	this->moveGolfBall();

	//std::cout << currPosition.x << " " << currPosition.y << "\n";
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
	this->window->draw(*this->mapVector[currMapNum]);   // Draws map
	this->window->draw(hole);				            // Draws hole
	this->window->draw(golfBall);			            // Draws golfBall

	this->window->display();
}
