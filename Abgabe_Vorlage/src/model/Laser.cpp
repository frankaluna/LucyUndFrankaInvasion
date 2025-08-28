#include "Laser.hpp"
#include <iostream>

Laser::Laser(sf::Vector2f position, int speed) : rectangle(sf::Vector2f ({4.f, 15.f}))
{
    this -> position = position; //initializes position
    this -> speed = speed;       //intitializes speed
    active = true;               //initializes active status

}

//handles laser updates
void Laser::update(float dt){       //dt: delta time
    //moves laser
    position.y += speed * dt;
    if (active){
        //deactivates laser if its out of the screen
        if(position.y < -600 || position.y >0){
            active = false;
        }
    }
}

//draws active lasers
void Laser::draw(Layer &layer){
    if (!active){
        return;
    }

//rectangle in an Pink Color as laser
rectangle.setFillColor(sf::Color{ 232, 9, 121});
rectangle.setPosition(position);
layer.add_to_layer(rectangle); //draws laser
}

//returns lasers speed
int Laser::get_speed(){
    return speed;
}

//returns lasers shape
const sf::RectangleShape& Laser::get_rectangle() const {
    return rectangle;
}