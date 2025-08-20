#include "AlienControl.hpp"
#include <iostream>
AlienControl:: AlienControl(Layer &layer) : layer(layer){

}
void AlienControl:: add_alien(float x, float y, float speed){
    Alien alien;
    alien.set_position(x, y);
    alien.set_speed(speed);
}