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
    collision = false;  //initializes collision to false
}


//starts a new interval at a random time
void SpaceshipControl::start_interval(){
    std::random_device randomizer;
    std::mt19937 generate(randomizer());
    std::uniform_int_distribution<> distribute(10,20); //every 10 to 20 seconds

    interval = static_cast<float>(distribute(generate));
    last_seen = 0.f;    //resets last_seen
}   

//appearance of the spaceship
void SpaceshipControl::appear(){
    spaceship.set_position(spaceship.get_position().x,-565);

    //randomize the location where the spaceship pops up
    std::random_device randomizer;
    std::mt19937 generate(randomizer());
    std::uniform_int_distribution<> distribute(0,1);

    int random_x = distribute(generate);
    //determines if spaceship is moving left or right and where it appears
    if (random_x == 0){
        //left side
        spaceship.set_position(0,spaceship.get_position().y);
        speed = 2;
    } else {
        //right side
        spaceship.set_position(600 - 32, spaceship.get_position().y) ; //screen width - image width
        speed = -2;
    }
    //sets spaceship status to alive
    spaceship.alive = true;
}

//handles spaceships updates
void SpaceshipControl:: update(float dt) {
    //counts how long since the spaceship was last seen
    if (!spaceship.alive) {
        last_seen += dt;
        //makes spaceship appear if its been a while since its been seen
        if(last_seen >= interval){
            appear();
            start_interval(); //start a new interval for next appearance
        }
    }

    //moves spaceship while its alive
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

//draws spaceship while it´s alive
void SpaceshipControl::draw_spaceship(){
    if(spaceship.alive){
        spaceship.draw(layer);
    }
}

//handles collisions with players lasers
void SpaceshipControl::collisions_spaceship(std::shared_ptr<Laser> laser){
    //if the spaceship is not active right now, the lasers should not be able to reach it
    if (!spaceship.alive) 
    return;
    
    //checks for collisions
    if (laser->get_rectangle().getGlobalBounds().findIntersection(spaceship.get_sprite().getGlobalBounds())){
        laser->active = false;  //deactivates laser
        spaceship.alive = false; //resets spaceships alive status and when spaceship is unalived it disappears
        collision = true;       //sets collision to true
    }
    
}