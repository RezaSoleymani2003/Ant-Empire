#include "Ant.h"

Ant::Ant(string type, tuple<float, float> position) {
    this->type = type;
    this->position = position;
}

void Ant::print() {
    cout << "Type: " << type << " -- Position: (" << get<0>(position) << "," << get<1>(position) << ")" << endl;
}

void Ant::move() {
   
}

vector<Ant> createAnts(int count, vector<string> types) {
    vector<Ant> ants;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, types.size() - 1);

    for (int i = 0; i < count; i++) {
        int randomIndex = dist(gen);
        Ant newAnt(types[randomIndex], make_tuple(0, 0));
        ants.push_back(newAnt);
    }
    return ants;
}
