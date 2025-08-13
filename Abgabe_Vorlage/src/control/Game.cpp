#include "Game.hpp"

#include <SFML/Window/Keyboard.hpp>

#include "../model/Constants.hpp"

Game::Game() : window(sf::VideoMode({constants::VIEW_WIDTH, constants::VIEW_HEIGHT}), "Space Invaders"),
    view(sf::FloatRect(sf::Vector2f({0,-constants::VIEW_HEIGHT}), sf::Vector2f({constants::VIEW_WIDTH,constants::VIEW_HEIGHT}))),
    game_layer(window) {
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
        // TODO: Process other events
        // examples:
        //if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            //if (keyPressed->code == sf::Keyboard::Key::Right) { // right arrow key pressed
                // ...
        // if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
            // if (keyReleased->code == sf::Keyboard::Key::Right) { // right arrow released
                // ...
    }
    return false;
}

void Game::update(float time_passed) {
    // TODO: update the game objects with the current time stamp
}

void Game::draw() {
    window.clear();

    game_layer.clear();
    // TODO: add game elements to layer
    game_layer.draw();

    window.display();
}
