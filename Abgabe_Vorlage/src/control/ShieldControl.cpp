#include "ShieldControl.hpp"

ShieldControl::ShieldControl(Layer &layer) : 
layer(layer) {
}

void ShieldControl::draw() {
    int i;
    float x = 54;
    float y = -125;
    for (i = 0; i < 4; i++) {
        Shield shield({x, y});
        shield.draw(layer);
        x = x + 164;
    }

}
