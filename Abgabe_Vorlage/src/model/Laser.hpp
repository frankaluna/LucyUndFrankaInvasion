#ifndef LASER_HPP
#define LASER_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Directions.hpp"
#include "../view/Layer.hpp"


class Laser{
    public:
        Laser(sf::Vector2f position, int speed);

        void update(float dt);

        void draw(Layer &layer);

        bool active;


    private:
    sf::Vector2f position;
    int speed;
};
#endif