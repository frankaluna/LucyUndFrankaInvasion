#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/model/Laser.hpp"

class LaserTest: public ::testing::Test{

    public:
        LaserTest(): lp({300,-650},-1),
                     la({200,-200}, 2) {
        }
    protected:
        //Laser for player
        Laser lp;
        //Laser for alien
        Laser la;
};
TEST_F(LaserTest,update_test){
    lp.active = true;
    la.active = true;
    float dt = 1.0;
    lp.update(dt);
    la.update(dt);

    ASSERT_EQ(lp.get_position().y,-651);
    ASSERT_EQ(lp.active, false);

    ASSERT_EQ(la.get_position().y,-198);
    ASSERT_EQ(la.active, true);
}
/*TEST_F(LaserTest, draw_test){
    lp.active = true;
    la.active = false;
    ASSERT_EQ(lp.draw(), )
}*/