#include "PlayerControl.hpp"

PlayerControl::PlayerControl(Layer &layer) : layer(layer) {

}

//moves Player to the right
void PlayerControl::right_button_pressed() {
    player.move_right();
} 

//moves Player to the left
void PlayerControl::left_button_pressed() {
    player.move_left();
}

//shoots if spacebar is pressed
void PlayerControl::spacebar_pressed() {
    player.shoot();
}


//stops Players movement
void PlayerControl::direction_button_released(HorizontalDirection direction) {
    if (direction == player.get_horizontal_movement())
        player.stop_horizontal_movement();
}

//
bool PlayerControl::can_shoot(float elapsed_time) {
    float elapsed_time
    return (elapsed_time > 0.5);
}
