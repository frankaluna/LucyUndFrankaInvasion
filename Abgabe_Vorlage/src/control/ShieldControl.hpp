#ifndef SHIELDCONTROL_H
#define SHIELDCONTROL_H

#include <SFML/Graphics.hpp>
#include "../model/Shield.hpp"
#include <SFML/Window.hpp>

class ShieldControl {
    public:
    ShieldControl(Layer &layer);

    void draw();

    private:

    Layer &layer;
};

#endif