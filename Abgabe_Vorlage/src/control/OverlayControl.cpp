#include "OverlayControl.hpp"


OverlayControl::OverlayControl(Layer &layer) :
font("assets/fonts/ARCADECLASSIC.TTF"),
layer(layer),
game_over(), 
game_over_sprite(game_over),
game_score(),
score_sprite(game_score),
game_lives(),
score_counter(font)
{
    show_game_over = false;     //intializes, that the game is not over  
    
    score_counter.setPosition({70 , 562});  // sets position of the score board at the lower left corner

    //loads background images (only needs to be loaded once)
    if (!game_lives.loadFromFile("assets/images/lives.png"))    
        throw std::runtime_error("game over asset not found"); 
}

//update elements of the overlay, while the game is running
void OverlayControl::update(int score, int lives){
    show_score(score);
    show_lives(lives);
}

//draws the elements of the overlay
void OverlayControl::draw() {
    // draw lives and score 
    for(auto lives_sprite : lives_sprites){
        layer.add_to_layer(lives_sprite);
    }
    layer.add_to_layer(score_sprite);
    layer.add_to_layer(score_counter);

    //draws game over screen, if the game is over
    if (show_game_over)
        layer.add_to_layer(game_over_sprite);
}

//handles case, that the game is over
void OverlayControl::is_game_over() {
    //loads game over screen
    if (!game_over.loadFromFile("assets/images/GAME_OVER.png"))
        throw std::runtime_error("game over asset not found");

    game_over_sprite.setTexture(game_over);
    game_over_sprite.setPosition({0,0});
    game_over_sprite.setTextureRect(sf::IntRect({0,0}, {600, 600}));
    
    show_game_over = true;
}

//handles showing players current score 
void OverlayControl::show_score(int score) {
    //loads "Score:" sprite
    if (!game_score.loadFromFile("assets/images/Score2.png"))
        throw std::runtime_error("game over asset not found");

    score_sprite.setTexture(game_score);
    score_sprite.setTextureRect(sf::IntRect({0,0}, {52 ,16}));
    score_sprite.setOrigin({0, 0});
    score_sprite.setPosition({10, 575});

    //writes the current score next to the score sprite
    score_counter.setString(std::to_string(score));

}

//handles showing players current lives
void OverlayControl::show_lives(int lives){
    lives_sprites.clear();
    int i;

    for (i = 0; i < lives; i++){

        sf::Sprite lives_sprite(game_lives);    //creates a new lives_sprite
        lives_sprite.setTextureRect(sf::IntRect({0,0}, {32, 32}));
        lives_sprite.setOrigin({0, 0});
        lives_sprite.setPosition({475 + i * 32, 565});  //adjusting position of the created sprite
        lives_sprites.push_back(lives_sprite);      //adding the lives_sprite to the lives_sprites vector
    }
}