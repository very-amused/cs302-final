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
    /*sf::CircleShape sand(60);
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

    //creates flag


    //creates power meter outline
    sf::RectangleShape powerMeterGreen(sf::Vector2f(20, 50));
    powerMeterGreen.setFillColor(sf::Color::White);
    powerMeterGreen.setPosition(150, 140);
    sf::RectangleShape powerMeterYellow(sf::Vector2f(20, 30));
    powerMeterYellow.setFillColor(sf::Color::Yellow);
    powerMeterYellow.setPosition(150, 110);
    sf::RectangleShape powerMeterRed(sf::Vector2f(20, 10));
    powerMeterRed.setFillColor(sf::Color::Red);
    powerMeterRed.setPosition(150, 100);*/

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
    const int *combined[] = { level, level2, level3, level4 };
    unsigned short randomMap = rand() % 2;
    // create the tilemap from the level definition
    TileMap map;
    if (!map.load("C://Users/owenn/source/repos/Project1/sfml/include/SFML/graphics-vertex-array-tilemap-tileset.png", sf::Vector2u(32, 32), combined[3], 16, 8))
    {
        return -1;
    }
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // draw the map
        window.clear();
        window.draw(map);
        window.draw(hole);
        window.display();
    }

    return 0;
}

int main() {
    return WinMain();
}
