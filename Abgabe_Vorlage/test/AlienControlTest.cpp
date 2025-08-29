#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/control/AlienControl.hpp"
#include "../src/model/Alien.hpp"
#include "../src/view/Layer.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class AlienControlTest : public ::testing::Test {
protected:
    sf::RenderWindow dummyWindow;
    Layer dummyLayer;
    AlienControl ac;

    AlienControlTest() 
        : dummyWindow(sf::VideoMode(600.0, 600.0), "Test"), // zuerst Window
          dummyLayer(dummyWindow),                      // dann Layer mit Window
          ac(dummyLayer)                                // dann AlienControl mit Layer
    {}

    //~AlienControlTest() override = default;
};

TEST_F(AlienControlTest, create_aliens_sizeTest){
    std::vector<std::shared_ptr<Alien>> aliens = ac.create_aliens();

    ASSERT_EQ(aliens.size(), 36);
}

TEST_F(AlienControlTest, create_aliens_positionTest) {
    std::vector<std::shared_ptr<Alien>> aliens = ac.create_aliens();

    ASSERT_EQ(aliens[0]->get_position().x, 83);
    ASSERT_EQ(aliens[0]->get_position().y, -548);    
}