#include "AlienControl.hpp"
#include <iostream>

AlienControl::AlienControl(Layer &layer) : layer(layer),
score(0),
level(1)
{
    //create first cluster of aliens with an initial speed of 20, that moves to the right
    aliens = create_aliens();
    speed = 20;
    h_dir = HorizontalDirection::RIGHT;

    //determines first outer aliens
    set_outer_aliens();

    //initialize shot time and that the game is not over
    shot_start_time = sf::seconds(0.0f);
    is_game_over = false;
}

//method that creates an alien cluster and returns all created aliens in a vector
std::vector<std::shared_ptr<Alien>> AlienControl::create_aliens() {
    int i;
    int j;
    int type;
    
    //create Alien rows
    for (i = 0; i < 4; i++){
    //determine what type of alien to draw
        if (i == 0 || i == 1) {
        type = 1;
    }
    else if (i == 2 || i == 3) {
        type = 2;
    }
        //create Alien columns
        for (j = 0; j < 9; j++) {
            float x = 83 + j * 48; // 83 is x coordinate of the column most to the right
            float y = -548 + i * 48; // -548 is y coordinate of the highest row 
            //add created alien to aliens vector
            aliens.push_back(std::make_shared<Alien> (type, sf::Vector2f {x, y}));

        }
    }
    return aliens;
}

//loops over the aliens vector and draws each element inside
void AlienControl::draw_alien() {
    for(auto &alien : aliens) {
        alien->draw(layer);
       }
}

//determines the leftest, rightest and lowest aliens
void AlienControl::set_outer_aliens() {

//initialize pointers
    most_left  = aliens.front();
    most_right = aliens.front();
    most_down = aliens.front();

    
    for (auto &alien : aliens) {
        float cur_pos = alien->get_position().x; 
        if (cur_pos > most_right->get_position().x){
            most_right = alien;
        }

        if (cur_pos < most_left->get_position().x){
            most_left = alien;
        }

        if (cur_pos > most_down->get_position().y){
            most_down = alien;
        }
    }
}

//updates aliens 
void AlienControl::update_aliens(float elapsed_time) {

    //checks for every update, if the outer aliens are still set correctly
    set_outer_aliens();

     //starts new level with faster aliens, if all the aliens in aliens are erased  //starts new level with faster aliens, if all the aliens in aliens are erased 
    if (aliens.size() == 0){
            level++;
            if(h_dir == HorizontalDirection::RIGHT) {
                speed = speed + (4 * level);}
            if(h_dir == HorizontalDirection::LEFT) {
                speed = speed - (4 * level);
            }
            //creates new alien cluster
            create_aliens(); 
    }



    //checks if alien cluster collides with window bounds and if it does makes it go down and change horizontal direction
    bool go_down = false;
        if (most_left->get_position().x < 25 && h_dir == HorizontalDirection::LEFT) {
            speed = -speed;
            h_dir = HorizontalDirection::RIGHT;
            go_down = true;
            
        }

        if (most_right->get_position().x > 575 && h_dir == HorizontalDirection::RIGHT) {
            speed = -speed;
            h_dir = HorizontalDirection::LEFT;
            go_down = true;
        }
       
        //checks if the aliens have to go down and moves them down and in the other horizontal direction 
        for(auto &alien : aliens){
            float x = alien->get_position().x;
            float y = alien->get_position().y;
            if(go_down){
                y += 16;
            }
            x += elapsed_time * speed;
            alien->set_position(x, y);
        }

    //if the aliens reach the player the game is over
    if(most_down->get_position().y > -150){
            is_game_over = true;
    }
    
    //updates all the Laser shot by aliens
   for (auto& laser: alien_lasers){
        laser->update(elapsed_time);
    }

    //erased alien lasers if they are no longer active
    alien_lasers.erase(
        std::remove_if(
            alien_lasers.begin(),
            alien_lasers.end(),
            [&](const std::shared_ptr<Laser>& laser) {
                return !laser->active;
            }
        ),
        alien_lasers.end()
    ); 

/*
    //starts new level with faster aliens, if all the aliens in aliens are erased 
    if (aliens.size() == 0){
            level++;
            speed = speed + 5 * level;
            //creates new alien cluster
            create_aliens(); 
    }
    */
}

//handles the shots of the aliens
void AlienControl::shoot_alien(){
    //selects a random alien
    std::shared_ptr<Alien> random_a = random_alien();
    //determines times between shots
    if (clock.getElapsedTime() - shot_start_time >= sf::seconds(2.0f - (0.4 * level))) {
        //adds a new laser to the alien_lasers vector
        alien_lasers.push_back(std::make_shared<Laser>(
        sf::Vector2f(random_a->get_position().x, random_a->get_position().y) , 150));
        shot_start_time = clock.getElapsedTime();
    }
};

//returns a random alien in the aliens vector
std::shared_ptr<Alien> AlienControl::random_alien(){
static std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(0, aliens.size() - 1);
int random_number = distribution(generator);  // generates number between zero and the size of the aliens vector

return aliens[random_number];
}

//returns the vector alien_lasers including all the active lasers shot by aliens 
std::vector<std::shared_ptr<Laser>> AlienControl::get_alien_lasers() {
    return alien_lasers;
}

//handles collisions with aliens
void AlienControl::collisions_aliens(std::shared_ptr<Laser> laser) {
    //for every alien in the aliens vector
    auto iteration_aliens = aliens.begin();
    while(iteration_aliens != aliens.end()){
        if (laser->get_rectangle().getGlobalBounds().findIntersection((*iteration_aliens)->get_sprite().getGlobalBounds())) {
            
            iteration_aliens = aliens.erase(iteration_aliens); //erased alien at the intersection with an laser
            
            laser->active = false; //deactivates involved laser

            set_score(score += 1); //score +1 for each shot alien

        } else {
            ++iteration_aliens; 
        }
    }
}

//returns players score
int AlienControl::get_score() {
    return score;
}

// sets players score
void AlienControl::set_score(int newScore) {
    score = newScore;
}