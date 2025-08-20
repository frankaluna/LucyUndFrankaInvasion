#include "PlayerControl.hpp"
#include <iostream>

PlayerControl::PlayerControl(Layer &layer) : layer(layer)
{
// startposition (x,y) anpassen nach Spielfeld!!

}

//moves Player to the right
void PlayerControl::right_button_pressed() {
    player.move_right();
} 


//moves Player to the left
void PlayerControl::left_button_pressed() {
    player.move_left();
}

// release button stop
void PlayerControl::direction_button_released(HorizontalDirection direction) {
    if (direction == player.get_horizontal_movement()){
        player.stop_horizontal_movement();
    }
}
/*
//set back shoot timer
void PlayerControl:: start_shoot(){
    current_shot_start_time = 0.f;
}
// checking if able to shoot again
bool PlayerControl:: can_shoot(float elapsed_time){
    const float cooldown = 0.5f; //half second between 2 shots
    return (elapsed_time - current_shot_start_time) >= cooldown;
}

//shoots if spacebar is pressed
void PlayerControl::spacebar_pressed() {
    float x = player.get_position_x();
    float y = player.get_position_y()-20.f;

    Projectile projectile(y, -300.f, Shooter:: Player, 5.f);
    projectile.set_position(x,y);
    projectiles.push_back(projectile);

    //reset timer
    start_shoot();
}
*/
void PlayerControl::update_player(float elapsed_time){
    sf::Vector2f position = player.get_position();

    float x = 0;

    if (player.get_position().x > 50 && player.get_horizontal_movement() == HorizontalDirection::LEFT) {
        x = -200;
    }
    
    if (player.get_position().x < 550 && player.get_horizontal_movement() == HorizontalDirection::RIGHT) {
        x = 200;
    }
    x = player.get_position().x + x * elapsed_time;
    //update position
    player.set_position(x , -50);
    /*
    //move projectile
    for (auto &projectile : projectiles){
        sf:: Vector2f projectile_pos = projectile.get_position();
        projectile_pos.y += projectile.get_speed()* elapsed_time;
        projectile.set_position(projectile_pos.x, projectile_pos.y);
    }
    
    //delete projectile if out of window
    projectiles.erase(std:: remove(projectiles.begin(), projectiles.end(), [](const Projectile &p){
        return p.get_position_y < 0
    }),
    projectiles.end());
*/  
}

void PlayerControl:: draw_player(){
    //layer.add_to_layer(player.get_sprite());
    player.draw(layer);
    //for (auto &projectile : projectiles) {
    //    projectile.draw(layer);
    //}
}

/*
float PlayerControl::get_player_length()const{
    return player.get_position().y;
}
*/
