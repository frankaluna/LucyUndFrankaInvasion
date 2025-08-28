#include "PlayerControl.hpp"
#include <iostream>

PlayerControl::PlayerControl(Layer &layer) : layer(layer)
{
    shot_start_time = sf::seconds(0.0f); //initializes shot time
}

//moves Player to the right
void PlayerControl::right_button_pressed() {
    player.move_right();
} 

//moves Player to the left
void PlayerControl::left_button_pressed() {
    player.move_left();
}

//stops horizontal movement when a direction button is released
void PlayerControl::direction_button_released(HorizontalDirection direction) {
    if (direction == player.get_horizontal_movement()){
        player.stop_horizontal_movement();
    }
}

//updates players movement, position and lasers
void PlayerControl::update_player(float elapsed_time){
    sf::Vector2f position = player.get_position();
    
    float x = 0;
    //handles players movement
    if (player.get_position().x > 50 && player.get_horizontal_movement() == HorizontalDirection::LEFT) {
        x = -200;
    }

    if (player.get_position().x < 550 && player.get_horizontal_movement() == HorizontalDirection::RIGHT) {
        x = 200;
    }
    x = player.get_position().x + x * elapsed_time;
    
    //update position
    player.set_position(x , -50);

    //updates lasers shot by player
    for (auto& laser: this->get_lasers()){
        laser->update(elapsed_time);
    }

    //erases inactive lasers 
    lasers.erase(
        std::remove_if(
            lasers.begin(),
            lasers.end(),
            [&](const std::shared_ptr<Laser>& laser) {
                return !laser->active;
            }
        ),
        lasers.end()
    );
}

//draws player
void PlayerControl::draw_player(){
    player.draw(layer);   
}

//returns vector with all active player lasers
const std::vector<std::shared_ptr<Laser>>& PlayerControl::get_lasers() const {
    return lasers;
}

//handles players shots
void PlayerControl:: shoot_player(){
    //checks if last shot is has been fired more than 0.35s ago 
    if (clock.getElapsedTime() - shot_start_time >= sf::seconds(0.35f)) {
        lasers.push_back(std::make_shared<Laser>(                               //creates new laser and adds it to the lasers vector
        sf::Vector2f(player.get_position().x, player.get_position().y), -150)); //sets lasers start position to the players current position
        shot_start_time = clock.getElapsedTime();                               //resets time since last shot
    }
}

//handles collisions with the player
void PlayerControl::collisions_player(std::shared_ptr<Laser> laser) {
    //checks for collisions
    auto intersection = player.get_sprite().getGlobalBounds().findIntersection(laser->get_rectangle().getGlobalBounds());
    if(intersection.has_value() && intersection->position.y > player.get_position().y - 16 && laser->get_speed() > 0) {
        player.set_lives(player.get_lives() - 1);   //decreases players lives by one
        laser->active = false;     //deactivates laser
    }
}

//returns true, if the player has less than one life
bool PlayerControl::is_game_over(){
    return player.get_lives() <= 0;
}

//returns players current lives
int PlayerControl::get_lives(){
    return player.get_lives();
}

//sets players lives
void PlayerControl::set_lives(int new_lives){
    player.set_lives(new_lives);
}

