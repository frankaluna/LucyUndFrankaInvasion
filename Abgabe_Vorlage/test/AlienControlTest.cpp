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
    AlienControlTest() : ac(layer) {
        // Hack: falls dein AlienControl einen echten Layer& erwartet
        // Besser: AlienControl so umbauen, dass er ein Interface nimmt
    }
protected:
    Mocklayer layer;
    AlienControl ac;
};

TEST_F(AlienControlTest, create_aliens_sizeTest){
    std::vector<std::shared_ptr<Alien>> aliens = ac.create_aliens();

    ASSERT_EQ(aliens.size(), 36);
}

TEST_F(AlienControlTest, create_aliens_positionTest) {
    std::vector<std::shared_ptr<Alien>> aliens = ac.create_aliens(); 
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
    std::vector<std::shared_ptr<Alien>> aliens = ac.create_aliens();
    ac.set_outer_aliens();

    for(auto &alien : aliens) {
        ASSERT_LE(alien->get_position().x, ac.get_most_right()->get_position().x);
        ASSERT_GE(alien->get_position().x, ac.get_most_left()->get_position().x);
        ASSERT_LE(alien->get_position().y, ac.get_most_down()->get_position().y);
    }
}

TEST_F(AlienControlTest, update_level_Test){
    
}