#ifndef ALIENCONTROL_HPP
#define ALIENCONTROL_HPP


#include <vector>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../view/Layer.hpp"
#include "../model/Laser.hpp"
#include "../model/Alien.hpp"
#include "../model/Directions.hpp"
#include "PlayerControl.hpp"

//class to control the Aliens

class AlienControl {
    public:

    //constructor
    AlienControl(Layer &layer);
    
    //creates the Block of Aliens
    std::vector<std::shared_ptr<Alien>> create_aliens();

    //draws every Alien in the aliens vector
    void draw_alien();

    //updates Aliens movement, level and lasers
    void update_aliens(float elapsed_time);

    //sets the outer aliens to the current alien, that is the left, right and lower boundary
    void set_outer_aliens();

    //takes care of the lasers, that the Aliens shoot
    void shoot_alien();

    //chooses a random alien to shoot
    std::shared_ptr<Alien> random_alien();

    //returns the vector, that contains all active lasers shot by aliens
    std::vector<std::shared_ptr<Laser>> get_alien_lasers();

    //checks if lasers are colliding with a laser
    void collisions_aliens(std::shared_ptr<Laser> laser);

    //returns scores
    int get_score();

    //sets new score for the Player
    void set_score(int newScore);

    //checks if aliens are at the Players level
    bool is_game_over;

    private:
    int score;
    int level;
    float speed;
    
    //vector of pointers to all aliens
    std::vector<std::shared_ptr<Alien>> aliens;

    //layer on which the aliens are drawn
    Layer &layer;
    
    //vector of pointers to all lasers shot by aliens
    std::vector<std::shared_ptr<Laser>> alien_lasers;

    
    std::shared_ptr<Alien> most_left;
    std::shared_ptr<Alien> most_right;
    std::shared_ptr<Alien> most_down;
    HorizontalDirection h_dir;

    sf::Time shot_start_time;
    sf::Clock clock;

   
};

#endif