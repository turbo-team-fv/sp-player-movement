#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#define kVel 5

using namespace std;
class Player
{

    private:
    sf::Texture  tex;
    sf::Sprite spri;
    vector<float> pos;
    sf::IntRect frames[8];

    public:
        Player();
        virtual ~Player();
        void movePlayer(float x, float y);
        vector<float> getPos();
        sf::Sprite getSprite();

    protected:

};

#endif // PLAYER_H
