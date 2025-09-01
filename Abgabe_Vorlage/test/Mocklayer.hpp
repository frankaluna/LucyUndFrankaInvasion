#include <gmock/gmock.h>
#include <SFML/Graphics.hpp>
#include "../src/view/ILayer.hpp"

class Mocklayer : public ILayer{
public:
    MOCK_METHOD(void, add_to_layer, (const sf::Drawable &drawable));
    MOCK_METHOD(void, draw, ());
    MOCK_METHOD(void, clear, ());
    MOCK_METHOD(void, set_view, (const sf::View &view)); 
    };