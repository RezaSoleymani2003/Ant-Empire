#ifndef PHEROMONE_H
#define PHEROMONE_H

#include <string>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Pheromone {
public:
    string type;
    float intensity;
    sf::CircleShape shape;

    Pheromone(string type, const sf::CircleShape& shape, float intensity = 1.0f);
    

    void decay(float amount);
};


#endif
