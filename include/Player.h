#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <SFML/Graphics.hpp>
#define kVel 5
class Player
{

    private:
    sf::Texture  tex;
    sf::Sprite spri;
    float pos[2];
    sf::IntRect frames[8];

    public:
        Player();
        virtual ~Player();
        void movePlayer(sf::Event e);
        sf::Sprite getSprite();

    protected:

};

#endif // PLAYER_H
