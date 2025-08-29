#include "Shield.hpp"
// Constructor that initializes the shield with given position
Shield:: Shield(sf::Vector2f position) : 
texture(),
sprite(texture), //initializing texture and sprite for later applications
resilience(5)
{
    this -> position = position; //initializing the positon

    //loading the texture and throwing an error if the sprite is unavailable
     if (!texture.loadFromFile(("assets/images/Shield.png")))
        throw std::invalid_argument("Spritesheet not found");
    // set up sprite
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect({0, 0}, {64, 64}));
    sprite.setOrigin({32, 32});
    sprite.setPosition(position);

}
//adds sprite of shield to layer
void Shield::draw(Layer &layer) {        
    layer.add_to_layer(sprite);
}

//get the shield's position as a vector
sf::Vector2f Shield:: get_position() {
    return position;
}
    
//set positions x and y and connects to sprite
void Shield:: set_position(float x, float y){
    position.x = x;
    position.y = y;
    sprite.setPosition({x, y});
}
    
//get the shield's sprite 
const sf:: Sprite& Shield:: get_sprite() const{
    return sprite;
}

int Shield::get_resilience(){
    return resilience;
}

void Shield::set_resilience(int new_reslience){
    if(new_reslience > 5){
        new_reslience = 5;
    }
    if(new_reslience < 0){
        new_reslience = 5;
    }
    resilience = new_reslience;
    
}