#include "Player.hpp"

Player::Player() :

  position({300, -50}), //um an screen anzupassen: position({(GetScreenWidth()-image.width)/?, (GetScreenHight() - imahe.hight/?})
    texture(),
    sprite(texture)
{
    

     if (!texture.loadFromFile("/home/f/ffreeric/LucyUndFrankaInvasion/Abgabe_Vorlage/assets/images/alien1_g.png"))
        throw std::invalid_argument("Spritesheet not found");
    //set up sprite
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect({0, 0}, {32, 32}));
    sprite.setOrigin({16, 16}); // middle point
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
//get position as vector
sf::Vector2f Player::get_position() {
    return position;
}
//setter position
void Player::set_position(float x, float y) {
    position.y = y;
    position.x = x;
    sprite.setPosition(position);
}
//Sprite getter
const sf::Sprite& Player::get_sprite() const {
    return sprite;
}