#include "Alien.hpp"

Alien:: Alien() :
    position_x(0),
    position_y(200),
    h_dir(HorizontalDirection:: LEFT),
    texture(),
    sprite(texture){
        //load texture
        //hier Bilder Alien
        //set up sprite
        sprite.setTexture(texture);
    sprite.setTextureRect(sf::intRect({0,0}, {100,100}));
    sprite.setOrigin({50,100});
    sprite.setPosition({300,0}); //sprite sachen noch anpassen!!!
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
//shoot action
void Alien:: shoot(){
    //shoot action noch ergänzen!!!
}
//return direction(left, right, none)
HorizontalDirection Alien:: get_horizontal_movement() const{
    h_dir;
}
//get position x
float Alien:: get_position_x() const{
    return position_x;
}
//get position y
float Alien:: get_position_y() const{
    return position_y;
}
//set x and y position
void Alien:: set_position(float x, float y){
    position_x = x;
    position_y = y;
}
//get Sprite picture
const sf::Sprite& Alien:: get_sprite() const {
    return sprite
}
// get speed
float Alien:: get_speed() const{
    return speed;
}
// set speed
void Alien:: set_speed(float newSpeed) {
    speed= newSpeed;
}