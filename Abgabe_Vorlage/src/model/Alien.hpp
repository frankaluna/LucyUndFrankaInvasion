#ifndef ALIEN_HPP
#define ALIEN_HP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Directions.hpp"


//Alien Model Class
class Alien{
public:
//constructor and initialize
Alien();

//movements
void move_right();
void move_left();
void move_down();

//action shoot
void shoot();

//check if aliens is moving right or left
    HorizontalDirection get_horizontal_movement() const;

//check if alien is moving up or down
    VerticalDirection get_vertical_movement() const;

//updates alien position
void set_position(float x, float y);

//alien's current horizontal position
float get_position_x() const;

//alien's current vertical position
float get_position_y() const;

// sprite for alien
const sf:: Sprite &get_sprite() const;

//getter speed
float get_speed() const;

//setter speed
void set_speed (float newSpeed);

private:
sf::Texture texture;
sf:: Sprite sprite;

// alien x and y positions
float position_x;
float position_y;

//stop horizontal movements
void stop_horizontal_movement();

// alien direction horizontal
HorizontalDirection h_dir;

//alien direction vertical
VerticalDirection v_dir;

//trackment speed
float speed;
};
#endif