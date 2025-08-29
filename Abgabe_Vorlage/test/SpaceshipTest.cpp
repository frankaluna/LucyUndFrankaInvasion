#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/model/Spaceship.hpp"

class SpaceshipTest: public ::testing::Test(){

    public:
        SpaceshipTest() : s(){
        }
    protected:
        Spaceship s;
};
/*
Test_F(SpaceshipTest,draw_test){

}*/