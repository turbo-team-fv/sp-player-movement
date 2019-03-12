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
    vector<double> pos;
    int dir;
    vector<sf::Rect<int> > frames;
    Render			rState;
	State       	pState;



    public:
        Player();
        virtual ~Player();
        void movePlayer(double x, double y);
        vector<double> getPos();
        void setDir(int d);
        sf::Sprite getSprite();
        void updatePlayer(double velx, double vely, sf::Time et);
        void drawPlayer(sf::RenderWindow& w, double i);

    protected:

};

#endif // PLAYER_H
