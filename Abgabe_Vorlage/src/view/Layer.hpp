#ifndef LAYER_H
#define LAYER_H

#include <SFML/Graphics.hpp>
#include "ILayer.hpp"

// Layer class
class Layer : public ILayer{
public:   
    // Initializes the layer in the given window
    Layer(sf::RenderWindow &window);

    // adds the drawable element to the layer
    void add_to_layer(const sf::Drawable &drawable) override;

    // draws the scene to the window
    void draw() override;

    // clear the layer, remove all drawable elements
    void clear() override;

    // adjust the layer's view
    void set_view(const sf::View &view) override;

private:
    // window in which the layer is shown
    sf::RenderWindow &window;

    // render target
    sf::RenderTexture target;

    // sprite to which the target is drawn, that gets shown in the window
    sf::Sprite sprite;
};

#endif