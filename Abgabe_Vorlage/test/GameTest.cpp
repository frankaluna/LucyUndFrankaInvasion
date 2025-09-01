#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/control/Game.hpp"


class GameTest : public ::testing::Test{

    public:
      GameTest() : g(){
      }

    protected:
      Game g;
};
//testing the start() method
TEST_F(GameTest, start_test){
  g.input() = true;
  
}

//testing the input method

//testing the update method

//testing the draw method

//
