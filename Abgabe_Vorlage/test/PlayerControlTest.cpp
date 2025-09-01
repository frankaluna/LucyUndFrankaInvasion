#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/control/PlayerControl.hpp"
#include "../src/model/Laser.hpp"
#include "../src/model/Player.hpp"
#include "Mocklayer.hpp"

class PlayerControlTest :public ::testing::Test{

    public:
        PlayerControlTest() : 
        pc(layer),
        laser(std::make_shared<Laser>(sf::Vector2f(300, -60), -2)),
        la(std::make_shared<Laser>(sf::Vector2f(200, -100), -2))

        {
        laser->active = true;
        la->active = false;
        }
    protected:
        Mocklayer layer;
        PlayerControl pc;
        std::shared_ptr<Laser> laser;
        std::shared_ptr<Laser> la;

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
TEST_F(PlayerControlTest, left_update_player_test){
    pc.get_player().set_position(300,-300);
    pc.get_player().move_left();

    pc.update_player(1.f);

    //should move left
    ASSERT_LT(pc.get_player().get_position().x, 300); 
    //should stay the same in y position
    ASSERT_EQ(pc.get_player().get_position().y, -300); 
}
TEST_F(PlayerControlTest, right_update_player_test){
    pc.get_player().set_position(300,-300);
    pc.get_player().move_right();

    pc.update_player(1.f);

    //should move right
    ASSERT_GT(pc.get_player().get_position().x, 300); 
    //should stay the same in y position
    ASSERT_EQ(pc.get_player().get_position().y, -300); 
}
TEST_F(PlayerControlTest, 550_update_player_test){
    pc.get_player().set_position(550,-300);
    pc.get_player().move_right();

    pc.update_player(1.f);

    //should move right but no further than x = 550
    ASSERT_LE(pc.get_player().get_position().x, 550);  
    //should stay the same in y position
    ASSERT_EQ(pc.get_player().get_position().y, -300); 
}
TEST_F(PlayerControlTest, 550_update_player_test){
    pc.get_player().set_position(50,-300);
    pc.get_player().move_left();

    pc.update_player(1.f);

    //should move left but no further than x = 50
    ASSERT_GE(pc.get_player().get_position().x, 50);  
    //should stay the same in y position
    ASSERT_EQ(pc.get_player().get_position().y, -300); 
}
TEST_F(PlayerControlTest, inactive_laser_update_player_test){
    pc.get_lasers().push_back(laser);
    pc.get_lasers().push_back(la);
    pc.update_player(1.f);

    ASSERT_EQ(pc.get_lasers().size(),1);
}


//testing draw_player() see: PlayerTest
 
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
    ASSERT_EQ(pc.get_player().get_lives(), 3);
    ASSERT_TRUE(laser->active);

}

//testing is_game_over() method
TEST_F(PlayerControlTest, is_game_over_test){
pc.set_lives(0);
ASSERT_TRUE(pc.is_game_over());
}

