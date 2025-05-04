#ifndef ANT_H
#define ANT_H

#include <string>
#include <tuple>
#include <vector>
#include <random>
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "pheromone.h"

using namespace std;
const double PI = 3.141592653589793;
const float ANT_SIZE = 5.f;
const float SENSE_RANGE = 20.f;
const float SIGHT_ANGLE = PI * 60 / 180;

const float INIT_WEIGHT = 1.f;
const float RANDOM_WEIGHT = 1.f;
const float PHEROMONE_WEIGHT = 1.f;

class Ant {
public:
    string type;
    sf::CircleShape shape;
    sf::Vector2f velocity;
    int pheromoneCounter;
    
    Ant(string type, sf::CircleShape& shape);

    void print();
    void move(float xDirection,float yDirection);
    void updateVelocity(vector<Pheromone> pheremoneTrails);
    Pheromone createPheromone(string type);
};

vector<Ant> createAnts(int count, vector<string> types);
#endif
