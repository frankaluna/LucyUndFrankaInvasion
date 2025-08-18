#include "shields.hpp"

Shield:: Shield(int lives) :
    position_x(0), //ein x Wert ??????
    position_y(-150), //mehrere y-werte für verschiedene shields ???
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
    //get a pretty Sprite picture pleasegit 
    const sf:: Sprite& Shield:: get_sprite() const{
        return sprite;
    }