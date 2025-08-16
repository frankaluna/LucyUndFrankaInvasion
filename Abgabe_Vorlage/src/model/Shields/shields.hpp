#ifndef SHIELDS_HPP
#define SHIELDS_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Directions.hpp"

//shield model class
class Shield{
    public:
    //constructor and initialize
    Shield(int lives = 30);

    //position of shield
    void set_position(float x, float y);

    //shield's horizontal position
    float get_position_x() const;

    //shield's vertical position
    float get_position_y() const;

    //sprite for shield
    const sf:: Sprite&get_sprite() const;

    private:
    sf:: Texture texture;
    sf:: Sprite sprite;

    //sprite position
    float position_x;
    float position_y;
};
#endif