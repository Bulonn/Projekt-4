#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

sf::RenderWindow window(sf::VideoMode(1280, 720), "Elevator");
sf::Sprite buttonf01, buttonf02, buttonf03, buttonf04, buttonf05, buttonf10, buttonf12, buttonf13, buttonf14, buttonf15, buttonf20, buttonf21, buttonf23, buttonf24, buttonf25, buttonf30, buttonf31, buttonf32, buttonf34, buttonf35, buttonf40, buttonf41, buttonf42, buttonf43, buttonf45, buttonf50, buttonf51, buttonf52, buttonf53, buttonf54;

void createButtons(sf::Sprite& buttonf01, sf::Sprite& buttonf02, sf::Sprite& buttonf03, sf::Sprite& buttonf04, sf::Sprite& buttonf05, sf::Sprite& buttonf10, sf::Sprite& buttonf12, sf::Sprite& buttonf13, sf::Sprite& buttonf14, sf::Sprite& buttonf15, sf::Sprite& buttonf20, sf::Sprite& buttonf21, sf::Sprite& buttonf23, sf::Sprite& buttonf24, sf::Sprite& buttonf25, sf::Sprite& buttonf30, sf::Sprite& buttonf31, sf::Sprite& buttonf32, sf::Sprite& buttonf34, sf::Sprite& buttonf35, sf::Sprite& buttonf40, sf::Sprite& buttonf41, sf::Sprite& buttonf42, sf::Sprite& buttonf43, sf::Sprite& buttonf45, sf::Sprite& buttonf50, sf::Sprite& buttonf51, sf::Sprite& buttonf52, sf::Sprite& buttonf53, sf::Sprite& buttonf54)
{
    sf::Texture Button0, Button1, Button2, Button3, Button4, Button5;
    Button0.loadFromFile("button0.png");
    Button1.loadFromFile("button1.png");
    Button2.loadFromFile("button2.png");
    Button3.loadFromFile("button3.png");
    Button4.loadFromFile("button4.png");
    Button5.loadFromFile("button5.png");
    buttonf10.setTexture(Button0);
    buttonf20.setTexture(Button0);
    buttonf30.setTexture(Button0);
    buttonf40.setTexture(Button0);
    buttonf50.setTexture(Button0);
    buttonf10.setPosition(sf::Vector2f(600, 300));
    buttonf20.setPosition(sf::Vector2f(620, 300));
    buttonf30.setPosition(sf::Vector2f(640, 300));
    buttonf40.setPosition(sf::Vector2f(660, 300));
    buttonf50.setPosition(sf::Vector2f(680, 300));
    buttonf01.setTexture(Button1);
    buttonf21.setTexture(Button1);
    buttonf31.setTexture(Button1);
    buttonf41.setTexture(Button1);
    buttonf51.setTexture(Button1);
    buttonf02.setTexture(Button2);
    buttonf12.setTexture(Button2);
    buttonf32.setTexture(Button2);
    buttonf42.setTexture(Button2);
    buttonf52.setTexture(Button2);
    buttonf03.setTexture(Button3);
    buttonf13.setTexture(Button3);
    buttonf23.setTexture(Button3);
    buttonf43.setTexture(Button3);
    buttonf53.setTexture(Button3);
    buttonf04.setTexture(Button4);
    buttonf14.setTexture(Button4);
    buttonf24.setTexture(Button4);
    buttonf34.setTexture(Button4);
    buttonf54.setTexture(Button4);
    buttonf05.setTexture(Button5);
    buttonf15.setTexture(Button5);
    buttonf25.setTexture(Button5);
    buttonf35.setTexture(Button5);
    buttonf45.setTexture(Button5);
}



void display_background()
{
    sf::Texture Background;
    sf::Sprite background;
    Background.loadFromFile("background.png");
    background.setTexture(Background);
    background.setPosition(sf::Vector2f(52, 0));
    window.draw(background);
}



void simulate(sf::Sprite& buttonf01, sf::Sprite& buttonf02, sf::Sprite& buttonf03, sf::Sprite& buttonf04, sf::Sprite& buttonf05, sf::Sprite& buttonf10, sf::Sprite& buttonf12, sf::Sprite& buttonf13, sf::Sprite& buttonf14, sf::Sprite& buttonf15, sf::Sprite& buttonf20, sf::Sprite& buttonf21, sf::Sprite& buttonf23, sf::Sprite& buttonf24, sf::Sprite& buttonf25, sf::Sprite& buttonf30, sf::Sprite& buttonf31, sf::Sprite& buttonf32, sf::Sprite& buttonf34, sf::Sprite& buttonf35, sf::Sprite& buttonf40, sf::Sprite& buttonf41, sf::Sprite& buttonf42, sf::Sprite& buttonf43, sf::Sprite& buttonf45, sf::Sprite& buttonf50, sf::Sprite& buttonf51, sf::Sprite& buttonf52, sf::Sprite& buttonf53, sf::Sprite& buttonf54)
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
        window.draw(buttonf10);
        window.draw(buttonf20);
        window.draw(buttonf30);
        window.draw(buttonf40);
        window.draw(buttonf50);

        window.display();
    }

}



int main()
{
    createButtons(buttonf01, buttonf02, buttonf03, buttonf04, buttonf05, buttonf10, buttonf12, buttonf13, buttonf14, buttonf15, buttonf20, buttonf21, buttonf23, buttonf24, buttonf25, buttonf30, buttonf31, buttonf32, buttonf34, buttonf35, buttonf40, buttonf41, buttonf42, buttonf43, buttonf45, buttonf50, buttonf51, buttonf52, buttonf53, buttonf54);
    simulate(buttonf01, buttonf02, buttonf03, buttonf04, buttonf05, buttonf10, buttonf12, buttonf13, buttonf14, buttonf15, buttonf20, buttonf21, buttonf23, buttonf24, buttonf25, buttonf30, buttonf31, buttonf32, buttonf34, buttonf35, buttonf40, buttonf41, buttonf42, buttonf43, buttonf45, buttonf50, buttonf51, buttonf52, buttonf53, buttonf54);
    return 0;
}
