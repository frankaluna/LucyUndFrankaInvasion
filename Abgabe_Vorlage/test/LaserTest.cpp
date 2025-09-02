#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/model/Laser.hpp"
#include "Mocklayer.hpp"

class LaserTest: public ::testing::Test{

    public:
        LaserTest(): 
        //laser player for testing
        lp({300.f,-650.f},-1.f),
        //laser alien for testing          
        la({200.f,-200.f}, 2.f) {
        }
    protected:
        //Laser for player
        Laser lp;
        //Laser for alien
        Laser la;
        //Mocklayer
        Mocklayer layer;
};
//testing the update method 
TEST_F(LaserTest,update_test){
    //setting the lasers active and the time dt to apply update method
    lp.active = true;
    la.active = true;
    float dt = 1.f;
    lp.update(dt);
    la.update(dt);

    //position should update to y=-651 and not active anymore
    ASSERT_EQ(lp.get_position().y,-651);
    ASSERT_FALSE(lp.active);
    //position of laser alien updated and still active
    ASSERT_EQ(la.get_position().y,-198);
    ASSERT_TRUE(la.active);
}
//testing draw method
TEST_F(LaserTest, draw_test){
   EXPECT_CALL(layer, add_to_layer(::testing::Ref(lp.get_rectangle()))).Times(1);
    lp.draw(layer); 
}