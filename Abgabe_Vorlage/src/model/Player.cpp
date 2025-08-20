#include "Player.hpp"


Player::Player(int score, int hearts) :
  position({300, -50}),
    texture(),
    sprite(texture)
{
    this->score = score;
    this->hearts = hearts;

     if (!texture.loadFromFile("/home/f/ffreeric/LucyUndFrankaInvasion/Abgabe_Vorlage/assets/images/alien1_g.png"))
        throw std::invalid_argument("Spritesheet not found");
    //set up sprite
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect({0, 0}, {32, 32}));
    sprite.setOrigin({16, 16});
    sprite.setPosition(position);

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

void Player::draw(Layer &layer) {
    layer.add_to_layer(sprite);
}

//action shoot
void Player:: shoot(){
//finish after doing projectile class
}
//return direction (left, right, none)
HorizontalDirection Player::get_horizontal_movement() const{
   return h_dir;
}
//getter position x
float Player:: get_position_x() const {
    return position_x;
}
//getter position y
float Player:: get_position_y() const {
    return position_y;
}

//get position as vector
sf::Vector2f Player::get_position() {
    return position;
}
//setter position
void Player::set_position(float x, float y) {
    position_x = x;
    position_y = y;
    position.y = y;
    position.x = x;
    sprite.setPosition(position);
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
    return hearts;
}
void Player:: set_hearts(int newHearts){
    hearts = newHearts;
}
