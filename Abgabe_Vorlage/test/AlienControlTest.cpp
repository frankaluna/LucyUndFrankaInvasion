#include <gtest/gtest.h>
#include "../src/control/AlienControl.hpp"
#include "../src/model/Alien.hpp"
#include "Mocklayer.hpp"

//Test class for Alien Control

class AlienControlTest : public ::testing::Test {
public:
//initialization of test class
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
    std::vector<std::shared_ptr<Laser>>& alien_lasers = ac.get_alien_lasers();
};

//tests, if there are 36 aliens being created for the alien cluster
TEST_F(AlienControlTest, create_aliens_sizeTest){
    aliens.clear();
    aliens = ac.create_aliens();

    ASSERT_EQ(aliens.size(), 36);
}

//tests if all 36 aliens are in the right spot
TEST_F(AlienControlTest, create_aliens_positionTest) {
   aliens.clear();
    aliens = ac.create_aliens();
    int x = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 9; j++) {
             ASSERT_EQ(aliens[x]->get_position().x, 83 + j * 48);
             ASSERT_EQ(aliens[x]->get_position().y, -548 + i * 48); 
             x++;
        }
    }   
}

//tests, if outer aliens are being set right
TEST_F(AlienControlTest, set_outer_aliens_Test) {
    //std::vector<std::shared_ptr<Alien>> aliens = ac.create_aliens();
    ac.set_outer_aliens();

    for(auto &alien : aliens) {
        ASSERT_LE(alien->get_position().x, ac.get_most_right()->get_position().x);
        ASSERT_GE(alien->get_position().x, ac.get_most_left()->get_position().x);
        ASSERT_LE(alien->get_position().y, ac.get_most_down()->get_position().y);
    }
}

//tests if level is updated
TEST_F(AlienControlTest, update_level_Test){
    int oldLevel = ac.get_level();
    ac.update_aliens(0.5f);

    ASSERT_EQ(ac.get_level(), oldLevel++);
}


//tests if speed is updated
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

//tests if bounds are correctly updated
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


//tests if aliens have to move down
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

//tests if the game is over / if aliens reached the Shields
TEST_F(AlienControlTest, update_over_Test) {

    ac.update_aliens(0.5f);
    if (ac.get_most_down()->get_position().y > -150) {
    ASSERT_TRUE(ac.is_game_over);
    }
}


//tests if inactive lasers are properly erased
TEST_F(AlienControlTest, update_erase_Test) {
    ac.get_alien_lasers().push_back(laser);
    ac.get_alien_lasers().push_back(la);
    ac.update_aliens(0.5f);

    ASSERT_EQ(ac.get_alien_lasers().size(),1);
}

//tests if aliens shoot properly
TEST_F(AlienControlTest, shoot_Test) {
    ac.get_alien_lasers().clear();
    ac.get_shot_start_time() = sf::seconds(-100.f);
    ac.shoot_alien();

    ASSERT_EQ(ac.get_alien_lasers().size(), 1);
}

//tests if aliens dissapear if colliding with players lasers 
TEST_F(AlienControlTest, collisions_aliens_Test) {
    std::shared_ptr<Laser> laser_ptr (new Laser({300, -300}, -2));
    ac.get_aliens().clear();
    ac.random_alien()->set_position(300, -300);
    ac.get_aliens().push_back(ac.random_alien());

    ASSERT_EQ(ac.get_aliens().size(), 1);

    ac.collisions_aliens(laser_ptr);

    ASSERT_EQ(ac.get_aliens().size(), 0);
} 

//random_alien() is not being tested because of the randomizer