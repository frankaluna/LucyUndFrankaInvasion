#ifndef ALIENCONTROL_HPP
#define ALIENCONTROL_HPP

#include "../model/Alien.hpp"
#include <vector>
#include <random>
#include "../view/Layer.hpp"
#include <SFML/Graphics.hpp>
#include "../model/Directions.hpp"



class AlienControl {
    public:

    AlienControl(Layer &layer);
    
    std::vector<std::shared_ptr<Alien>> create_aliens();

    void draw_alien();

    void update_aliens(float elapsed_time);

    void set_outer_aliens();

    void shoot_alien();


    private:
    //Alien alien;
    Layer &layer;
    std::vector<std::shared_ptr<Alien>> aliens;
    std::vector<std::shared_ptr<Laser>> alien_lasers;

    float speed;
    std::shared_ptr<Alien> most_left;
    std::shared_ptr<Alien> most_right;
    std::shared_ptr<Alien> most_down;
    HorizontalDirection h_dir;
    //bool game_over;   //für wenn wir einen game over screen haben

};

#endif