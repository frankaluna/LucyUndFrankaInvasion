#include "AlienControl.hpp"
#include <iostream>
AlienControl:: AlienControl(Layer &layer) : layer(layer){

}
//lets the alien shoot
void start_shoot();

//checking if alien can shoot again
bool can_shoot();

//updating aliens position
void update_alien();

//draw alien to layer
void draw_alien();

//get position of alien
float get_alien_hight();
float get_alien_length(); //Ergänzungen?

//set psoition AlienControl
float set_alien_hight();
float set_alien_length(); //Ergänzungen??
