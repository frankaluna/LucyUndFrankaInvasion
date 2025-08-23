#include "AlienControl.hpp"
#include <iostream>

AlienControl::AlienControl(Layer &layer) : layer(layer)
//alien(1, {300, -300})
{
    aliens = create_aliens();
}

std::vector<Alien> AlienControl::create_aliens() {
    std::vector<Alien> aliens;
    int i;
    int j;
    //create Alien rows
    for (i = 0; i < 6; i++){
        //create Alien columns
        for (j = 0; j < 10; j++) {
            float x = 83 + j * 48;
            float y = -548 + i * 48; 
            aliens.push_back(Alien(1, {x, y}));
            
        }
    }
    return aliens;
}

void AlienControl::draw_alien() {
    for(Alien& alien : aliens) {
         alien.draw(layer);
         std::cout<< "i am drawing an alien" << std::endl;
    }
}