#include "Player.hpp"


Player::Player(int score, int hearts) : 
    position_x(0),
    position_y(-200),
    h_dir(HorizontalDirection:: NONE),
    texture(),
    sprite(texture){
    //load texture
    //hier Bild invader !!!
    //set up up sprite
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::intRect({0,0}, {100,100}));
    sprite.setOrigin({50,100});
    sprite.setPosition({300,0}); //sprite sachen noch anpassen!!!
}

//movement right
void Player:: move_right() {
    h_dir = HorizontalDirection:: RIGHT;
}
//movement left
void Player:: move_left(){
    h_dir = HorizontalDirection:: LEFT;
}
//stop any horizontal movement
void Player:: stop_horizontal_movement(){
    h_dir = HorizontalDirection:: NONE;
}
//action shoot
void Player:: shoot(){
//finish after doing projectile class
}
//return direction (left, right, none)
HorizontalDirection Player::get_horizontal_movement() const{
    h_dir;
}
//getter position x
float Player:: get_position_x() const {
    return position_x;
}
//getter position y
float Player:: get_position_y() const {
    return position_x;
}
//setter position
void Player::set_position(float x, float y) {
    position_x = x;
    position_y = y;
}
//Sprite getter
const sf::Sprite& Player::get_sprite() const {
    return sprite;
}
//getter score
int Player::get_score() const{
    return score;
}
//setter score
void Player::set_score(int newScore){
    score = newScore;
}
//getter hearts
int Player:: get_hearts() const{
    return hearts
}
void Player:: set_hearts(int newHearts){
    hearts = newHearts;
}