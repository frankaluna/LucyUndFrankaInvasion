#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "./PlayerControl.hpp"
#include "./ShieldControl.hpp"
#include "./AlienControl.hpp"
#include "./SpaceshipControl.hpp"
#include "OverlayControl.hpp"
#include "../view/Layer.hpp"
#include "../model/Laser.hpp"

// Game control class
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

    //creating a window for our 2D drawing
    sf::RenderWindow window;

    // view area and layers
    sf::View view;
    Layer game_layer;       //layer for our game elements
    Layer background_layer; //the layer for our background
    Layer overlay_layer;    //layer for our lives, score and end game screen


    // resources to draw the background
    sf::Texture background;         
    sf::Sprite background_sprite;

    //initializing our control classes
    PlayerControl player_control;       //the player = alien at the bottom of the screen
    ShieldControl shield_control;       //shields protecting the player
    AlienControl alien_control;         //invadors
    SpaceshipControl spaceship_control; //spaceship at the top
    OverlayControl overlay_control;     //score, lives, end game

};

#endif