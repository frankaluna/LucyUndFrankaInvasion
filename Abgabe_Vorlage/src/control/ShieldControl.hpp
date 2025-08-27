#ifndef SHIELDCONTROL_H
#define SHIELDCONTROL_H

#include <SFML/Graphics.hpp>
#include "../model/Shield.hpp"
#include <SFML/Window.hpp>
#include "../model/Laser.hpp"
#include <vector>

class ShieldControl {
    public:
    
    ShieldControl(Layer &layer);

    void draw();

    std::vector<Shield> create_shields();

    void collisions_shield(std::shared_ptr<Laser> laser);

    private:

    Layer &layer;

    std::vector<Shield> shields;

};

#endif