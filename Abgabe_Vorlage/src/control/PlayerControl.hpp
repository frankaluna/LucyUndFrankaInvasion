#ifndef PLAYERCONTROL_HPP
#define PLAYERCONTROL_HPP

#include <SFML/Graphics.hpp>
#include "../model/Player.hpp"
#include "./Directions.hpp"
#include "../view/Layer.hpp"


class PlayerControl {
    public:

    //initializes Player on a layer
    PlayerControl(Layer &layer);

    //move Player to the right
    void right_button_pressed();

    //move Player to the left
    void left_button_pressed();

    //shoots projectile
    void spacebar_pressed();

    //stop horizontal movement
    void direction_button_released(HorizontalDirection direction);

    //lets the character start shooting (reset shoot timer)
    void start_shoot();

    //checks if character can shoot again
    bool can_shoot(float elapsed_time);

    //updates Players position
    void update(float elapsed_time);

    //draw character to layer
    void draw_player();

    //get vertical position of the character
    float get_player_pos() const;


private:
    //player
    Player player;

    //layer where player is drawn
    Layer &layer;



    

};

#endif