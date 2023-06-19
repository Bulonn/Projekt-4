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


float dis(float time, float velocity, bool kierunek)
{
    if (kierunek == 1)
    {
        return -(time * velocity);
    }
    else
    {
        return(time * velocity);
    }


}


void info();

class Elevator
{
public:

    int current_floor = 0;
    int current_weight = 0;
    int destiny = 0;
    int max_weight = 8;
    int people_on_1 = 0, people_on_2 = 0, people_on_3 = 0, people_on_4 = 0, people_on_5 = 0, people;
    bool direction = 1;

    std::vector<int> queue = {};
    std::vector<int> goals = {};

    int set_height(int from_floor_number) //PODANIE WARTOSCI PIKSELI NA JAKA MA DOTRZEC elev NA PODSTAWIE NUMERU DOCELOWEGO PIETRA
    {

        switch (from_floor_number)
        {
        case 0:
            return 634;
            break;
        case 1:
            return 500;
            break;
        case 2:
            return 377;
            break;
        case 3:
            return 254;
            break;
        case 4:
            return 131;
            break;
        case 5:
            return 8;
            break;
        }
    }



    bool is_valid(int from_floor, float y_pos) //SPRAWDZENIE POPRAWNOSCI ZGLOSZENIA Z AKTUALNYM RUCHEM WINDY
    {
        if (direction == 1 && y_pos < set_height(from_floor))
        {
            return 0;
        }
        else if (direction == 0 && y_pos > set_height(from_floor))
        {

            return 0;
        }
        else
        {
            return 1;
        }
    }


