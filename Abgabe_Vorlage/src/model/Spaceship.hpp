#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include <SFML/Graphics.hpp>
#include "../view/Layer.hpp"

//Spaceship model class
class Spaceship {

    public:
        //constructor and initialize
        Spaceship();

        //boolean for checking if it is alive
        bool alive;

        //position of spaceship
        void set_position(float x, float y);

        //getter position
        sf::Vector2f get_position() const;

        //sprite for spaceship
        const sf:: Sprite&get_sprite() const;

        //draw method
        void draw(Layer &layer);

        //getter speed
        float get_speed() const;

    private:
        sf::Vector2f position;  //spaceships position
        sf::Texture texture;    //spaceships texture
        sf::Sprite sprite;      //spaceships sprite

        //speed of spaceship
        float speed;
};

#endif