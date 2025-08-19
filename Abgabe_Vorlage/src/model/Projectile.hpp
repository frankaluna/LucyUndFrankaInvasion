#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Player.hpp"
#include "Alien.hpp"
#include "Shooter.hpp"


//model class for a projectile
class Projectile {
    public:
        //constructor, initializes the projectile if projectile is shot by Player
        Projectile(Player* owner, float speed);

        //constructor, initializes the projectile if it shot by an Alien
        Projectile(Alien* owner, float speed);

        //updates Projectiles Movement
        void update(float deltaTime);

        void draw(sf::RenderWindow &window);

        //deactivates Projectile
        void deactivate();

        //get current x position
        float get_x_position();

        //get current y position
        float get_y_position();

        //get current speed 
        float get_speed();

        //get radius
        float get_radius();

        //returns if projectile is active
        bool isActive();


    private:

        float x_position;
        float y_position;
        float speed;
        float radius;
        Shooter shooter;
        bool active;
        sf::Sprite sprite;
};

#endif