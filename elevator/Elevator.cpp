#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

sf::RenderWindow window(sf::VideoMode(1280, 720), "Elevator");
sf::Sprite buttonf01, buttonf02, buttonf03, buttonf04, buttonf05, buttonf10, buttonf12, buttonf13, buttonf14, buttonf15, buttonf20, buttonf21, buttonf23, buttonf24, buttonf25, buttonf30, buttonf31, buttonf32, buttonf34, buttonf35, buttonf40, buttonf41, buttonf42, buttonf43, buttonf45, buttonf50, buttonf51, buttonf52, buttonf53, buttonf54;
const int F4B = 770;
const int F3B = 350;

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



    //rozmieszczenie przyciskow
    //------------------------------------------------------------------------------------------------
    sf::Texture Button0, Button1, Button2, Button3, Button4, Button5;
    int k = 20;
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
    buttonf40.setPosition(sf::Vector2f(F4B, 280));
    buttonf41.setPosition(sf::Vector2f(F4B + k, 280));
    buttonf42.setPosition(sf::Vector2f(F4B + 2 * k, 280));
    buttonf43.setPosition(sf::Vector2f(F4B + 3 * k, 280));
    buttonf45.setPosition(sf::Vector2f(F4B + 4 * k, 280));
    buttonf20.setPosition(sf::Vector2f(F4B, 530));
    buttonf21.setPosition(sf::Vector2f(F4B + k, 530));
    buttonf23.setPosition(sf::Vector2f(F4B + 2 * k, 530));
    buttonf24.setPosition(sf::Vector2f(F4B + 3 * k, 530));
    buttonf25.setPosition(sf::Vector2f(F4B + 4 * k, 530));
    buttonf10.setPosition(sf::Vector2f(F3B, 650));
    buttonf12.setPosition(sf::Vector2f(F3B + k, 650));
    buttonf13.setPosition(sf::Vector2f(F3B + 2 * k, 650));
    buttonf14.setPosition(sf::Vector2f(F3B + 3 * k, 650));
    buttonf15.setPosition(sf::Vector2f(F3B + 4 * k, 650));
    buttonf30.setPosition(sf::Vector2f(F3B, 410));
    buttonf31.setPosition(sf::Vector2f(F3B + k, 410));
    buttonf32.setPosition(sf::Vector2f(F3B + 2 * k, 410));
    buttonf34.setPosition(sf::Vector2f(F3B + 3 * k, 410));
    buttonf35.setPosition(sf::Vector2f(F3B + 4 * k, 410));
    buttonf50.setPosition(sf::Vector2f(F3B, 165));
    buttonf51.setPosition(sf::Vector2f(F3B + k, 165));
    buttonf52.setPosition(sf::Vector2f(F3B + 2 * k, 165));
    buttonf53.setPosition(sf::Vector2f(F3B + 3 * k, 165));
    buttonf54.setPosition(sf::Vector2f(F3B + 4 * k, 165));
    //------------------------------------------------------------------------------------------------


    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    sf::Vector2f worldPosition = window.mapPixelToCoords(mousePosition);

                    if (buttonf10.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 10" << std::endl;
                    }
                    if (buttonf12.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 12" << std::endl;
                    }
                    if (buttonf13.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 13" << std::endl;
                    }
                    if (buttonf14.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 14" << std::endl;
                    }
                    if (buttonf15.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 15" << std::endl;
                    }
                    if (buttonf20.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 20" << std::endl;
                    }
                    if (buttonf21.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 21" << std::endl;
                    }
                    if (buttonf23.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 23" << std::endl;
                    }
                    if (buttonf24.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 24" << std::endl;
                    }
                    if (buttonf25.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 25" << std::endl;
                    }
                    if (buttonf30.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 30" << std::endl;
                    }
                    if (buttonf31.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 31" << std::endl;
                    }
                    if (buttonf32.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 32" << std::endl;
                    }
                    if (buttonf34.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 34" << std::endl;
                    }
                    if (buttonf35.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 35" << std::endl;
                    }
                    if (buttonf40.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 40" << std::endl;
                    }
                    if (buttonf41.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 41" << std::endl;
                    }
                    if (buttonf42.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 42" << std::endl;
                    }
                    if (buttonf43.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 43" << std::endl;
                    }
                    if (buttonf45.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 45" << std::endl;
                    }
                    if (buttonf50.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 50" << std::endl;
                    }
                    if (buttonf51.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 51" << std::endl;
                    }
                    if (buttonf52.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 52" << std::endl;
                    }
                    if (buttonf53.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 53" << std::endl;
                    }
                    if (buttonf54.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Przycisk klikniety 54" << std::endl;
                    }
                }
            }
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear(sf::Color(255, 255, 255));
        display_background();
        window.draw(elevator);
        window.draw(buttonf40);
        window.draw(buttonf41);
        window.draw(buttonf42);
        window.draw(buttonf43);
        window.draw(buttonf45);
        window.draw(buttonf20);
        window.draw(buttonf21);
        window.draw(buttonf24);
        window.draw(buttonf23);
        window.draw(buttonf25);
        window.draw(buttonf10);
        window.draw(buttonf12);
        window.draw(buttonf13);
        window.draw(buttonf14);
        window.draw(buttonf15);
        window.draw(buttonf30);
        window.draw(buttonf31);
        window.draw(buttonf32);
        window.draw(buttonf34);
        window.draw(buttonf35);
        window.draw(buttonf50);
        window.draw(buttonf51);
        window.draw(buttonf52);
        window.draw(buttonf53);
        window.draw(buttonf54);

        window.display();
    }

}



int main()
{
    simulate(buttonf01, buttonf02, buttonf03, buttonf04, buttonf05, buttonf10, buttonf12, buttonf13, buttonf14, buttonf15, buttonf20, buttonf21, buttonf23, buttonf24, buttonf25, buttonf30, buttonf31, buttonf32, buttonf34, buttonf35, buttonf40, buttonf41, buttonf42, buttonf43, buttonf45, buttonf50, buttonf51, buttonf52, buttonf53, buttonf54);
    return 0;
}
