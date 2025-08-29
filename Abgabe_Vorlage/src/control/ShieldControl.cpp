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
        auto &shield = *iteration_shields;
        if (laser->get_rectangle().getGlobalBounds().findIntersection((*iteration_shields)->get_sprite().getGlobalBounds())){
            
            //reduce resilience
            shield->set_resilience(shield->get_resilience()-1);
            //deactivate laser
            laser->active = false;
            
            std::cout <<"shield attacked" << shield->get_resilience()  <<  std::endl;
            
            //reduce resilience if
            if (shield->get_resilience() <= 0){
                iteration_shields = shields.erase(iteration_shields);
                continue;
            }
            
        } ++iteration_shields;
        
       
    }   
}

