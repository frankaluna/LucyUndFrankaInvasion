#ifndef SHIELDCONTROL_H
#define SHIELDCONTROL_H

#include <SFML/Graphics.hpp>
#include "../model/Shield.hpp"
#include <SFML/Window.hpp>
#include "../model/Laser.hpp"
#include <vector>
//Controller class for the shields
class ShieldControl {
    public:
    //constructor and initializes with layer
    ShieldControl(Layer &layer);

    //draws shield to the game layer
    void draw();

    //creating a row of shields
    std::vector<std::shared_ptr<Shield>> create_shields();

    //checking for the collisions between shields and lasers
    void collisions_shield(std::shared_ptr<Laser> laser);


    private:

    //the layer we want to draw on
    Layer &layer;

    //the row as a vector of the shields
    std::vector<std::shared_ptr<Shield>> shields;

};

#endif