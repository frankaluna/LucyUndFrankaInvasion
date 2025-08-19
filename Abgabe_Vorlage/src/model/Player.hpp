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
Player(int score = 0, int hearts = 3);

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
    float get_position_x() const;

//return the character's current vertical position (unchanging)
    float get_position_y() const;

// returns the sprite(picture) depicting the character
    const sf::Sprite &get_sprite() const;

//getter score
int get_score() const;

//setter score
void set_score(int newScore);

//getter hearts
int get_hearts() const;

//setter hearts
void set_hearts(int newHearts);

//stop horizontal movements
void stop_horizontal_movement();

private:
sf::Texture texture;
sf::Sprite sprite;
   
// character's x and y position
float position_x;
float position_y;
sf::Vector2f position;

// character is moving left or right
HorizontalDirection h_dir;

//trackment score
int score;

//trackment hearts
int hearts;


};
#endif