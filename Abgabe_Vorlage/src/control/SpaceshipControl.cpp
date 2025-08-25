#include "SpaceshipControl.hpp"
#include <random>

SpaceshipControl:: SpaceshipControl(Layer &layer) :
layer(layer), 
speed(0), 
last_seen(0), 
interval() //hier hast du aufgehört Luthy
{

}
//appearance of the spaceship
void SpaceshipControl::appear(){
    spaceship.set_position(spaceship.get_position().x,-565);

    //randomize the location where the spaceship pops up
    std::random_device randomizer;
    std::mt19937 generate(randomizer());
    std::uniform_int_distribution<> distribute(0,1);

    int random_x = distribute(generate);

    if (random_x == 0){
        //left side
        spaceship.set_position(0,spaceship.get_position().y);
        speed = 3;
    }else {
        //right side
        spaceship.set_position(600 - 32, spaceship.get_position().y) ; //screen width - image width
        speed = -3;
    }
    spaceship.alive = true;
}
void SpaceshipControl:: update() {
    if (!spaceship.alive) {
        appear();
    }

    if(spaceship.alive){
        sf::Vector2f position = spaceship.get_position();
        position.x += speed;
        spaceship.set_position(position.x, position.y);
        
        //check if spaceshift has left the view
        if(position.x > 600 - 32 || position.x <0){
            spaceship.alive = false;
        }
    }
}
void SpaceshipControl::draw_spaceship(){
    if(spaceship.alive){
        spaceship.draw(layer);
    }
}