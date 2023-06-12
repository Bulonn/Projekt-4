#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

sf::RenderWindow window(sf::VideoMode(1280, 720), "Elevator");

void display_background()
{
    sf::Texture Background;
    sf::Sprite background;
    Background.loadFromFile("background.png");
    background.setTexture(Background);
    background.setPosition(sf::Vector2f(52, 0));
    window.draw(background);
}



void simulate()
{
    sf::Texture Elevator;
    sf::Sprite elevator;
    Elevator.loadFromFile("elevator.png");
    elevator.setTexture(Elevator);
    elevator.setPosition(sf::Vector2f(532, 634));

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }
        
        window.clear(sf::Color(255, 255, 255));
        display_background();
        window.draw(elevator);
        window.display();
    }

}



int main()
{
    simulate();
    return 0;
}
