#include "Spaceship.hpp"


Spaceship::Spaceship() :
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

    alive = false;

}
//destructor for Spaceship
Spaceship::~Spaceship(){
    //sf::Texture nothing;
    //texture.swap(nothing);
}

//get position
sf::Vector2f Spaceship:: get_position() const{
    return position;
}
//set positions
void Spaceship:: set_position(float x, float y){
    position.x = x;
    position.y = y;
    sprite.setPosition({x,y});
}

//get sprite picture
const sf:: Sprite& Spaceship:: get_sprite() const{
    return sprite;
}

void Spaceship:: draw(Layer &layer){
    layer.add_to_layer(sprite);
}

//getter speed
float Spaceship:: get_speed() const{
    return speed;
}
