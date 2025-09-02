#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/model/Spaceship.hpp"
#include "Mocklayer.hpp"

using ::testing::Ref;

class SpaceshipTest: public ::testing::Test{

    public:
        SpaceshipTest() : s(){
        }
    protected:
        Spaceship s;
        Mocklayer layer;
};

TEST_F(SpaceshipTest,draw_test){
    EXPECT_CALL(layer, add_to_layer(Ref(s.get_sprite()))).Times(1);

    s.draw(layer); 
};