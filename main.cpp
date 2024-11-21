#include<sfml/Graphics.hpp>

int WinMain()
{

    //creates the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Golf Sim");

    //creates green background
    sf::RectangleShape grass(sf::Vector2f(800, 600));
    grass.setFillColor(sf::Color::Green);

    //creates hole
    sf::CircleShape hole(10);
    hole.setFillColor(sf::Color::Black);
    hole.setPosition(700, 200);

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
    powerMeterRed.setPosition(150, 100);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(grass);
        window.draw(hole);
        window.draw(sand);
        window.draw(water);
        window.draw(flagPole);
        window.draw(powerMeterGreen);
        window.draw(powerMeterYellow);
        window.draw(powerMeterRed);

        window.display();
    }

    return 0;
}
