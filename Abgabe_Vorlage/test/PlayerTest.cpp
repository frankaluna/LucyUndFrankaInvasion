#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/model/Player.hpp"
#include "Mocklayer.hpp"
#include "../src/model/Directions.hpp"

class PlayerTest: public ::testing::Test{

    public:
        PlayerTest() : p(){
        }

    protected:
        Player p;
        Mocklayer layer;
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
TEST_F(PlayerTest, draw_test){
     EXPECT_CALL(layer, add_to_layer(::testing::Ref(p.get_sprite()))).Times(1);

    p.draw(layer); 
}