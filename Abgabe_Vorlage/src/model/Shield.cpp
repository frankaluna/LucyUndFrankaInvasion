#include "Shield.hpp"

Shield:: Shield(sf::Vector2f position) : 
texture(),
sprite(texture)
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

    //get position 
    sf::Vector2f Shield:: get_position() const{
        return position;
    }
    
    //set positions x and y
    void Shield:: set_position(float x, float y){
        position.x = x;
        position.y = y;
    }
    
    //get a pretty Sprite picture please 
    const sf:: Sprite& Shield:: get_sprite() const{
        return sprite;
    }

    void Shield::draw(Layer &layer) {

            layer.add_to_layer(sprite);
    }