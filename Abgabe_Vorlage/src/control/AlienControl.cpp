#include "AlienControl.hpp"
#include <iostream>

AlienControl::AlienControl(Layer &layer) : layer(layer)

{
    aliens = create_aliens();
    speed = 50;
}

std::vector<std::shared_ptr<Alien>> AlienControl::create_aliens() {
    std::vector<std::shared_ptr<Alien>> aliens;
    int i;
    int j;
    int type;
    
    //create Alien rows
    for (i = 0; i < 4; i++){
        if (i == 0 || i == 1) {
        type = 1;
    }
    else if (i == 2 || i == 3) {
        type = 2;
    }
   
        //create Alien columns
        for (j = 0; j < 9; j++) {
            float x = 83 + j * 48;
            float y = -548 + i * 48; 
            aliens.push_back(std::make_shared<Alien> (type, sf::Vector2f {x, y}));
            aliens.back()->move_right();
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

void AlienControl::update_aliens(float elapsed_time) {
    for(auto &alien : aliens){
        float x = alien->get_position().x;
        if (alien->get_position().x < 25 && alien->get_horizontal_movement() == HorizontalDirection::LEFT) {
            speed = -speed;
            alien->move_right();
        }

        if (alien->get_position().x > 525 && alien->get_horizontal_movement() == HorizontalDirection::RIGHT) {
            speed = -speed;
            //std::cout << "ich bewege mich nach links" << std::endl;
            alien->move_left();
        }
        x += elapsed_time * speed;
        //std::cout << "ich bewege mich" << std::endl;
        alien->set_position(x, alien->get_position().y);
    }

}