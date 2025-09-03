#include "Spaceship.hpp"


Spaceship::Spaceship() :
    //initializing the position of the spaceship at the top of the screen with texture and sprite
    position({300, -550}), 
    texture(),
    sprite(texture)
{
    if (!texture.loadFromFile("assets/images/Spaceship.png")) 
        throw std::invalid_argument("Spritesheet not found");
    //set up sprite
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect({0, 0}, {32, 32}));
    sprite.setOrigin({16, 16}); // middle point
    sprite.setPosition(position);
    
    //not seen at first
    alive = false;

}

//returns the position of the spaceship
sf::Vector2f Spaceship:: get_position() const{
    return position;
}

//sets spaceships position and adjusts sprite accordingly
void Spaceship:: set_position(float x, float y){
    position.x = x;
    position.y = y;
    sprite.setPosition({x,y});
}

//returns the sprite of the spaceship
const sf:: Sprite& Spaceship:: get_sprite() const{
    return sprite;
}

//draws spaceship on given layer
void Spaceship:: draw(ILayer &layer){
    layer.add_to_layer(sprite);
}

//returns the speed of the spaceship
float Spaceship:: get_speed() const{
    return speed;
}
