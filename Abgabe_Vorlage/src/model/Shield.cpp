#include "Shield.hpp"

Shield:: Shield(sf::Vector2f position) : 
texture(),
sprite(texture),
resilience(33)
{
    this -> position = position; 

     if (!texture.loadFromFile(("assets/images/Shield.png")))
        throw std::invalid_argument("Spritesheet not found");
    // set up sprite
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect({0, 0}, {64, 64}));
    sprite.setOrigin({32, 32});
    sprite.setPosition(position);

}
void Shield::draw(Layer &layer) {        
    layer.add_to_layer(sprite);
}

//get position 
sf::Vector2f Shield:: get_position() {
    return position;
}
    
//set positions x and y
void Shield:: set_position(float x, float y){
    position.x = x;
    position.y = y;
    sprite.setPosition({x, y});
}
//get a pretty Sprite picture please 
const sf:: Sprite& Shield:: get_sprite() const{
    return sprite;
}

int Shield::get_resilience(){
    return resilience;
}

void Shield::set_resilience(int new_reslience){
    if(new_reslience > 33){
        new_reslience = 33;
    }
    if(new_reslience < 0){
        new_reslience = 0;
    }
    resilience = new_reslience;
    
}