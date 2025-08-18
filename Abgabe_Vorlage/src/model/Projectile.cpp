#include "Projectile.hpp"

//constructor if owner is player
Projectile::Projectile(Player* owner, float speed) : 
speed(this -> speed),
shooter(Shooter::PLAYER), 
radius(0.5), 
active(true)  {

    y_position = owner->get_position_y();
    x_position = owner->get_position_x();
};

//constructor if owner is alien

Projectile::Projectile(Alien* owner, float speed) : 

speed(this -> speed),
shooter(Shooter::ALIEN), 
radius(0.5), 
active(true)  {

    y_position = owner->get_position_y();
    x_position = owner->get_position_x();
};

//updates projectiles position
void Projectile::update(float deltaTime) {
    if (active == true) {
        if (shooter == Shooter::PLAYER) {
                y_position = y_position + (speed * deltaTime);
                if (y_position < 0) {
                    deactivate();
                }
        }

        if (shooter == Shooter::ALIEN) {
            //get_level muss noch in Alien implementiert werden
                y_position = y_position - (speed 
                //+ owner.get_level())   
                     * deltaTime);
                    if (y_position > 600) {
                        deactivate();
                    }
        }

    }
};

//irgendwie erkennt er RenderWindow nicht warum??
  void draw(sf::RenderWindow &window) {
        sprite.setPosition(x_position, y_position);
        window.draw(sprite);
    }

//deactivates projectile
void Projectile::deactivate() {
    active = false;
}

//gets projectiles x position
float Projectile::get_x_position() {
    return x_position;
}

//gets projectiles y position
float Projectile::get_y_position() {
    return y_position;
}

//gets projectiles speed
float Projectile::get_speed() {
    return speed;
}

float Projectile::get_radius() {
    return radius;
}

bool Projectile::isActive() {
    return active;
}
