#ifndef SPACESHIPCONTROL_HPP
#define SPACESHIPCONTROL_HPP

#include <SFML/Graphics.hpp>
#include "../model/Spaceship.hpp"
#include "../view/Layer.hpp"

class SpaceshipControl{
    public:

    //initialites Spaceship on layer
    SpaceshipControl(Layer &layer);

    //updates Spaceship
    void update();

    //draws Spaceship to layer
    void draw_spaceship();
    
    //appear method
    void appear();
    
    private:

    //spaceship
    Spaceship spaceship;

    //layer where spaceship is drawn
    Layer &layer;

    //speed
    float speed;
    
    };

#endif 
/*

*/