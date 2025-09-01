#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/control/SpaceshipControl.hpp"

class SpaceshipControlTest : public ::testing::Test{
    public:
        SpaceshipControlTest() : sc(layer){
        }
    protected:
        SpaceshipControl sc;
        Layer layer;
};
//testing update() method

//testing draw_spaceship() method

//testing appear method

//testing start_interval method

//testing collisions_spaceship method