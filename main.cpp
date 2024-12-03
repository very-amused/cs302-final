#include "TileMap.h"
#include "Game.h"

int main()
{
    // //creates sand
    // sf::CircleShape sand(60);
    // sand.setFillColor(sf::Color(194, 178, 128));
    // sand.setPosition(400, 400);

    // //creates water
    // sf::CircleShape water(80);
    // water.setFillColor(sf::Color::Blue);
    // water.setPosition(300, 60);

    // //creates flagpole
    // sf::RectangleShape flagPole(sf::Vector2f(5, 60));
    // flagPole.setFillColor(sf::Color(170, 170, 170));
    // flagPole.setPosition(707, 150);

    // //creates ball
    // sf::Texture ballTexture;
    // sf::Sprite golfBall;

    // ballTexture.loadFromFile("C:/Users/swagm/source/repos/SFML Tutorial/SFML Tutorial/assets/player/textures/golf-ball.png");
    // golfBall.setTexture(ballTexture);


    // //creates power meter outline
    // sf::RectangleShape powerMeterGreen(sf::Vector2f(20, 50));
    // powerMeterGreen.setFillColor(sf::Color::White);
    // powerMeterGreen.setPosition(150, 140);
    // sf::RectangleShape powerMeterYellow(sf::Vector2f(20, 30));
    // powerMeterYellow.setFillColor(sf::Color::Yellow);
    // powerMeterYellow.setPosition(150, 110);
    // sf::RectangleShape powerMeterRed(sf::Vector2f(20, 10));
    // powerMeterRed.setFillColor(sf::Color::Red);
    // powerMeterRed.setPosition(150, 100);
    
    
    Game game;

    // Game Loop
    while (game.running())
    {
        // Update
        game.update();
        // Render
        game.render();

    }

    return 0;
}