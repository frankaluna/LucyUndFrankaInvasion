#include "OverlayControl.hpp"

OverlayControl::OverlayControl(Layer &layer) :
font("assets/fonts/ARCADECLASSIC.TTF"),
layer(layer),
game_over(), 
game_over_sprite(game_over),
game_score(),
score_sprite(game_score),
game_lives(),
//lives_sprite(game_lives),
score_counter(font)
{
    show_game_over = false;
    
    score_counter.setPosition({70 , 562});

    if (!game_lives.loadFromFile("assets/images/lives.png"))
        throw std::runtime_error("game over asset not found"); 
     
     
}

void OverlayControl::update(int score, int lives){
    show_score(score);
    show_lives(lives);
}

void OverlayControl::draw() {
    // draw the text views to the layer
    for(auto lives_sprite : lives_sprites){
        layer.add_to_layer(lives_sprite);
    }
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

    if (!game_score.loadFromFile("assets/images/Score2.png"))
        throw std::runtime_error("game over asset not found");

    score_sprite.setTexture(game_score);
    score_sprite.setTextureRect(sf::IntRect({0,0}, {52 ,16}));
    score_sprite.setOrigin({0, 0});
    score_sprite.setPosition({10, 575});

    
    score_counter.setString(std::to_string(score));

}


void OverlayControl::show_lives(int lives){
    lives_sprites.clear();
    int i;

    for (i = 0; i < lives; i++){
        sf::Sprite lives_sprite(game_lives);
        //lives_sprite.setTexture(game_lives);
        lives_sprite.setTextureRect(sf::IntRect({0,0}, {32, 32}));
        lives_sprite.setOrigin({0, 0});
        lives_sprite.setPosition({400 + i * 32, 562});
        lives_sprites.push_back(lives_sprite);
    
    }


}