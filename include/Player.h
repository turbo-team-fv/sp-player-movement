#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Render.h"
#define kVel 5

using namespace std;
class Player
{

    private:
    sf::Texture  tex;
    sf::Sprite spri;
    vector<float> pos;
    int dir;
    sf::IntRect frames[8];
    Render			rState;
	State       	pState;



    public:
        Player();
        virtual ~Player();
        void movePlayer(float x, float y);
        vector<float> getPos();
        void setDir(int d);
        sf::Sprite getSprite();
        void updatePlayer(float velx, float vely, sf::Time et);

    protected:

};

#endif // PLAYER_H
