#include <SFML/Graphics.hpp>
#include "ant.h"

using namespace std;
int main()
{
    Ant ant("Green", make_tuple(200,200));

    cout << ant.type << endl; 
    ant.print();
    
    // vector<string> types = {"Red", "Green"};
    // vector<Ant> ants = createAnts(4, types);

    // for(Ant& ant: ants){
    //     ant.print();
    // } 

    sf::RenderWindow window(sf::VideoMode({700, 700}), "SFML Sucks!");
    sf::CircleShape antShape(5.f);
    sf::Vector2u windowSize = window.getSize();

    antShape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        // _sleep(2);
        while (const std::optional event = window.pollEvent())
        {   
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        sf::Vector2f currentPosition = antShape.getPosition();


        if (currentPosition.x + antShape.getRadius() * 5 <= windowSize.x &&
            currentPosition.y + antShape.getRadius() * 5 <= windowSize.y &&
            currentPosition.x >= 0 && currentPosition.y >= 0) {
            // If the new position is within bounds, move the shape
            antShape.move(sf::Vector2f(1.f, 1.f));
        }else{
            antShape.move(sf::Vector2f(-300.f, -300.f));

        }

        window.clear();
        window.draw(antShape);
        window.display();
    }
}