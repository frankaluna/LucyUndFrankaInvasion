#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
#include "./Shooter.hpp"



//model class for a projectile
class Projectile {
    public:
        //constructor, initializes the projectile
        Projectile(float startY, float speed, Shooter shooter, float radius);

        //updates Projectiles Movement
        void update(float deltaTime) {};

        //deactivates Projectile
        void deactivate() {};

        //get current x position
        float get_x_position() {};

        //get current y position
        float get_y_position() {};

        //get current speed 
        float get_speed() {};

        //get radius
        float get_radius() {};


    private:

        float x_position;
        float y_position;
        float speed;
        float radius;
        Shooter shooter;
        bool active;

};

#endif