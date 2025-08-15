#ifndef PLAYERCONTROL_H
#define PLAYERCONTROL_H

#include <SFML/Graphics.hpp>
#include "../model/Player.hpp"
#include "../model/Directions.hpp"
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

    //checks if character can shoot again
    bool can_shoot(float elapsed_time);

    //updates Players position
    void update();


private:

    Player player;
    //hier vllt auch Layer ergänzen?

    

};

#endif