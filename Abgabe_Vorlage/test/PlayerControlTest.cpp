#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/control/PlayerControl.hpp"
#include "../src/model/Laser.hpp"

class PlayerControlTest :public ::testing::Test{

    public:
        PlayerControlTest() : p(),
                              l({600,600}),
                              laser(std::make_shared<Laser>(sf::Vector2f(300, -60), -2)){
        laser->active = true;
        }
    protected:
        PlayerControl p;
        Layer l;
        std::shared_ptr<Laser> laser;

        
};
//testing right_button_pressed() method
TEST_F(PlayerControlTest, right_button_pressed_test){
    p.right_button_pressed();
    ASSERT_EQ(p.get_player_movement(), HorizontalDirection::RIGHT);
}
//testing left_button_pressed() method
TEST_F(PlayerControlTest, left_button_pressed_test){
    p.left_button_pressed();
    ASSERT_EQ(p.get_player_movement(), HorizontalDirection::LEFT);
}

//testing direction_button_released() method
TEST_F(PlayerControlTest, direction_button_released_test){
    HorizontalDirection direction = HorizontalDirection::LEFT;
    p.direction_button_released(direction);
    ASSERT_EQ(p.get_player_movement(), HorizontalDirection::NONE);
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
    p.get_player().set_position({300,-50});
    p.set_lives(3);
    p.collisions_player(laser);
    ASSERT_EQ(p.get_player().get_lives(), 2);
    ASSERT_FALSE(laser->active);
}

TEST_F(PlayerControlTest, no_collisions_player_test){
    p.get_player().set_position({300,300});
    p.set_lives(3);
    p.collisions_player(laser);
    ASSERT_EQ(p.get_player().get_lives(), 3);
    ASSERT_TRUE(laser->active);

}

//testing is_game_over() method
TEST_F(PlayerControlTest, is_game_over_test){
p.set_lives(0);
ASSERT_TRUE(p.is_game_over());
}

