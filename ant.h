#ifndef ANT_H
#define ANT_H

#include <string>
#include <tuple>
#include <vector>
#include <random>
#include <iostream>

using namespace std;

class Ant {
public:
    string type;
    tuple<float, float> position;

    Ant(string type, tuple<float, float> position);

    void print();
    void move();
};

vector<Ant> createAnts(int count, vector<string> types);

#endif
