#ifndef OVERLAYCONTROL_H
#define OVERLAYCONTROL_H

#include <stddef.h>
#include <SFML/Graphics.hpp>
#include "../view/Layer.hpp"

class OverlayControl{
    public: 

    OverlayControl(Layer &layer);

    //void update_score(int oldScore);

    //void update_lives();

    void draw();

    void is_game_over();

    private:

    //sf::Font font;

    //size_t score;

    Layer &layer;

    sf::Texture game_over;
    sf::Sprite sprite;

    bool show_game_over;

};

#endif