#ifndef OVERLAYCONTROL_H
#define OVERLAYCONTROL_H

#include <stddef.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../view/Layer.hpp"

class OverlayControl{
    public: 

    OverlayControl(Layer &layer);

    void update(int score, int lives);

    void draw();

    void is_game_over(); 

    void show_score(int score);

    void show_lives(int lives);

    private:

    Layer &layer;

    sf::Font font;

    sf::Texture game_over;
    sf::Texture game_score;
    sf::Texture game_lives;
 
    sf::Sprite game_over_sprite;
    sf::Sprite score_sprite;
    std::vector<sf::Sprite> lives_sprites;

    sf::Text score_counter;

    bool show_game_over;

};

#endif