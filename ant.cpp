#include "Ant.h"

Ant::Ant(string type, sf::CircleShape& shape) {
    this->type = type;
    this->shape = shape;
    this->pheromoneCounter = 0;
    
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(1.0f, 3.0f);
    std::uniform_real_distribution<float> dist2(100.0f, 600.0f);
    this->velocity = sf::Vector2f(dist(gen), dist(gen));
    this->shape.setPosition(sf::Vector2f(dist2(gen), dist2(gen)));
}


void Ant::print() {
    sf::Vector2f pos = this->shape.getPosition();
    cout << "Type: " << this->type << " -- Position: (" << pos.x << ", " << pos.y << ")" << endl;

}

void Ant::updateVelocity(vector<Pheromone> pheremoneTrails){
    float clockwiseXRange = cos(SIGHT_ANGLE) * this->velocity.x;
    float clockwiseYRange = sin(SIGHT_ANGLE) * this->velocity.y;
    float anticlockwiseXRange = -1 * sin(SIGHT_ANGLE) * this->velocity.x;
    float anticlockwiseYRange = cos(SIGHT_ANGLE) * this->velocity.y;


    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distX(anticlockwiseXRange, clockwiseXRange);
    std::uniform_real_distribution<float> distY(100.0f, 600.0f);


}
void Ant::move(float xDirection, float yDirection) {
    this->shape.move(sf::Vector2f(xDirection, yDirection));
}

Pheromone Ant::createPheromone(string type) {
    sf::CircleShape pheromoneShape(2.f);
    pheromoneShape.setFillColor(sf::Color::Blue);
    pheromoneShape.setPosition(this->shape.getPosition());

    return Pheromone(type, pheromoneShape, 1.0f);
}

vector<Ant> createAnts(int count, vector<string> types) {
    vector<Ant> ants;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, types.size() - 1);

    for (int i = 0; i < count; i++) {
        int randomIndex = dist(gen);
        sf::CircleShape antShape(ANT_SIZE);
        sf::Vector2f initialPosition(0.f, 0.f);

        Ant newAnt(types[randomIndex], antShape);
        ants.push_back(newAnt);
    }
    return ants;
}
