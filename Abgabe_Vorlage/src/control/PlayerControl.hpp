#ifndef PLAYERCONTROL_HPP
#define PLAYERCONTROL_HPP

#include <SFML/Graphics.hpp>
#include "../model/Player.hpp"
#include "../model/Directions.hpp"
#include "../view/Layer.hpp"
#include <vector>
#include "../model/Laser.hpp"

class PlayerControl {
    public:

    //initializes Player on a layer
    PlayerControl(Layer &layer);

    //move Player to the right
    void right_button_pressed();

    //move Player to the left
    void left_button_pressed();

    //shoots projectile
   // void spacebar_pressed();

    //stop horizontal movement
    void direction_button_released(HorizontalDirection direction);

    //updates Players position
    void update_player(float elapsed_time);

    //draw character to layer
    void draw_player();

    //shoot for player control
    void shoot_player();

    //getter for laser dynamic array for when we want to work on collusion
    const std::vector<std::shared_ptr<Laser>>& get_lasers() const;


private:
    //player
    Player player;

    //layer where player is drawn
    Layer &layer;

    //length where the current shot started
    float current_shot_start_time = 0;  

    // speed
    float speed = 200.f; 

    // horizontal direction
    HorizontalDirection h_dir = HorizontalDirection::NONE;

    //Vector for all the active lasers
    std::vector<std::shared_ptr<Laser>> lasers; 

};

#endif
