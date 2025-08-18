#include "Projectile.hpp"

Projectile::Projectile(float startY, float speed, Shooter shooter, float radius) : y_position(startY), shooter(this -> shooter), radius(this -> radius), 