    void set_direction(int from_floor) //USTAWIANIE KIERUNKU PORUSZANIA SIE WINDY
    {
        if (from_floor > current_floor)
        {
            direction = 1;
        }
        else if (from_floor < current_floor)
        {
            direction = 0;
        }
    }


    
    void get_tasks(int from_floor, int goal, float y_pos) //TA FUNKCJA BEDZIE WYWOLYWANA TYLKO W MOMENCIE KLIKNIECIA PRZYCISKU
    {

        if (current_weight < max_weight) //SPRAWDZENIE CZY elev NIE JEST PRZEPELNIONA
        {

            if (is_valid(from_floor, y_pos)) //SPRAWDZENIE CZY ZGLOSZENIE SPELNIA WARUNKI WEZWANIA
            {

                if (current_weight == 0) //SPRAWDZENIE CZY elev JEST PUSTA
                {

                    set_direction(from_floor); //JAK PUSTA TO KOLEJNE ZGLOSZENIE NADAJE KIERUNEK
                }
                queue.push_back(from_floor);  //DODANIE DO KOLEJKI NUMERU Z KTOREGO elev JEST WZYWANA
                goals.push_back(goal); //DODANIE DO KOLEJKI NUMERU NA KTORE elev MA DOJECHAC Z PIETRA WEZWANIA
                people = people_on_1 + people_on_2 + people_on_3 + people_on_4 + people_on_5 + current_weight;
                if (from_floor == 1 && people < 8) people_on_1++;
                if (from_floor == 2 && people < 8) people_on_2++;
                if (from_floor == 3 && people < 8) people_on_3++;
                if (from_floor == 4 && people < 8) people_on_4++;
                if (from_floor == 5 && people < 8) people_on_5++;
            }
        }
        else if (current_weight == max_weight) //JESLI W WINDZIE ZNAJDUJE SIE MAKSYMALNA LICZBA OSOB
        {
            std::cout << "  | WINDA PRZECIAZONA, PROSZE CZEKAC AZ ZWOLNI SIE MIEJSCE |";
            return;
        }
    }


    
    void el_simulate(Elevator& e1, float time, float velocity, sf::Sprite& elev, sf::Clock& clock)
    {


        elev.getPosition().y;
        std::sort(e1.queue.begin(), e1.queue.end()); //POSORTOWANIE WEKTORA NUMEROW Z KTORYCH WINDA JEST WZYWANA
        std::sort(e1.goals.begin(), e1.goals.end()); //POSORTOWANIE WEKTORA NUMEROW NA KTORE WINDA MA DOJECHAC Z PIETRA WEZWANIA

        if (!e1.queue.empty()) //JESLI NADAL SA ZGLOSZENIA Z JAKIEGOS PIETRA 
        {
            //USTAWIANIE NAJBLIZSZEGO DOCELOWEGO PIETRA
            if (e1.direction == 1)
            {
                e1.destiny = e1.queue[0];
            }
            else if (e1.direction == 0)
            {
                e1.destiny = e1.queue[queue.size() - 1];
            }
            //JEDZ NA TE PIETRO AZ OSIAGNIE WYSOKOSC
            if ((e1.direction == 1 && (elev.getPosition().y > e1.set_height(e1.destiny))) || (e1.direction == 0 && (elev.getPosition().y < e1.set_height(e1.destiny))))
            {
                elev.move(0, dis(time, velocity, e1.direction)); //PRZESUN O OBLICZONA WARTOSC
            }
            else //WINDA DOTARLA NA DOCELOWA WYSOKOSC 
            {
                //JESLI OSIAGNELA TO PRZESZUKAJ WEKTOR NUMEROW Z KTORYCH WINDA JEST WZYWANA
                auto container_1 = std::find(e1.queue.begin(), e1.queue.end(), e1.destiny);
                while (container_1 != e1.queue.end())
                {
                    e1.queue.erase(container_1);
                    if (e1.current_weight != e1.max_weight) {
                        if (elev.getPosition().y > 490 && elev.getPosition().y < 550) people_on_1--;
                        if (elev.getPosition().y > 350 && elev.getPosition().y < 450) people_on_2--;
                        if (elev.getPosition().y > 220 && elev.getPosition().y < 280) people_on_3--;
                        if (elev.getPosition().y > 100 && elev.getPosition().y < 200) people_on_4--;
                        if (elev.getPosition().y > 1 && elev.getPosition().y < 50) people_on_5--;
                        e1.current_weight++;
                    }
                    ; //DODAJ TYLE LUDZI ILE CHCE WSIASC
                    container_1 = std::find(e1.queue.begin(), e1.queue.end(), e1.destiny);
                }
                //PRZESZUKAJ WEKTOR NUMEROW NA KTORE WINDA MA DOJECHAC Z PIETRA WEZWANIA
                auto container_2 = std::find(e1.goals.begin(), e1.goals.end(), e1.destiny);
                while (container_2 != e1.goals.end())
                {
                    e1.goals.erase(container_2);
                    if (e1.current_weight > 0) e1.current_weight--; //USUN TYLE LUDZI ILE CHCE WYSIASC
                    container_2 = std::find(e1.goals.begin(), e1.goals.end(), e1.destiny);
                }
                e1.current_floor = e1.destiny; //ZAKTUALIZUJ AKTUALNY NUMER PIETRA

                sf::sleep(sf::seconds(2));
                clock.restart();


            }
        }
        else if (e1.queue.empty() && !e1.goals.empty()) //JESLI JUZ NIKT NIE WZYWA A W WINDZIE NADAL ZNAJDUJA SIE OSOBY KTORE TRZEBA ODWIEZC 
        {
            //USTAWIANIE NAJBLIZSZEGO DOCELOWEGO PIETRA
            if (e1.goals[e1.goals.size() - 1] < e1.current_floor) e1.direction = 0;
            if (e1.direction == 1)
            {
                e1.destiny = e1.goals[0];
            }
            else if (direction == 0)
            {
                e1.destiny = e1.goals[e1.goals.size() - 1];

            }
            //JEDZ NA TE PIETRO AZ OSIAGNIE WYSOKOSC
            if ((e1.direction == 1 && (elev.getPosition().y > e1.set_height(e1.destiny))) || (e1.direction == 0 && (elev.getPosition().y < e1.set_height(e1.destiny))))
            {
                elev.move(0, dis(time, velocity, direction));
            }
            else //WINDA DOTARLA NA DOCELOWA WYSOKOSC 
            {
                //PRZESZUKAJ WEKTOR NUMEROW NA KTORE WINDA MA DOJECHAC Z PIETRA WEZWANIA
                auto container_2 = std::find(e1.goals.begin(), e1.goals.end(), e1.destiny);
                while (container_2 != e1.goals.end())
                {
                    e1.goals.erase(container_2);
                    if (e1.current_weight > 0) e1.current_weight--; //USUN TYLE LUDZI ILE CHCE WYSIASC
                    container_2 = std::find(e1.goals.begin(), e1.goals.end(), e1.destiny);

                }
                e1.current_floor = e1.destiny; //ZAKTUALIZUJ AKTUALNY NUMER PIETRA

                sf::sleep(sf::seconds(2));
                clock.restart();

            }
        }
        else if (e1.queue.empty() && e1.goals.empty() && current_floor != 0) //BRAK WEZWAN I WINDA W POLOZENIU INNYM NIZ PIETRO 0
        {
            e1.direction = 0; //KIERUNEK W DOL
            get_tasks(NULL, 0, elev.getPosition().y); //PRZYJMIJ ZLECENIE NA JAZDE NA PIETRO 0
            //ODCZEKAJ I ZJEDZ
            sf::sleep(sf::seconds(3));
            clock.restart();
        }
        else if (e1.queue.empty() && e1.goals.empty() && current_floor == 0) //WINDA W POCZTAKOWYM POLOZENIU I CZEKA NA ZLECENIA
        {
            e1.direction = 1;
        }
    }
};
Elevator e1;

