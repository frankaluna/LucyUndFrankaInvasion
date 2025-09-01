#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/control/SpaceshipControl.hpp"
#include "Mocklayer.hpp"

class SpaceshipControlTest : public ::testing::Test{
    public:
        SpaceshipControlTest() : sc(layer){
        }
    protected:
        SpaceshipControl sc;
        Mocklayer layer;
};
//testing update() method
TEST_F(SpaceshipControlTest,update_test_notalive){
sc.get_spaceship().alive = true;
float dt = 1.0f;
sc.update(dt);
ASSERT_EQ(sc.get_last_seen(), 1.0f );
}

TEST_F(SpaceshipControlTest,update_test_alive){
sc.get_spaceship().alive = false;
float dt = 1.0f;
sc.update(dt);
ASSERT_EQ(sc.get_last_seen(), 0.0f );
}

//testing draw_spaceship() method see in SpaceshipTest

//testing appear method --> aufgrund randomizer nicht testbar

//testing start_interval method --> augrund randomizer nicht testbar


//testing collisions_spaceship method
TEST_F(SpaceshipControlTest, no_collisions_spaceship_test){
    auto laser = std::make_shared<Laser>(sf::Vector2f{500,-500}, -1);
    laser->active = true;
    sc.get_spaceship().set_position(50, -50);
    sc.get_spaceship().alive = true;
    sc.collisions_spaceship(laser);

    EXPECT_TRUE(laser->active);   // stays active
    EXPECT_TRUE(sc.get_spaceship().alive); // spaceship alive
    EXPECT_FALSE(sc.collision);   // no Collision

}
TEST_F(SpaceshipControlTest, collisions_spaceship_test){
    auto laser = std::make_shared<Laser>(sf::Vector2f{300,-300}, -1);
    laser->active = true;
    sc.get_spaceship().set_position(300, -300);
    sc.get_spaceship().alive = true;
    sc.collisions_spaceship(laser);

    EXPECT_FALSE(laser->active);   // does not stays active
    EXPECT_FALSE(sc.get_spaceship().alive); // spaceship not alive
    EXPECT_TRUE(sc.collision);   // a Collision

}