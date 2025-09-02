#include <gtest/gtest.h>
#include "../src/control/ShieldControl.hpp"
#include "../src/model/Shield.hpp"
#include "Mocklayer.hpp"

class ShieldControlTest : public ::testing::Test {
    public:
        ShieldControlTest() : sc(layer) {}

    protected:
    ShieldControl sc;
    Mocklayer layer;
    std::vector<std::shared_ptr<Shield>> shields = sc.create_shields();

};

TEST_F(ShieldControlTest, create_shields_sizeTest) {
    shields.clear();
    shields = sc.create_shields();
    ASSERT_EQ(shields.size(), 4);
}

TEST_F(ShieldControlTest, create_shields_positionTest) {
    shields.clear();
    shields = sc.create_shields();
    int i;
    float x = 54;
    float y = -125; 

    for (i = 0; i < 4; i++) {
        ASSERT_EQ(shields[i]->get_position().x, x + i * 164);
        ASSERT_EQ(shields[i]->get_position().y, y);
    }

}

//draw_shields: da Shield::draw() getestet ist und funktioniert muss auch ShieldControl::draw_shield() funktionieren


TEST_F(ShieldControlTest, collisions_shield_resillianceTest) {
    
    std::shared_ptr<Laser> laser_ptr (new Laser({300, -300}, -2));
    auto shield = std::make_shared<Shield>(sf::Vector2f{300, -300});
    sc.get_shields().clear();
    sc.get_shields().push_back(shield);
    int oldResiliance = shields[0]->get_resilience();

    

    sc.collisions_shield(laser_ptr);

    ASSERT_EQ(shields[0]->get_resilience(), oldResiliance - 1);
}

TEST_F(ShieldControlTest, collisions_shield_eraseTest) {
    std::shared_ptr<Laser> laser_ptr (new Laser({300, -300}, -2));
    auto shield = std::make_shared<Shield>(sf::Vector2f{300, -300});
    sc.get_shields().clear();
    sc.get_shields().push_back(shield);
   
    int oldSize = shields.size(); 
    shields[0]->set_resilience(1);

    sc.collisions_shield(laser_ptr);

    ASSERT_EQ(sc.get_shields().size(), oldSize - 1);
}