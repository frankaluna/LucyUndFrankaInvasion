#include "OverlayControl.hpp"

OverlayControl::OverlayControl(Layer &layer) :
layer(layer),
game_over(), 
sprite(game_over) {
    show_game_over = false;
}

void OverlayControl::draw() {
    // draw the text views to the layer

    if (show_game_over)
        layer.add_to_layer(sprite);
}

void OverlayControl::is_game_over() {

    if (!game_over.loadFromFile("assets/images/GAME_OVER.png"))
        throw std::runtime_error("game over asset not found");

    sprite.setTexture(game_over);
    sprite.setPosition({0,0});
    sprite.setTextureRect(sf::IntRect({0,0}, {600, 600}));

    show_game_over = true;
}