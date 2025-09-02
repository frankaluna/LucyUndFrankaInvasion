#ifndef SPACESHIPCONTROL_HPP
#define SPACESHIPCONTROL_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../model/Spaceship.hpp"
#include "../view/Layer.hpp"
#include "../model/Laser.hpp"
#include "PlayerControl.hpp"
#include "../view/ILayer.hpp"

class SpaceshipControl{
    public:

    //initialites Spaceship on layer
    SpaceshipControl(ILayer &layer);

    //updates Spaceship
    void update(float dt);

    //draws Spaceship to layer
    void draw_spaceship();
    
    //appear method
    void appear();
    
    //starts new time interval
    void start_interval();

    //checks for collision with spaceship
    void collisions_spaceship(std::shared_ptr<Laser> laser);

    //returns true if there is a collision
    bool collision;

    //returns last_seen of spaceship for testing
    float get_last_seen();

    //getter for the spaceship in private for testing
    Spaceship& get_spaceship();

    //getter for the spaceship in private for testing
    const Spaceship& get_spaceship() const;
    
    private:

    //spaceship
    Spaceship spaceship;

    //layer where spaceship is drawn
    ILayer &layer;

    //speed
    float speed;

    //float for the interval declaration
    float interval;

    //time for last appearance
    float last_seen;
    
    };

#endif 
