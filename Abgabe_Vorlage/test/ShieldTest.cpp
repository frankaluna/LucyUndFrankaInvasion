#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/model/Shield.hpp"
#include "Mocklayer.hpp"

using ::testing::Ref;

class ShieldTest : public ::testing::Test {
    public:
        ShieldTest() : s({300, -300}) {
        }

    protected:
        Shield s;
        Mocklayer layer;
};

TEST_F(ShieldTest, draw_Test) {
    EXPECT_CALL(layer, add_to_layer(Ref(s.get_sprite())))
        .Times(1);

    s.draw(layer); 
};

