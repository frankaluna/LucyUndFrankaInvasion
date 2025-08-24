#include "AlienControl.hpp"
#include <iostream>

AlienControl::AlienControl(Layer &layer) : layer(layer)

{
    aliens = create_aliens();
}

std::vector<std::shared_ptr<Alien>> AlienControl::create_aliens() {
    std::vector<std::shared_ptr<Alien>> aliens;
    int i;
    int j;
    int type;
    
    //create Alien rows
    for (i = 0; i < 6; i++){
        if (i == 0 || i == 1) {
        type = 1;
    }
    else if (i == 2 || i == 3) {
        type = 2;
    }
    else if (i == 4 || i == 5) {
        type = 3;
    }
        //create Alien columns
        for (j = 0; j < 10; j++) {
            float x = 83 + j * 48;
            float y = -548 + i * 48; 
            aliens.push_back(std::make_shared<Alien> (type, sf::Vector2f {x, y}));
            
        }
    }
    return aliens;
}

void AlienControl::draw_alien() {
    for(auto &alien : aliens) {
        //layer.add_to_layer(alien->get_sprite());
        alien->draw(layer);
       }
}
