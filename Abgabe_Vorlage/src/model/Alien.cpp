#include "Alien.hpp"

Alien:: Alien() :
    texture(),
    sprite(texture),
    position_x(0),
    position_y(200),
    h_dir(HorizontalDirection::LEFT),
    //v_dir(VerticalDirection::NONE), // muss initialisiert werden, sonst undefiniert
    speed(0)
{
    sprite.setTexture(texture);
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
    return h_dir;
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