#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/model/Player.hpp"

class PlayerTest: public ::testing::Test{

    public:
        PlayerTest() : p(){
        }

    protected:
        Player p;
};

TEST_F(PlayerTest, move_left_test){
    p.move_left();
    ASSERT_EQ(p.get_horizontal_movement(), HorizontalDirection::LEFT);
}
TEST_F(PlayerTest, move_right_test){
    p.move_right();
    ASSERT_EQ(p.get_horizontal_movement(), HorizontalDirection::RIGHT);
}
TEST_F(PlayerTest, stop_horizontal_movement_test){
    p.stop_horizontal_movement();
    ASSERT_EQ(p.get_horizontal_movement(), HorizontalDirection::NONE);
}
//draw method ergänzen