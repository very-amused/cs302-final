#include "Game.h"
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
	this->ballTexture.loadFromFile("C:/Users/larry/source/repos/CS302-final-project/CS302-final-project/assets/player/textures/golf-ball.png");
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

    const int level[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };
    const int level2[] =
    {
        0, 3, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 3, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
        0, 0, 3, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 2, 0,
        2, 0, 3, 0, 0, 0, 2, 2, 2, 0, 0, 0, 1, 1, 1, 1,
        0, 0, 3, 0, 0, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };
    const int level3[] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3,
        0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 3, 3, 0, 0,
        0, 0, 0, 0, 1, 1, 1, 2, 0, 0, 0, 3, 3, 0, 2, 0,
        2, 0, 0, 0, 0, 0, 2, 2, 3, 3, 3, 3, 0, 0, 0, 0,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0,
    };
    const int level4[] =
    {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 1,
        1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 3, 3, 0, 1,
        1, 0, 0, 0, 1, 1, 1, 2, 0, 0, 0, 3, 3, 0, 2, 1,
        1, 0, 0, 0, 0, 0, 2, 2, 3, 3, 3, 3, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    };
    const int level5[] =
    {
        0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 3, 3, 3,
        0, 0, 0, 0, 1, 1, 1, 3, 3, 0, 0, 0, 3, 3, 0, 0,
        0, 0, 0, 0, 1, 1, 1, 1, 3, 0, 0, 3, 3, 0, 2, 0,
        0, 0, 0, 0, 0, 0, 2, 2, 3, 3, 3, 3, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0,
    };
    const int level6[] =
    {
        1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 3, 3, 3, 0, 0, 0, 0, 0, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 2, 3, 3, 0, 0, 0, 3, 3, 0, 0,
        0, 0, 0, 0, 2, 2, 2, 2, 3, 0, 0, 3, 3, 0, 2, 0,
        0, 0, 0, 0, 0, 2, 2, 2, 3, 3, 3, 3, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0, 0,
    };
    const int level7[] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0,
        0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    const int level8[] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0,
        0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0,
        3, 3, 3, 3, 3, 0, 0, 2, 0, 0, 3, 3, 3, 3, 3, 3,
    };
    const int level9[] =
    {
        0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 0, 0, 0, 0, 2, 2, 1, 1, 0, 0, 0, 0, 0, 2, 0,
        0, 0, 0, 0, 0, 0, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    };
    const int* combined[] = { level, level2, level3, level4, level5, level6, level7, level8, level9 };

    // ******************************* Maps *******************************


    for (int i = 0; i < totalMaps; i++)
    {
        // Makes TileMap* and stores it in mapVector
        TileMap* map = new TileMap;
        map->load("C:/Users/larry/source/repos/CS302-final-project/CS302-final-project/assets/player/textures/graphics-vertex-array-tilemap-tileset.png", sf::Vector2u(32, 32), combined[i], 16, 8);
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

void Game::pollEvents()
{
	// handle events
	while (this->window->pollEvent(this->ev))
	{	

		if (this->ev.type == sf::Event::KeyPressed) 
        {
            // Pressing R will reset the screen
            if(ev.key.code == sf::Keyboard::R) 
            {
                this->resetBallPosition();
            }
            // Pressing N will move on
            else if (ev.key.code == sf::Keyboard::N)
            {
                this->updateMap();
            }
		}
        if (this->ev.type == sf::Event::MouseButtonPressed)
        {
            this->ballMovementTrue = !ballMovementTrue;
            //std::cout << ballMovementTrue << "\n";
            mousePosition.x = this->ev.mouseButton.x;
            mousePosition.y = this->ev.mouseButton.y;
            //std::cout << "mouse x: " << this->ev.mouseButton.x << std::endl;
            //std::cout << "mouse y: " << this->ev.mouseButton.y << std::endl;

        }

		if (this->ev.type == sf::Event::Closed || this->currentMap == 8) 
		{
			this->window->close();
		}
	}
}

void Game::updateMap()
{
    std::cout << "Map #" << this->currentMap + 2 << "\n";
    this->currentMap++;
    this->resetBallPosition();
}

void Game::moveGolfBall()
{   
    sf::Vector2f ballPosition = golfBall.getPosition();
    float x_velocity = (mousePosition.x - ballPosition.x) / 50;
    float y_velocity = (mousePosition.y - ballPosition.y) / 50;

    // Stupid movement
    if (ballMovementTrue)
    {
        golfBall.move(x_velocity, y_velocity);
    }
}

void Game::resetBallPosition()
{
    // Call Reset for each map
    this->golfBall.setPosition(10.f, video_mode.height / 2);
    this->ballMovementTrue = false;
}

void Game::update()
{
	this->pollEvents();
    this->moveGolfBall();
}

void Game::render()
{
	this->window->clear();					            // Clears old frame
    
    // Resets screen and changes map when ball makes contact with the hole
    if (isCollision())
    {
        updateMap();
    }

    this->window->draw(*this->mapVector[currentMap]);   // Draws map
	this->window->draw(hole);				            // Draws hole
	this->window->draw(golfBall);			            // Draws golfBall

	this->window->display();
}
