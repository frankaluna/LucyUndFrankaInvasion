#ifndef SHIELDS_HPP
#define SHIELDS_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Directions.hpp"
#include "../view/Layer.hpp"

//shield model class
class Shield{
    public:
    //constructor and initialize
    Shield(sf::Vector2f position);

    //position of shield
    void set_position(float x, float y);

    //shield's horizontal position
    sf::Vector2f get_position() ;

    //sprite for shield
    const sf:: Sprite &get_sprite() const;

    void draw(Layer &layer);

    private:
    sf::Vector2f position;
    sf:: Texture texture;
    sf:: Sprite sprite;

};
#endif