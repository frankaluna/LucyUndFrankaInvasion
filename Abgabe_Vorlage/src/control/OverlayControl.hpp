#ifndef OVERLAYCONTROL_H
#define OVERLAYCONTROL_H

#include <stddef.h>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../view/Layer.hpp"

class OverlayControl{
    public: 

    OverlayControl(Layer &layer);

    //void update_score(int oldScore);

    void draw(int score);

    void is_game_over(); 

    void show_score(int score);

    private:

    Layer &layer;

    sf::Font font;

    sf::Texture game_over;
    sf::Texture game_going;
 
    sf::Sprite game_over_sprite;
    sf::Sprite score_sprite;

    sf::Text score_counter;

    bool show_game_over;

};

#endif