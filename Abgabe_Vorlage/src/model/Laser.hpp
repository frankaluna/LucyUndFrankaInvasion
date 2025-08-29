#ifndef LASER_HPP
#define LASER_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "Directions.hpp"
#include "../view/Layer.hpp"

//class that handles lasers

class Laser{

    public:
    //constructor
    Laser(sf::Vector2f position, int speed);

    //updates lasers
    void update(float dt);

    //draws lasers
    void draw(Layer &layer);

    //is true if laser is active
    bool active;

    //returns lasers speed
    int get_speed();

    //returns lasers shape
    const sf::RectangleShape& get_rectangle() const;

    //returns the position of the laser
    sf::Vector2f get_position();

    private:
    //lasers position
    sf::Vector2f position;
    //lasers speed
    int speed;
    //lasers shape
    sf::RectangleShape rectangle;
    
};

#endif