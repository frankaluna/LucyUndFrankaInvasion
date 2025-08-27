#include "ShieldControl.hpp"
#include <iostream>
#include <vector>

ShieldControl::ShieldControl(Layer &layer) : 
layer(layer) 
{
create_shields();
}
std::vector<Shield> ShieldControl::create_shields(){
    int i;
    float x = 54;
    float y = -125;

    //create row of shields
    for (i = 0; i < 4; i++) {
        Shield shield({x, y});
        shields.push_back(shield);
        //shield.draw(layer);
        x = x + 164;
    }
    //return shields;
}
void ShieldControl::draw() {
     for(auto &shield : shields){
        shield.draw(layer);
     }
}


void ShieldControl:: collisions_shield(std::shared_ptr<Laser> laser){
    
    auto iteration_shields = shields.begin();
    while(iteration_shields != shields.end()){
        if (laser->get_rectangle().getGlobalBounds().findIntersection(iteration_shields->get_sprite().getGlobalBounds())){
            iteration_shields = shields.erase(iteration_shields);
            laser->active = false;
            std::cout <<"shield attacked" << std::endl;
        }else{
            ++iteration_shields;
        }
    }   
}

