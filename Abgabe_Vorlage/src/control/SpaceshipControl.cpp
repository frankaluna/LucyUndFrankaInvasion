#include "SpaceshipControl.hpp"
#include <random>
#include <iostream>

SpaceshipControl:: SpaceshipControl(Layer &layer) :
layer(layer), 
speed(0), 
last_seen(0.f), 
interval(0.f)
{
    //starts new random interval at the start
    start_interval();
}
void SpaceshipControl::start_interval(){
    std::random_device randomizer;
    std::mt19937 generate(randomizer());
    std::uniform_int_distribution<> distribute(10,20); //every 10 to 20 seconds

    interval = static_cast<float>(distribute(generate));
    last_seen = 0.f;
    collision = false;
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
        speed = 2;
    }else {
        //right side
        spaceship.set_position(600 - 32, spaceship.get_position().y) ; //screen width - image width
        speed = -2;
    }
    spaceship.alive = true;
}
void SpaceshipControl:: update(float dt) {
    if (!spaceship.alive) {
        last_seen += dt;
        
        if(last_seen >= interval){
            appear();
            start_interval(); //start a new interval for next appearance
        }
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

void SpaceshipControl::collisions_spaceship(std::shared_ptr<Laser> laser){
    if (laser->get_rectangle().getGlobalBounds().findIntersection(spaceship.get_sprite().getGlobalBounds())){
        laser->active = false;
        //when spaceship is unalived it disappears
        spaceship.alive = false;
        std::cout <<"spaceship down" << std::endl;
        collision = true;
    }
}