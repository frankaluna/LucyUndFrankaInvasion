#ifndef POWERUP_HPP
#define POWERUP_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Directions.hpp"

//Powerup model class

class Powerup {

    public:
    //constructor and initialize
    Powerup();

    //movement left
    void move_left();

    //movement right
    void move_right();

    //check if powerup is moving right or left
    HorizontalDirection get_horizontal_movement() const;


    //updates powerups position
    void set_position(float x, float y);

    //returns powerups horizontal position
    float get_position_x() const;

    //returns powerups vertical position
    float get_position_y() const;

    // returns the sprite(picture) depicting the Powerup
    const sf::Sprite &get_sprite() const;

private:

    sf::Texture texture;
    
    sf::Sprite sprite;

    //powerups x and y position
    float position_x;
    float position_y;

    //if powerup is moving left or right
    HorizontalDirection h_dir;

};

#endif