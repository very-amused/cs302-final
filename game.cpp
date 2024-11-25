#include "Game.h"

// ******************************* Private functions *******************************

void Game::initVariables()	
{
	this->window = nullptr;		// Set window to null just to initialize
}

void Game::initWindow()
{
	// Set VideoMode height and width
	this->video_mode.height = 600;
	this->video_mode.width = 800;

	this->window = new sf::RenderWindow(this->video_mode, "Game 1", sf::Style::Titlebar | sf::Style::Close);
}

// ******************************* Constructors / Destructors *******************************

Game::Game()	// Constructor
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()	// Destructor
{
	delete this->window;
}

// ******************************* Accessors *******************************

const bool Game::running() const
{
	return this->window->isOpen();
}

// ******************************* Functions *******************************

void Game::pollEvents()
{
	// Event Polling
	while (this->window->pollEvent(this->ev)) {

		switch (this->ev.type) {

			case sf::Event::Closed:
				this->window->close();
				break;

			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::Escape)
					this->window->close();
				break;
		}
	}
}

// Update game logic (Behind the scenes)
void Game::update()
{
	this->pollEvents();
}

// Rendering where everything is on the screen
void Game::render()
{	
	this->window->clear(sf::Color(255, 130,0));

	// Draw game objects

	this->window->display();
}