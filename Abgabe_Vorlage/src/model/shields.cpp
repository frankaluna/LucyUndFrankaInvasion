#include "shields.hpp"

Shield:: Shield() :
    position(1, 2), //Platzhalter Werte
    texture(),
    sprite(texture){
        //load texture
        //hier Bilder shields
        //set up sprite
        sprite.setTexture(texture);
        //sprite.setTextureRect(sf::intRect({0,0},{}));
        //sprite.setOrigin({}); 
        //sprite.setPosition({});
        //sprite sachen ergänzen!!!
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