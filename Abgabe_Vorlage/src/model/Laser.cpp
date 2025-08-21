#include "Laser.hpp"

Laser::Laser(sf::Vector2f position, int speed)
{
    this -> position = position;
    this -> speed = speed;
}
void Laser::draw(Layer &layer){
    // define a 4x15 rectangle in a green color
sf::RectangleShape rectangle({4.f, 15.f});
rectangle.setFillColor(sf::Color::Green);
rectangle.setPosition(position);
layer.add_to_layer(rectangle);
}