void info()
{
    std::cout << "|Znajdujemy sie na pietrze:" << e1.current_floor << "|";
    std::cout << "|Ustawiono kierunek:" << e1.direction << "|";
    std::cout << "|Liczba osob:" << e1.current_weight << "|";
    std::cout << "|Aktualne wezwania na pietra:";

    for (const auto& element : e1.queue)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::cout << "| Aktualny wektor celow : ";

    for (const auto& element : e1.goals)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::cout << "| Cel : " << e1.destiny << " | ";

}

void simulate(sf::Sprite& buttonf01, sf::Sprite& buttonf02, sf::Sprite& buttonf03, sf::Sprite& buttonf04, sf::Sprite& buttonf05, sf::Sprite& buttonf10, sf::Sprite& buttonf12, sf::Sprite& buttonf13, sf::Sprite& buttonf14, sf::Sprite& buttonf15, sf::Sprite& buttonf20, sf::Sprite& buttonf21, sf::Sprite& buttonf23, sf::Sprite& buttonf24, sf::Sprite& buttonf25, sf::Sprite& buttonf30, sf::Sprite& buttonf31, sf::Sprite& buttonf32, sf::Sprite& buttonf34, sf::Sprite& buttonf35, sf::Sprite& buttonf40, sf::Sprite& buttonf41, sf::Sprite& buttonf42, sf::Sprite& buttonf43, sf::Sprite& buttonf45, sf::Sprite& buttonf50, sf::Sprite& buttonf51, sf::Sprite& buttonf52, sf::Sprite& buttonf53, sf::Sprite& buttonf54)
{
    sf::Texture Elevator;
    sf::Sprite elevator;
    Elevator.loadFromFile("elevator.png");
    elevator.setTexture(Elevator);
    elevator.setPosition(sf::Vector2f(532, 634));

    sf::Font font;
    font.loadFromFile("ka1.ttf");
    sf::Text cf, nf, cw, p1, p2, p3, p4, p5;;
    cf.setFont(font);
    cf.setCharacterSize(15);
    cf.setFillColor(sf::Color::Black);
    cf.setPosition(sf::Vector2f(50, 20));

    nf.setFont(font);
    nf.setCharacterSize(15);
    nf.setFillColor(sf::Color::Black);
    nf.setPosition(sf::Vector2f(50, 40));

    cw.setFont(font);
    cw.setCharacterSize(15);
    cw.setFillColor(sf::Color::Black);
    cw.setPosition(sf::Vector2f(50, 60));

    p1.setFont(font);
    p1.setCharacterSize(15);
    p1.setFillColor(sf::Color::Black);
    p1.setPosition(sf::Vector2f(455, 530));

    p2.setFont(font);
    p2.setCharacterSize(15);
    p2.setFillColor(sf::Color::Black);
    p2.setPosition(sf::Vector2f(750, 410));

    p3.setFont(font);
    p3.setCharacterSize(15);
    p3.setFillColor(sf::Color::Black);
    p3.setPosition(sf::Vector2f(455, 285));

    p4.setFont(font);
    p4.setCharacterSize(15);
    p4.setFillColor(sf::Color::Black);
    p4.setPosition(sf::Vector2f(750, 165));

    p5.setFont(font);
    p5.setCharacterSize(15);
    p5.setFillColor(sf::Color::Black);
    p5.setPosition(sf::Vector2f(455, 44));

    //ROZMIESZCZENIE PRZYCISKOW
    //------------------------------------------------------------------------------------------------------------------------
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
    //------------------------------------------------------------------------------------------------------------------------

    float vel = 60.0f; //WSPOLCZYNNIK DO OBLICZANIE PREDKOSCI
    sf::Clock clock, clock1; //ZEGAR
    float time = 0.0f; //ZMIENNA PRZECHOWUJACA CZAS

    while (window.isOpen()) //PETLA GLOWNA
    {

        //NAPISY INFORMACYJNE
        cf.setString("Current floor  " + std::to_string(e1.current_floor));
        nf.setString("Next floor  " + std::to_string(e1.destiny));
        cw.setString("People  " + std::to_string(e1.current_weight));
        p1.setString(std::to_string(e1.people_on_1));
        p2.setString(std::to_string(e1.people_on_2));
        p3.setString(std::to_string(e1.people_on_3));
        p4.setString(std::to_string(e1.people_on_4));
        p5.setString(std::to_string(e1.people_on_5));


        time = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed) {

                if (event.mouseButton.button == sf::Mouse::Left) {

                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    sf::Vector2f worldPosition = window.mapPixelToCoords(mousePosition);

                    if (buttonf10.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Wcisnieto 10" << std::endl;
                        e1.get_tasks(1, 0, elevator.getPosition().y);
                    }
                    if (buttonf12.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Wcisnieto 12" << std::endl;
                        e1.get_tasks(1, 2, elevator.getPosition().y);
                    }
                    if (buttonf13.getGlobalBounds().contains(worldPosition)) {


                        std::cout << "Wcisnieto 13" << std::endl;
                        e1.get_tasks(1, 3, elevator.getPosition().y);

                    }
                    if (buttonf14.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Wcisnieto 14" << std::endl;
                        e1.get_tasks(1, 4, elevator.getPosition().y);
                    }
                    if (buttonf15.getGlobalBounds().contains(worldPosition)) {


                        std::cout << "Wcisnieto 15" << std::endl;
                        e1.get_tasks(1, 5, elevator.getPosition().y);
                    }
                    if (buttonf20.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Wcisnieto 20" << std::endl;
                        e1.get_tasks(2, 0, elevator.getPosition().y);
                    }
                    if (buttonf21.getGlobalBounds().contains(worldPosition)) {


                        std::cout << "Wcisnieto 21" << std::endl;
                        e1.get_tasks(2, 1, elevator.getPosition().y);
                    }
                    if (buttonf23.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Wcisnieto 23" << std::endl;
                        e1.get_tasks(2, 3, elevator.getPosition().y);
                    }
                    if (buttonf24.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Wcisnieto 24" << std::endl;
                        e1.get_tasks(2, 4, elevator.getPosition().y);
                    }
                    if (buttonf25.getGlobalBounds().contains(worldPosition)) {


                        std::cout << "Wcisnieto 25" << std::endl;
                        e1.get_tasks(2, 5, elevator.getPosition().y);
                    }
                    if (buttonf30.getGlobalBounds().contains(worldPosition)) {


                        std::cout << "Wcisnieto 30" << std::endl;
                        e1.get_tasks(3, 0, elevator.getPosition().y);
                    }
                    if (buttonf31.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Wcisnieto 31" << std::endl;
                        e1.get_tasks(3, 1, elevator.getPosition().y);
                    }
                    if (buttonf32.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Wcisnieto 32" << std::endl;
                        e1.get_tasks(3, 2, elevator.getPosition().y);
                    }
                    if (buttonf34.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Wcisnieto 34" << std::endl;
                        e1.get_tasks(3, 4, elevator.getPosition().y);
                    }
                    if (buttonf35.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Wcisnieto 35" << std::endl;
                        e1.get_tasks(3, 5, elevator.getPosition().y);
                    }
                    if (buttonf40.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Wcisnieto 40" << std::endl;
                        e1.get_tasks(4, 0, elevator.getPosition().y);
                    }
                    if (buttonf41.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Wcisnieto 41" << std::endl;
                        e1.get_tasks(4, 1, elevator.getPosition().y);
                    }
                    if (buttonf42.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Wcisnieto 42" << std::endl;
                        e1.get_tasks(4, 2, elevator.getPosition().y);
                    }
                    if (buttonf43.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Wcisnieto 43" << std::endl;
                        e1.get_tasks(4, 3, elevator.getPosition().y);
                    }
                    if (buttonf45.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Wcisnieto 45" << std::endl;
                        e1.get_tasks(4, 5, elevator.getPosition().y);
                    }
                    if (buttonf50.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Wcisnieto 50" << std::endl;
                        e1.get_tasks(5, 0, elevator.getPosition().y);
                    }
                    if (buttonf51.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Wcisnieto 51" << std::endl;
                        e1.get_tasks(5, 1, elevator.getPosition().y);
                    }
                    if (buttonf52.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Wcisnieto 52" << std::endl;
                        e1.get_tasks(5, 2, elevator.getPosition().y);
                    }
                    if (buttonf53.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Wcisnieto 53" << std::endl;
                        e1.get_tasks(5, 3, elevator.getPosition().y);
                    }
                    if (buttonf54.getGlobalBounds().contains(worldPosition)) {

                        std::cout << "Wcisnieto 54" << std::endl;
                        e1.get_tasks(5, 4, elevator.getPosition().y);
                    }

                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            {
                info();
            }
            if (event.type == sf::Event::Closed) window.close();
        }

        e1.el_simulate(e1, time, vel, elevator, clock);

        window.clear(sf::Color(255, 255, 255));
        //WYSIWTELANIE SPRAJTOW
        //------------------------------------------------------------------------------------------------------
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
        window.draw(cf);
        window.draw(nf);
        window.draw(cw);
        window.draw(p1);
        window.draw(p2);
        window.draw(p3);
        window.draw(p4);
        window.draw(p5);

        //------------------------------------------------------------------------------------------------------

        window.display();
    }
}

int main()
{
    simulate(buttonf01, buttonf02, buttonf03, buttonf04, buttonf05, buttonf10, buttonf12, buttonf13, buttonf14, buttonf15, buttonf20, buttonf21, buttonf23, buttonf24, buttonf25, buttonf30, buttonf31, buttonf32, buttonf34, buttonf35, buttonf40, buttonf41, buttonf42, buttonf43, buttonf45, buttonf50, buttonf51, buttonf52, buttonf53, buttonf54);
    return 0;
}
