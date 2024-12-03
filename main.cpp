#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "TileMap.h"

int WinMain()
{

    //creates the window
    sf::RenderWindow window(sf::VideoMode(512, 256), "Golf Sim");

    //creates green background
    /*sf::RectangleShape grass(sf::Vector2f(800, 600));
    grass.setFillColor(sf::Color::Green);*/

    //creates hole
    sf::CircleShape hole(10);
    hole.setFillColor(sf::Color::Black);
    hole.setPosition(400, 50);

    //creates sand
    sf::CircleShape sand(60);
    sand.setFillColor(sf::Color(194, 178, 128));
    sand.setPosition(400, 400);

    //creates water
    sf::CircleShape water(80);
    water.setFillColor(sf::Color::Blue);
    water.setPosition(300, 60);

    //creates flagpole
    sf::RectangleShape flagPole(sf::Vector2f(5, 60));
    flagPole.setFillColor(sf::Color(170, 170, 170));
    flagPole.setPosition(707, 150);

    //creates ball
    sf::Texture ballTexture;
    sf::Sprite golfBall;

    ballTexture.loadFromFile("C:/Users/swagm/source/repos/SFML Tutorial/SFML Tutorial/assets/player/textures/golf-ball.png");
    golfBall.setTexture(ballTexture);


    //creates power meter outline
    sf::RectangleShape powerMeterGreen(sf::Vector2f(20, 50));
    powerMeterGreen.setFillColor(sf::Color::White);
    powerMeterGreen.setPosition(150, 140);
    sf::RectangleShape powerMeterYellow(sf::Vector2f(20, 30));
    powerMeterYellow.setFillColor(sf::Color::Yellow);
    powerMeterYellow.setPosition(150, 110);
    sf::RectangleShape powerMeterRed(sf::Vector2f(20, 10));
    powerMeterRed.setFillColor(sf::Color::Red);
    powerMeterRed.setPosition(150, 100);

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
    unsigned short randomMap = rand() % 2;
    // create the tilemap from the level definition
    TileMap map1;
    TileMap map2;
    TileMap map3;
    TileMap map4;
    TileMap map5;
    TileMap map6;
    TileMap map7;
    TileMap map8;
    TileMap map9;
    map1.load("C:/Users/swagm/source/repos/SFML Tutorial/SFML Tutorial/assets/player/textures/graphics-vertex-array-tilemap-tileset.png", sf::Vector2u(32, 32), combined[0], 16, 8);
    map2.load("C:/Users/swagm/source/repos/SFML Tutorial/SFML Tutorial/assets/player/textures/graphics-vertex-array-tilemap-tileset.png", sf::Vector2u(32, 32), combined[1], 16, 8);
    map3.load("C:/Users/swagm/source/repos/SFML Tutorial/SFML Tutorial/assets/player/textures/graphics-vertex-array-tilemap-tileset.png", sf::Vector2u(32, 32), combined[2], 16, 8);
    map4.load("C:/Users/swagm/source/repos/SFML Tutorial/SFML Tutorial/assets/player/textures/graphics-vertex-array-tilemap-tileset.png", sf::Vector2u(32, 32), combined[3], 16, 8);
    map5.load("C:/Users/swagm/source/repos/SFML Tutorial/SFML Tutorial/assets/player/textures/graphics-vertex-array-tilemap-tileset.png", sf::Vector2u(32, 32), combined[4], 16, 8);
    map6.load("C:/Users/swagm/source/repos/SFML Tutorial/SFML Tutorial/assets/player/textures/graphics-vertex-array-tilemap-tileset.png", sf::Vector2u(32, 32), combined[5], 16, 8);
    map7.load("C:/Users/swagm/source/repos/SFML Tutorial/SFML Tutorial/assets/player/textures/graphics-vertex-array-tilemap-tileset.png", sf::Vector2u(32, 32), combined[6], 16, 8);
    map8.load("C:/Users/swagm/source/repos/SFML Tutorial/SFML Tutorial/assets/player/textures/graphics-vertex-array-tilemap-tileset.png", sf::Vector2u(32, 32), combined[7], 16, 8);
    map9.load("C:/Users/swagm/source/repos/SFML Tutorial/SFML Tutorial/assets/player/textures/graphics-vertex-array-tilemap-tileset.png", sf::Vector2u(32, 32), combined[8], 16, 8);
    TileMap maps[] = { map1, map2, map3, map4, map5, map6, map7, map8, map9 };

    int i = 0;

    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed ) {
                i = (i + 1);
            }
            if (i == 8)
            {
                window.close();
            }
        }

        // draw the map
            
            window.clear();
            window.draw(maps[i]);
            window.draw(hole);
            window.draw(golfBall);
            window.display();
            
           
    }

    return 0;
}

int main() {
    return WinMain();
}
