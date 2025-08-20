#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Directions.hpp"

//Player Model Class
class Player {
public:
//constructor and initialize
Player();

//movement left
void move_left();

//movement right
void move_right();

//action shoot
void shoot();


// check if character is moving right or left
    HorizontalDirection get_horizontal_movement() const;

// updates the character's position
    void set_position(float x, float y);

 // returns the character's current horizontal position
    float get_position() const;

// returns the sprite(picture) depicting the character
    const sf::Sprite &get_sprite() const;

//stop horizontal movements
void stop_horizontal_movement();

private:
sf::Texture texture;
sf::Sprite sprite;
   
// character's x and y position
sf::Vector2f position;

// character is moving left or right
HorizontalDirection h_dir;

};
#endif