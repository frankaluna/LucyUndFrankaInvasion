#include "Powerup.hpp"

Powerup::Powerup() : 
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

//movement left
void Powerup::move_left() {
   h_dir = HorizontalDirection::LEFT;
}

void Powerup::move_right() {
    h_dir = HorizontalDirection::RIGHT;
}

HorizontalDirection Powerup::get_horizontal_movement() const {
    return h_dir
}

void set_position(float x, float y) {
    position_x = x;
    position_y = y;
}

float get_position_x () const {
    return position_x;
}

float get_position_y () const {
    return position_y;
}


