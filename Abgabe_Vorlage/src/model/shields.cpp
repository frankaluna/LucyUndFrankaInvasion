#include "shields.hpp"

Shield:: Shield(int lives) :
    position({x,y});
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
    //get position x
    float Shield:: get_position_x() const{
        return position_x;
    }
    //get position y
    float Shield:: get_position_y() const{
        return position_y;
    }
    //set positions x and y
    void Shield:: set_position(float x, float y){
        position_x = x;
        position_y = y;
    }
    //get a pretty Sprite picture please 
    const sf:: Sprite& Shield:: get_sprite() const{
        return sprite;
    }