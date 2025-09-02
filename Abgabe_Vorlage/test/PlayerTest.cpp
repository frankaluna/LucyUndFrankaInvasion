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
//testing if player movement to the left works
TEST_F(PlayerTest, move_left_test){
    p.move_left();
    ASSERT_EQ(p.get_horizontal_movement(), HorizontalDirection::LEFT);
}
//testing if player moves to the right
TEST_F(PlayerTest, move_right_test){
    p.move_right();
    ASSERT_EQ(p.get_horizontal_movement(), HorizontalDirection::RIGHT);
}
//testing if player stops moving
TEST_F(PlayerTest, stop_horizontal_movement_test){
    p.stop_horizontal_movement();
    ASSERT_EQ(p.get_horizontal_movement(), HorizontalDirection::NONE);
}
//testing if the player gets drawn on mocklayer
TEST_F(PlayerTest, draw_test){
     EXPECT_CALL(layer, add_to_layer(::testing::Ref(p.get_sprite()))).Times(1);

    p.draw(layer); 
}