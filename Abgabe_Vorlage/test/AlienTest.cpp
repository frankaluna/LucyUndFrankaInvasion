#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/model/Alien.hpp"

class AlienTest : public ::testing::Test {

    public:
        AlienTest() : a(2, {300, -300}) {

        }

    protected:
    Alien a;
};

TEST_F(AlienTest, move_right_Test) {
    a.move_right();
    ASSERT_EQ(a.get_horizontal_movement(), HorizontalDirection::RIGHT);
}

TEST_F(AlienTest, move_left_Test){
    a.move_left();
    ASSERT_EQ(a.get_horizontal_movement(), HorizontalDirection::LEFT);
}

TEST_F(AlienTest, move_down_Test) {
    a.move_down();
    ASSERT_EQ(a.get_vertical_movement(), VerticalDirection::DOWN);
}

/*
TEST_F(AlienTest, draw_Test) {
    Layer layer;
    EXPECT_TRUE(layer.)
    a.draw(layer)
}
*/
