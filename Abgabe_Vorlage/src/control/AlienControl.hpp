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



class AlienControl {
    public:

    AlienControl(Layer &layer);
    
    std::vector<std::shared_ptr<Alien>> create_aliens();

    void draw_alien();

    void update_aliens(float elapsed_time);

    void set_outer_aliens();

    void shoot_alien();

    std::shared_ptr<Alien> random_alien();

    std::vector<std::shared_ptr<Laser>> get_alien_lasers();


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

    sf::Time shot_start_time;
    sf::Clock clock;

};

#endif