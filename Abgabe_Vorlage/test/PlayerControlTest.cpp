#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/control/PlayerControl.hpp"
#include "../src/model/Laser.hpp"

class PlayerControlTest :public ::testing::Test{

    public:
        PlayerControlTest() : 
        window(sf::VideoMode(800, 600), "Test Window"),       layer(window),
        pc(layer),
        laser(std::make_shared<Laser>(sf::Vector2f(300, -60), -2))
        {
        laser->active = true;
        }
    protected:
        Layer layer;
        PlayerControl pc;
        std::shared_ptr<Laser> laser;

};
//testing right_button_pressed() method
TEST_F(PlayerControlTest, right_button_pressed_test){
    pc.right_button_pressed();
    ASSERT_EQ(pc.get_player_movement(), HorizontalDirection::RIGHT);
}
//testing left_button_pressed() method
TEST_F(PlayerControlTest, left_button_pressed_test){
    pc.left_button_pressed();
    ASSERT_EQ(pc.get_player_movement(), HorizontalDirection::LEFT);
}

//testing direction_button_released() method
TEST_F(PlayerControlTest, direction_button_released_test){
    HorizontalDirection direction = HorizontalDirection::LEFT;
    pc.direction_button_released(direction);
    ASSERT_EQ(pc.get_player_movement(), HorizontalDirection::NONE);
}

//testing update_player() method
TEST_F(PlayerControlTest, update_player_test){

}

//testing draw_player() method
TEST_F(PlayerControlTest, draw_player_test){

}

//testing shoot_player() method
TEST_F(PlayerControlTest, shoot_player_test){

}

//testing collisions_player() method
TEST_F(PlayerControlTest, collisions_player_test){
    pc.get_player().set_position(300,-50);
    pc.set_lives(3);
    pc.collisions_player(laser);
    ASSERT_EQ(pc.get_player().get_lives(), 2);
    ASSERT_FALSE(laser->active);
}

TEST_F(PlayerControlTest, no_collisions_player_test){
    pc.get_player().set_position(300,300);
    pc.set_lives(3);
    pc.collisions_player(laser);
    ASSERT_EQ(p.get_player().get_lives(), 3);
    ASSERT_TRUE(laser->active);

}

//testing is_game_over() method
TEST_F(PlayerControlTest, is_game_over_test){
pc.set_lives(0);
ASSERT_TRUE(pc.is_game_over());
}

