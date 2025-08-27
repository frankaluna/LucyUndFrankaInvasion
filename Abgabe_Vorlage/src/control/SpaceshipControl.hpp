#ifndef SPACESHIPCONTROL_HPP
#define SPACESHIPCONTROL_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../model/Spaceship.hpp"
#include "../view/Layer.hpp"
#include "../model/Laser.hpp"
#include "PlayerControl.hpp"

class SpaceshipControl{
    public:

    //initialites Spaceship on layer
    SpaceshipControl(Layer &layer);

    //updates Spaceship
    void update(float dt);

    //draws Spaceship to layer
    void draw();
    
    //appear method
    void appear();
    
    void start_interval();

    void collisions_spaceship(std::shared_ptr<Laser> laser);

    private:

    //spaceship
    Spaceship spaceship;

    //layer where spaceship is drawn
    Layer &layer;

    //speed
    float speed;

    //float for the interval declaration
    float interval;

    //time for last appearance
    float last_seen;

    };

#endif 
/*

*/