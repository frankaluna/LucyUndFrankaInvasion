#ifndef ALIEN_HPP
#define ALIEN_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "Directions.hpp"
#include "../view/Layer.hpp"

//!!! attention to the fact that our aliens = invaders which in our case are spaceships instead of aliens
//Alien Model Class
class Alien{
public:
//constructor and initialize
Alien(int type, sf::Vector2f position);


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

//return invader position as a vector
sf::Vector2f get_position();

// sprite for alien
const sf:: Sprite &get_sprite() const;

//getter speed
float get_speed() const;

//setter speed
void set_speed (float newSpeed);

int get_type();

//updates ALien
void update();

//draw the alien
void draw(Layer &layer);

private:
sf::Vector2f position;
sf::Texture texture;
sf:: Sprite sprite;

int type;

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