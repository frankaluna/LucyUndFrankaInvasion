#include "Laser.hpp"
#include <iostream>

Laser::Laser(sf::Vector2f position, int speed)
{
    this -> position = position;
    this -> speed = speed;
    active = true;
}
//dt: delta time
void Laser::update(float dt){
    position.y += speed * dt;
    if (active){
        if(position.y < -600 || position.y >0){
            active = false;
            std::cout<<"inactive Laser" << std::endl; 
        }
    }
}

void Laser::draw(Layer &layer){
    if (!active){
        return;
    }
sf::RectangleShape rectangle({4.f, 15.f});
//rectangle.setFillColor(sf::Color::Green);
rectangle.setFillColor(sf::Color{ 232, 9, 121});
rectangle.setPosition(position);
layer.add_to_layer(rectangle);
layer.draw();

}