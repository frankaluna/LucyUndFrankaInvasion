#ifndef OVERLAYCONTROL_H
#define OVERLAYCONTROL_H

#include <stddef.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../view/Layer.hpp"
#include "../view/ILayer.hpp"

//This class handles the overlay of the game: displaying the lives, score and game over screen

class OverlayControl{
    public: 

    //constructor
    OverlayControl(ILayer &layer);

    //updates the overlay
    void update(int score, int lives);

    //draws the overlay elements
    void draw();

    //handles game over screen
    void is_game_over(); 

    //shows players score
    void show_score(int score);

    //shows players lives
    void show_lives(int lives);

    sf::Sprite& get_score_sprite();

    sf::Sprite& get_game_over_sprite();

    sf::Text& get_score_counter();

    std::vector<sf::Sprite>& get_lives_sprites();

    bool get_show_game_over();

    void set_show_game_over(bool game_over);


    private:

    ILayer &layer; //layer in which overlay is drawn

    sf::Font font; //font for the score

    sf::Texture game_over; //texture for game over screen
    sf::Texture game_score;//texture for score
    sf::Texture game_lives;//texture for lives
 
    sf::Sprite game_over_sprite; //sprite for game over screen
    sf::Sprite score_sprite;     //sprite for score
    std::vector<sf::Sprite> lives_sprites;  //vector containing sprites for lives

    sf::Text score_counter; //text that shows current score

    bool show_game_over;    //true if the game is over

};

#endif