#include "Projectile.hpp"
#include

Projectile::Projectile(float startY, float speed, Shooter shooter, float radius) : y_position(startY), shooter(this -> shooter), radius(this -> radius), 