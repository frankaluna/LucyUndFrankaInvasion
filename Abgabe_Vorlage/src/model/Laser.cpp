#include "Laser.hpp"

Laser::Laser(sf::Vector2f position, int speed)
{
    this -> position = position;
    this -> speed = speed;
}
//dt: delta time
void Laser::update(float dt){
    position.y += speed * dt;
}

void Laser::draw(Layer &layer){
sf::RectangleShape rectangle({4.f, 15.f});
rectangle.setFillColor(sf::Color::Green);
rectangle.setPosition(position);
layer.add_to_layer(rectangle);
layer.draw();

}