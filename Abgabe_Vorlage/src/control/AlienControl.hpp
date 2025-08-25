#ifndef ALIENCONTROL_HPP
#define ALIENCONTROL_HPP

#include "../model/Alien.hpp"
#include <vector>
#include "../view/Layer.hpp"
#include <SFML/Graphics.hpp>
#include "../model/Directions.hpp"


class AlienControl {
    public:

    AlienControl(Layer &layer);
    
    std::vector<std::shared_ptr<Alien>> create_aliens();

    void draw_alien();

   // void move_aliens();

    void update_aliens(float elapsed_time);


    private:
    //Alien alien;
    Layer &layer;
    std::vector<std::shared_ptr<Alien>> aliens;
    float speed;
};

#endif