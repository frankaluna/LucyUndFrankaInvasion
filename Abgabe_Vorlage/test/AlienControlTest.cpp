/*#include <gtest/gtest.h>
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
*/

#include <gtest/gtest.h>
#include "../src/control/AlienControl.hpp"
#include "../src/model/Alien.hpp"
#include "Mocklayer.hpp"

class AlienControlTest : public ::testing::Test {
public:
    AlienControlTest() : ac(layer),
        laser(std::make_shared<Laser>(sf::Vector2f(300, -60), -2)),
        la(std::make_shared<Laser>(sf::Vector2f(200, -100), -2)) {
        laser->active = true;
        la->active = false;
    }
protected:
    Mocklayer layer;
    AlienControl ac;
    std::vector<std::shared_ptr<Alien>> aliens = ac.create_aliens();
    std::shared_ptr<Laser> laser;
    std::shared_ptr<Laser> la;
};

TEST_F(AlienControlTest, create_aliens_sizeTest){
    //std::vector<std::shared_ptr<Alien>> aliens = ac.create_aliens();

    ASSERT_EQ(aliens.size(), 36);
}

TEST_F(AlienControlTest, create_aliens_positionTest) {
    //std::vector<std::shared_ptr<Alien>> aliens = ac.create_aliens(); 
    int x = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 9; j++) {
             ASSERT_EQ(aliens[x]->get_position().x, 83 + j * 48);
             ASSERT_EQ(aliens[x]->get_position().y, -548 + i * 48); 
             x++;
        }
    }   
}


//draw_alien: da Alien::draw() getestet ist und funktioniert muss auch AlienControl::draw_alien() funktionieren

TEST_F(AlienControlTest, set_outer_aliens_Test) {
    //std::vector<std::shared_ptr<Alien>> aliens = ac.create_aliens();
    ac.set_outer_aliens();

    for(auto &alien : aliens) {
        ASSERT_LE(alien->get_position().x, ac.get_most_right()->get_position().x);
        ASSERT_GE(alien->get_position().x, ac.get_most_left()->get_position().x);
        ASSERT_LE(alien->get_position().y, ac.get_most_down()->get_position().y);
    }
}

TEST_F(AlienControlTest, update_level_Test){
    int oldLevel = ac.get_level();
    int oldSpeed= ac.get_speed();
    ac.update_aliens(0.5f);

    ASSERT_EQ(ac.get_level(), oldLevel++);
}


TEST_F(AlienControlTest, update_speed_Test){
    int oldSpeed = ac.get_speed();
    ac.get_aliens().clear();
    ac.update_aliens(0.5f);

    if (ac.get_h_dir() == HorizontalDirection::LEFT) {
        ASSERT_EQ(ac.get_speed(), oldSpeed - (4 * ac.get_level()));
    } 
    
    if (ac.get_h_dir() == HorizontalDirection::RIGHT) {
        ASSERT_EQ(ac.get_speed(), oldSpeed + (4 * ac.get_level()));
    } 

}

TEST_F(AlienControlTest, update_bounds_Test){
    int oldSpeed = ac.get_speed();
    ac.update_aliens(0.5f);

    if(ac.get_most_left()->get_position().x < 25 && ac.get_h_dir() == HorizontalDirection::LEFT) {
        ASSERT_EQ(ac.get_speed(), oldSpeed * (-1));
        ASSERT_EQ(ac.get_h_dir(), HorizontalDirection::RIGHT);
    }
    if(ac.get_most_right()->get_position().x < 25 && ac.get_h_dir() == HorizontalDirection::RIGHT) {
        ASSERT_EQ(ac.get_speed(), oldSpeed * (-1));
        ASSERT_EQ(ac.get_h_dir(), HorizontalDirection::LEFT);
    }
}

TEST_F(AlienControlTest, update_down_Test) {

    for(auto &alien : aliens) {
        float x = alien->get_position().x;
        float y = alien->get_position().y;

        ac.update_aliens(0.5f);

        if(alien->get_position().x == 575 || alien->get_position().x == 25) {
            for(auto &alien :aliens) {
            ASSERT_EQ(alien->get_position().x, x + 0.5f + ac.get_speed());
            ASSERT_EQ(alien->get_position().y, y + 16); }
        }
    }
}

TEST_F(AlienControlTest, update_over_Test) {

    ac.update_aliens(0.5f);
    if (ac.get_most_down()->get_position().y > -150) {
    ASSERT_TRUE(ac.is_game_over);
    }
}


TEST_F(AlienControlTest, update_erase_Test) {
    ac.get_alien_lasers().push_back(laser);
    ac.get_alien_lasers().push_back(la);
    ac.update_aliens(0.5f);

    ASSERT_EQ(ac.get_alien_lasers().size(),1);
}

TEST_F(AlienControlTest, shoot_Test) {
    
}

