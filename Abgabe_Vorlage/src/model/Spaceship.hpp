#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include <SFML/Graphics.hpp>
#include "../view/Layer.hpp"
#include "../view/ILayer.hpp"

//Spaceship model class
class Spaceship {

    public:
        //constructor and initialize
        Spaceship();

        //boolean for checking if it is alive/ is to be seen 
        bool alive;

        //setting position of spaceship
        void set_position(float x, float y);

        //returns position
        sf::Vector2f get_position() const;

        //sprite for spaceship
        const sf:: Sprite&get_sprite() const;

        //draw method on layer
        void draw(ILayer &layer);

        //returns the speed
        float get_speed() const;

    private:
        sf::Vector2f position;  //spaceships position
        sf::Texture texture;    //spaceships texture
        sf::Sprite sprite;      //spaceships sprite

        //speed of spaceship
        float speed;
};

#endif