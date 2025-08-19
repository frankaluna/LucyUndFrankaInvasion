#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "./PlayerControl.hpp"
#include "../view/Layer.hpp"

// Game class
class Game {

public:
    //initialize the game (window and controls)
    Game();

    // start the game
    void start();

private:
    // processes user input, returns true if window has been closed
    bool input();

    // updates all game elements
    void update(float time_passed);

    // draws the scene
    void draw();

    sf::RenderWindow window;

    // view area and layers
    sf::View view;
    Layer game_layer;
    Layer background_layer;


    // resources to draw the background
    sf::Texture background;
    sf::Sprite background_sprite;

    PlayerControl player_control;
};

#endif