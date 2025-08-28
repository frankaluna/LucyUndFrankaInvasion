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
    //constructor and initialize with the position of the shield
    Shield(sf::Vector2f position);

    //setting position with a x and y value
    void set_position(float x, float y);

    //gets the position as a vector
    sf::Vector2f get_position() ;

    //for the return of the sprite picture of the shield
    const sf:: Sprite &get_sprite() const;

    //draws shield on layer
    void draw(Layer &layer);

    private:
    //position of shield
    sf::Vector2f position;

    //texture for the shield
    sf:: Texture texture;

    //sprite for the shield
    sf:: Sprite sprite;

};
#endif