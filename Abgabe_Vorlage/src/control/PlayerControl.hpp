#ifndef PLAYERCONTROL_HPP
#define PLAYERCONTROL_HPP

#include <SFML/Graphics.hpp>
#include "../model/Player.hpp"
#include "../model/Directions.hpp"
#include "../view/Layer.hpp"
#include "AlienControl.hpp"
#include <vector>
#include "../model/Laser.hpp"
#include <SFML/System.hpp>


class PlayerControl {
    public:

    //initializes Player on a layer
    PlayerControl(Layer &layer);

    //move Player to the right
    void right_button_pressed();

    //move Player to the left
    void left_button_pressed();

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

    //handles players collisions with lasers
    void collisions_player(std::shared_ptr<Laser> laser);

    //shows if game is over, when the player has less then one life
    bool is_game_over();

    //returns players lives
    int get_lives();

    //sets the players lives
    void set_lives(int new_lives);

    private:
    //player
    Player player;

    //layer where player is drawn
    Layer &layer;

    //length where the current shot started
    sf::Time shot_start_time;  

    //players moving speed
    float speed = 200.f; 

    // horizontal direction
    HorizontalDirection h_dir = HorizontalDirection::NONE;

    //Vector for all the active lasers shot by the player
    std::vector<std::shared_ptr<Laser>> lasers; 

    sf::Clock clock;
};

#endif
