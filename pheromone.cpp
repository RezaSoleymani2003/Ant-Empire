#include "pheromone.h"

Pheromone::Pheromone(string type, const sf::CircleShape& shape, float intensity){
        this->type = type;
        this->intensity = intensity;
        this->shape = shape;

        // shape.setFillColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(intensity * 255)));
    }
        
void Pheromone::decay(float amount){
    if(amount < 0) amount *= -1;

    this->intensity -= amount;
    if (intensity < 0.0f){
        intensity = 0.0f;
    } 
    sf::Color color = shape.getFillColor();
    color.a = 255 * intensity - 255;
    this->shape.setFillColor(color);
}
