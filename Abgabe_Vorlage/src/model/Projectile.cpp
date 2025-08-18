#include "Projectile.hpp"

//constructor if owner is player
Projectile::Projectile(Player* owner, float speed, float radius) : 
speed(this -> speed),
shooter(Shooter::PLAYER), 
radius(this -> radius), 
active(true)  {

    y_position = owner->get_position_y();
    x_position = owner->get_position_x();

   
};

//constructor if owner is alien

Projectile::Projectile(Alien* owner, float speed, float radius) : 

speed(this -> speed),
shooter(Shooter::ALIEN), 
radius(this -> radius), 
active(true)  {

    y_position = owner->get_position_y();
    x_position = owner->get_position_x();

   
};

