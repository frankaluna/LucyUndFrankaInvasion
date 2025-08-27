#include "OverlayControl.hpp"

OverlayControl::OverlayControl(Layer &layer) :
font("assets/fonts/ARCADECLASSIC.TTF"),
layer(layer),
game_over(), 
game_over_sprite(game_over),
game_going(),
score_sprite(game_going),
score_counter(font)
{
    show_game_over = false;
    
    score_counter.setPosition({70 , 562});  
}

void OverlayControl::draw(int score) {
    // draw the text views to the layer
    show_score(score);
    layer.add_to_layer(score_sprite);
    layer.add_to_layer(score_counter);
    if (show_game_over)
        layer.add_to_layer(game_over_sprite);
}

void OverlayControl::is_game_over() {

    if (!game_over.loadFromFile("assets/images/GAME_OVER.png"))
        throw std::runtime_error("game over asset not found");

    game_over_sprite.setTexture(game_over);
    game_over_sprite.setPosition({0,0});
    game_over_sprite.setTextureRect(sf::IntRect({0,0}, {600, 600}));

    show_game_over = true;
}

void OverlayControl::show_score(int score) {

    if (!game_going.loadFromFile("assets/images/Score2.png"))
        throw std::runtime_error("game over asset not found");

    score_sprite.setTexture(game_going);
    score_sprite.setTextureRect(sf::IntRect({0,0}, {52 ,16}));
    score_sprite.setOrigin({0, 0});
    score_sprite.setPosition({10, 575});

    
    score_counter.setString(std::to_string(score));

}




