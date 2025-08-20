#include "Alien.hpp"

Alien:: Alien() :
    texture(),
    sprite(texture),
    position({0,200}),
    h_dir(HorizontalDirection::LEFT),
    v_dir(VerticalDirection::NONE),
    speed(0)
{
     if (!texture.loadFromFile("assets/images/alien1_g.png"))
        throw std::invalid_argument("Spritesheet not found");
    //set up sprite
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect({0, 0}, {32, 32}));
    sprite.setOrigin({16, 16}); // middle point
    sprite.setPosition(position);
}

//movements
void Alien:: move_right(){
    h_dir = HorizontalDirection::RIGHT;
}
void Alien:: move_left(){
    h_dir = HorizontalDirection::LEFT;   
}
void Alien:: move_down(){
    v_dir = VerticalDirection::DOWN;
}
void Alien::draw(Layer &layer) {
    layer.add_to_layer(sprite);
}

//shoot action
void Alien:: shoot(){
    //shoot action noch ergänzen!!!
}

//return direction(left, right, none)
HorizontalDirection Alien:: get_horizontal_movement() const{
    return h_dir;
}

//get position as vector
sf::Vector2f Alien::get_position() {
    return position;
}

//set x and y position
void Alien:: set_position(float x, float y){
    position.x = x;
    position.y = y;
}

//get Sprite picture
const sf::Sprite& Alien:: get_sprite() const {
    return sprite;
}

// get speed
float Alien:: get_speed() const{
    return speed;
}

// set speed
void Alien:: set_speed(float newSpeed) {
    speed= newSpeed;
}