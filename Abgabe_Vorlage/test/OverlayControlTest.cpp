#include <gtest/gtest.h>
#include "../src/control/OverlayControl.hpp"
#include "Mocklayer.hpp"
using ::testing::Ref;

class OverlayControlTest : public ::testing::Test {
    public:
    OverlayControlTest() : oc(layer) {}

    protected:
    OverlayControl oc;
    Mocklayer layer;
    
    };

//OverlayControl::update(int score, int lives) ruft ausschließlich zwei Methoden auf, die im weiteren noch getestet werden


TEST_F(OverlayControlTest, draw_Test) {
    EXPECT_CALL(layer, add_to_layer(::testing::Ref(oc.get_score_sprite())))
        .Times(1);

    EXPECT_CALL(layer, add_to_layer(::testing::Ref(oc.get_score_counter())))
        .Times(1);

    for (auto& lives_sprite : oc.get_lives_sprites()) {
    EXPECT_CALL(layer, add_to_layer(::testing::Ref(lives_sprite)))
        .Times(1);
    }

    oc.set_show_game_over(true);

    if(oc.get_show_game_over() == true) {
        EXPECT_CALL(layer, add_to_layer(::testing::Ref(oc.get_game_over_sprite())))
        .Times(1);
    }

    oc.draw(); 
}

TEST_F(OverlayControlTest, is_game_over_Test) {

    EXPECT_NO_THROW(oc.is_game_over());
 
    ASSERT_TRUE(oc.get_show_game_over());

}

TEST_F(OverlayControlTest, show_score_Test) {

    EXPECT_NO_THROW(oc.show_score(5));

    oc.show_score(5);

    ASSERT_EQ(oc.get_score_counter().getString(), "5");
}

TEST_F(OverlayControlTest, show_lives_Test) {
    oc.show_lives(3);

    ASSERT_EQ(oc.get_lives_sprites().size(), 3);
}