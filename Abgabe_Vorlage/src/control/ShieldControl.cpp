#include "ShieldControl.hpp"
#include <iostream>
//constructor that initialized with the given layer
ShieldControl::ShieldControl(Layer &layer) : 
layer(layer) 
{
 //create the shields   
 shields = create_shields();
}
//method for the set up of the shields
std::vector<std::shared_ptr<Shield>> ShieldControl::create_shields(){
    int i;
    float x = 54;
    float y = -125;

    //create row of shields
    for (i = 0; i < 4; i++) {
        //Shield shield({x, y});
        shields.push_back(std::make_shared<Shield>(sf::Vector2f{x, y}));
        //shield.draw(layer);
        x = x + 164;
    }
    return shields;
}
//draws every shiel to the game layer
void ShieldControl::draw() {
     for(auto &shield : shields){
        shield->draw(layer);
     }
}
//checking for collsions with lasers
void ShieldControl:: collisions_shield(std::shared_ptr<Laser> laser){
    //iteration through the shields to seek the ones that were hit
    auto iteration_shields = shields.begin();
    while(iteration_shields != shields.end()){
        if (laser->get_rectangle().getGlobalBounds().findIntersection((*iteration_shields)->get_sprite().getGlobalBounds())){
            iteration_shields = shields.erase(iteration_shields);
            laser->active = false; //deactivate laser when it hits
            //std::cout <<"shield attacked" << std::endl;
        }else{
            ++iteration_shields;
        }
    }   
}

