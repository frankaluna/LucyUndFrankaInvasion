#ifndef ALIENCONTROL_HPP
#define ALIENCONTROL_HPP

#include "../model/Alien.hpp"
#include <vector>
#include "../view/Layer.hpp"
#include <SFML/Graphics.hpp>


class AlienControl {
    public:

    AlienControl(Layer &layer);
    
    std::vector<Alien> create_aliens();

    void draw_alien();

    private:
    //Alien alien;
    Layer &layer;
    std::vector<Alien> aliens;

    


};

#endif