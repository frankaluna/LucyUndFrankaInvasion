#include "AlienControl.hpp"
#include <iostream>

AlienControl::AlienControl(Layer &layer) : layer(layer)
//game_over(false)
{
    aliens = create_aliens();
    speed = 25;
    h_dir = HorizontalDirection::RIGHT;
    //je nachdem, wie die aliens sich weiter entwickeln, das vllt in eine andere Methode tun
    set_outer_aliens();
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

void AlienControl::set_outer_aliens() {

    most_left  = aliens.front();
    most_right = aliens.front();
    most_down = aliens.front();

    
    for (auto &alien : aliens) {
        float cur_pos = alien->get_position().x; 
        if (cur_pos > most_right->get_position().x){
            most_right = alien;
        }

        if (cur_pos < most_left->get_position().x){
            most_left = alien;
        }

        if (cur_pos < most_down->get_position().y){
            most_down = alien;
        }
    }
}

void AlienControl::update_aliens(float elapsed_time) {

    bool go_down = false;
        if (most_left->get_position().x < 25 && h_dir == HorizontalDirection::LEFT) {
            speed = -speed;
            h_dir = HorizontalDirection::RIGHT;
            go_down = true;
            
        }

        if (most_right->get_position().x > 575 && h_dir == HorizontalDirection::RIGHT) {
            speed = -speed;
            h_dir = HorizontalDirection::LEFT;
            go_down = true;
        }
       
        for(auto &alien : aliens){
        float x = alien->get_position().x;
        float y = alien->get_position().y;
        if(go_down){
            y += 16;
        }
        x += elapsed_time * speed;
        alien->set_position(x, y);
        }

    /*für wenn wir einen game over screen haben    
        if(most_down->get_position().y > -50){
            game_over = true;
        }
    */       
    }
/*
    void AlienControl::shoot_alien(){
        if (clock.getElapse)
    };

*/