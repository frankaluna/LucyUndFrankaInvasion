#include "PlayerControl.hpp"
#include <iostream>

PlayerControl::PlayerControl(Layer &layer) : layer(layer)
{
// startposition (x,y) anpassen nach Spielfeld!!
    shot_start_time = sf::seconds(0.0f);
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

    for (auto& laser: this->get_lasers()){
        laser->update(elapsed_time);
    }

    lasers.erase(
        std::remove_if(
            lasers.begin(),
            lasers.end(),
            [&](const std::shared_ptr<Laser>& laser) {
                return !laser->active; // oder laser->get_position().y < 0
            }
        ),
        lasers.end()
    );
    //testing if lasers really are deleted
    //std::cout << "Vector size: " << lasers.size() << std::endl;
}


void PlayerControl:: draw_player(){
    //layer.add_to_layer(player.get_sprite());
    player.draw(layer);
    
}
const std::vector<std::shared_ptr<Laser>>& PlayerControl::get_lasers() const {
    return lasers;
}
 void PlayerControl:: shoot_player(){
    if (clock.getElapsedTime() - shot_start_time >= sf::seconds(0.35f)) {
        lasers.push_back(std::make_shared<Laser>(
        sf::Vector2f(player.get_position().x, player.get_position().y), -150));
        shot_start_time = clock.getElapsedTime();
    }
 }

void PlayerControl::collisions_player(std::shared_ptr<Laser> laser) {
    
    auto intersection = player.get_sprite().getGlobalBounds().findIntersection(laser->get_rectangle().getGlobalBounds());
    if(intersection.has_value() && intersection->position.y > player.get_position().y - 16 && laser->get_speed() > 0) {
        std::cout << "ich werde getroffen" << player.get_lives() << std::endl;
        player.set_lives(player.get_lives() - 1);
        laser->active = false;
    }
    
}

bool PlayerControl::is_game_over(){
    return player.get_lives() <= 0;
}
