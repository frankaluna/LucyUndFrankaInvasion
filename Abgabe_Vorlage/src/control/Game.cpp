#include "Game.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include "../model/Constants.hpp"
//Constructor that inirializes the game with its settings
Game::Game() : window(sf::VideoMode({constants::VIEW_WIDTH, constants::VIEW_HEIGHT}), "Space Invaders"),
    view(sf::FloatRect(sf::Vector2f({0,-constants::VIEW_HEIGHT}), sf::Vector2f({constants::VIEW_WIDTH,constants::VIEW_HEIGHT}))),
    //layers
    game_layer(window),             
    background_layer(window),       
    overlay_layer(window),

    background(),                   //Texture
    background_sprite(background),  //Background Sprite 

    //control classes
    player_control(game_layer),
    shield_control(game_layer),
    alien_control(game_layer),
    spaceship_control(game_layer),
    overlay_control(overlay_layer)
    {

    // load background file and configure sprite
    if (!background.loadFromFile("assets/images/hintergrund.png"))
        throw std::runtime_error("background asset not found");

    background_sprite.setTexture(background);
    background_sprite.setPosition({0,0});
    background_sprite.setTextureRect(sf::IntRect({0,0}, {600, 600}));

     // draw on the render target (needs to be done only once) 
    background_layer.clear();
    background_layer.add_to_layer(background_sprite); // adds background to layer

    // limit frame rate
    window.setFramerateLimit(constants::FRAME_RATE);

    // set the view (visible area) for our game
    game_layer.set_view(view);
}

void Game::start() {
    // The clock is needed to control the speed of movement
    sf::Clock clock;

    while (window.isOpen()) {
        // Restart the clock and save the elapsed time into elapsed_time
        sf::Time elapsed_time = clock.restart();
 
        // handle input, check if window is still open
        if (!input()) {
            // update the scene according to the passed time
            update(elapsed_time.asSeconds());
            // draw the scene
            draw();
        }
    }
}

// returns true, if the window has been closed
bool Game::input() {
    while (std::optional<sf::Event> event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            // quit
            window.close();
            return true;
        }

        // pressed key actions
        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            switch (keyPressed->code) {
                //moves right if right key is pressed
                case sf::Keyboard::Key::Right:
                    player_control.right_button_pressed();
                    break;
                //moves left if left key is pressed
                case sf::Keyboard::Key::Left:
                    player_control.left_button_pressed();
                    break;
                //shoots if spacebar is pressed
                case sf::Keyboard::Key::Space:
                    player_control.shoot_player();
                    break;

                default:
                    break;
            }
        }

        // actions for releasing key
        if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
            switch (keyReleased->code) {
                case sf::Keyboard::Key::Right:
                    player_control.direction_button_released(HorizontalDirection::RIGHT);
                    break;
                case sf::Keyboard::Key::Left:
                    player_control.direction_button_released(HorizontalDirection::LEFT);
                    break;

                default:
                    break;
            }
        }
    }
    return false;
}
//updating game with elements
void Game::update(float time_passed) {
    //when lost switch to game over
    if(player_control.is_game_over() || alien_control.is_game_over == true) {
        game_layer.clear();
        overlay_control.is_game_over();
    }
    //updating player
    player_control.update_player(time_passed);

    //collsions with the lasers of player
    for (auto& laser: player_control.get_lasers()){
        laser->update(time_passed);
        alien_control.collisions_aliens(laser);
        spaceship_control.collisions_spaceship(laser);
        shield_control.collisions_shield(laser);
    }

    //updates aliens and their shooting
    alien_control.update_aliens(time_passed);
    alien_control.shoot_alien();
    
    //collisions with lasers of alien
    for (auto& laser: alien_control.get_alien_lasers()){
        laser->update(time_passed);
        player_control.collisions_player(laser);
        shield_control.collisions_shield(laser);   
    }
    //updating spaceship
    spaceship_control.update(time_passed);
    
    //if the spaceship gets hit add life to player
    if (spaceship_control.collision){
        int new_lives = player_control.get_lives() + 1;
        player_control.set_lives(new_lives);
        std::cout << "ein neues Leben!!!!" << player_control.get_lives() << std::endl;
        spaceship_control.collision = false;
    }    

    //update overlay screen
    overlay_control.update(alien_control.get_score(), player_control.get_lives());
}
//add game elements to layer
void Game::draw() {
    window.clear();
    game_layer.clear();
    player_control.draw_player();        // adds player
    shield_control.draw();               // adds shields
    alien_control.draw_alien();          // adds aliens
    spaceship_control.draw_spaceship();  // adds spadeship
   
    //add lasers for player
     for (auto& laser: player_control.get_lasers()){
        laser->draw(game_layer);
    }
    //add lasers for alien
    for (auto& laser: alien_control.get_alien_lasers()){
        laser->draw(game_layer);
    }
    //set up overlay layer
    overlay_layer.clear();
    overlay_control.draw();

    //draw all layers
    background_layer.draw();
    game_layer.draw();
    overlay_layer.draw();

    //display all
    window.display();
}
