#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Mocklayer {
public:
    std::vector<const sf::Drawable*> drawnObjects;  // speichert, was gezeichnet werden sollte
    sf::View currentView;

    Mocklayer() = default;

    void add_to_layer(const sf::Drawable &drawable) {
        drawnObjects.push_back(&drawable);
    }

    void draw() {
        // im Test nichts tun
    }

    void clear() {
        drawnObjects.clear();
    }

    void set_view(const sf::View &view) {
        currentView = view;
    }

    size_t get_draw_count() const {
        return drawnObjects.size();
    }
};