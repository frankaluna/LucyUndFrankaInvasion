#pragma once
#include <SFML/Graphics.hpp>

class ILayer {
public:
    virtual ~ILayer() = default;

    virtual void add_to_layer(const sf::Drawable &drawable) = 0;
    virtual void draw() = 0;
    virtual void clear() = 0;
    virtual void set_view(const sf::View &view) = 0;
};