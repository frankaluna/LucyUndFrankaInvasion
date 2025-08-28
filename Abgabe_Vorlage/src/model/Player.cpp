#include "Player.hpp"

Player::Player() :
    position({300, -50}), //sets players start in the middle of the screen and on a fixed y position
    texture(),
    sprite(texture),
    lives(3)    //initializes lives to three
{
    //loads players texture (only once)
     if (!texture.loadFromFile("assets/images/Player.png")) 
        throw std::invalid_argument("Spritesheet not found");
    //set up sprite
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect({0, 0}, {32, 32}));
    sprite.setOrigin({16, 16}); // middle point
    sprite.setPosition(position);

}

//sets h_dir right
void Player:: move_right() {
    h_dir = HorizontalDirection:: RIGHT;
}
//sets h_dir left
void Player:: move_left(){
    h_dir = HorizontalDirection:: LEFT;
}
//sets horizontal movement to none
void Player:: stop_horizontal_movement(){
    h_dir = HorizontalDirection:: NONE;
}

//draws player on given layer
void Player::draw(Layer &layer) {
    layer.add_to_layer(sprite);
}

//returns horizontal direction (left, right, none)
HorizontalDirection Player::get_horizontal_movement() const{
   return h_dir;
}

//returns position as vector
sf::Vector2f Player::get_position() {
    return position;
}

//returns lives
int Player::get_lives() {
    return lives;
}

//sets lives
void Player::set_lives(int new_lives) {
    if(new_lives < 0) new_lives = 0; //lives shouldn´t be less than 0
    if(new_lives > 3) new_lives = 3; //lives should´t be more than 3
    lives = new_lives;
}

//sets players position and adjusts sprites position
void Player::set_position(float x, float y) {
    position.y = y;
    position.x = x;
    sprite.setPosition(position);
}

//gets sprite
const sf::Sprite& Player::get_sprite() const {
    return sprite;
}