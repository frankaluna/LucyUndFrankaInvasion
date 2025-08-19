#ifndef ALIENCONTROL_HPP
#define ALIENCONTROL_HPP

#include "./Directions.hpp"
#include <SFML/Graphics.hpp>
#include "../model/Player.hpp"
#include "../view/Layer.hpp"
#include "../model/Projectile.hpp"
#include <vector>

class AlienControl{
    public:

    //initializes Alien on a layer
    AlienControl (Layer &layer);

    //start shooting
    void start_shoot();

    //checks if alien can shoot 
    bool can_shoot(float elapsed_time);

    //update alien position
    void update_alien(float elapsed_time);

    //draw alien to layer
    void draw_alien();

    //get hight of aliens
    float get_alien_hight() const;

    //get length of alien
    float get_alien_length() const;

private:
    //alien
    Alien alien;

    //layer where alien is drawn
    Layer &layer;

    //shot timer start
    float current_shot_start_time = 0;

    //speed
    float speed = 100.f;

    //horizontal direction
    HorizontalDirection h_dir = HorizontalDirection::LEFT;

    //vertical direction
    VerticalDirection v_dir = VerticalDirection::NONE;

    //projectiles
    std::vector<Projectile> projectiles;
};
#endif