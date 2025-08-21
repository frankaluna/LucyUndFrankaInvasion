#include "Laser.hpp"

Laser::Laser(sf::Vector2f position, int speed)
{
    this -> position = position;
    this -> speed = speed;
}
void Laser::update(float dt){
    //noch ergänzen
}

void Laser::draw(Layer &layer){
sf::RectangleShape rectangle({4.f, 15.f});
rectangle.setFillColor(sf::Color::Green);
rectangle.setPosition(position);
layer.add_to_layer(rectangle);
layer.draw();

}