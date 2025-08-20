#ifndef ALIENCONTROL_HPP
#define ALIENCONTROL_HPP

#include "./Directions.hpp"
#include <SFML/Graphics.hpp>
#include "../model/Alien.hpp"
#include "../view/Layer.hpp"
#include "../model/Projectile.hpp"
#include <vector>

class AlienControl{
    public:

    //initializes Alien on a layer
    AlienControl (Layer &layer);

    //add an alien
    void add_alien(float x, float y, float speed);

    //alien shooter
    void alien_shoot();

    //update alien position
    void update_alien(float elapsed_time);

    //draw alien to layer
    void draw_alien();

    //get aliens
    const std::vector<Alien>& get_aliens() const;

private:
        //layer where alien is drawn
    Layer &layer;

    //alien
    std::vector<Alien> aliens;

    //shot timer start
    float current_shot_start_time = 0;

    //speed
    float speed = 100.f;

    //horizontal direction
    HorizontalDirection h_dir = HorizontalDirection::LEFT;

    //vertical direction
    VerticalDirection v_dir = VerticalDirection::NONE;

    //2 seconds between shots at the start
    float shoot_dif = 2.0f

    //timer
    float shoot_timer = 0.0f;

    //projectiles
    std::vector<Projectile> projectiles;
};
#endif