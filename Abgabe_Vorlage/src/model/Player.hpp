#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Directions.hpp"
#include "../view/Layer.hpp"

//Player Model Class
class Player {
public:
//constructor and initialize
Player();

//movement left
void move_left();

//movement right
void move_right();

// check if character is moving right or left
HorizontalDirection get_horizontal_movement() const;

// updates the character's position
void set_position(float x, float y);

//return characters position as a vector
sf::Vector2f get_position();

//returns players current lives
int get_lives();

//sets players lives
void set_lives(int new_lives);

// returns the sprite(picture) depicting the character
const sf::Sprite &get_sprite() const;

//stop horizontal movements
void stop_horizontal_movement();

//draws player on layer
void draw(Layer &layer);

private:
sf::Vector2f position;  //players position
sf::Texture texture;    //players texture
sf::Sprite sprite;      //players sprite

//horizontal direction player is moving in
HorizontalDirection h_dir;   

//players lives
int lives;

};
#endif