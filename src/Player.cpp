#include "Player.h"
#include <SFML/Graphics.hpp>
using namespace std;

Player::Player(): rState(),pState()
{
    //ctor
    frames.push_back(sf::IntRect(10, 4,28, 44));//Frente 0----0
    frames.push_back(sf::IntRect(58, 6,28, 42));//Frente 1----1
    frames.push_back(sf::IntRect(8,146,32, 46));//Detras 0----2
    frames.push_back(sf::IntRect(56, 148,32, 44));//Detras 1--3
    frames.push_back(sf::IntRect(6, 98,40, 46));//SideR 0-----4
    frames.push_back(sf::IntRect(54, 100,40, 44));//SideR 1---5
    frames.push_back(sf::IntRect(2, 50,40, 46));//SideL 0-----6
    frames.push_back(sf::IntRect(50, 52,40, 44));//SideL 1----7

    //La carga de texturas podria ser otra clase
    tex.loadFromFile("resources/sp_alien_texture.png");
    if (!tex.loadFromFile("resources/sp_alien_texture.png"))
    {
        std::cerr << "Error cargando la imagen sp_alien_texture.png";
        exit(0);
    }

    dir=3;
    rState.SetTexture(tex);
    rState.SetSprite(28/2,44/2,frames[0],320,240,1.5);
}


void Player::setDir(int d)
{
    if(d>=0)
    {
        dir=d;
    }
}

void Player::updatePlayer(double velx, double vely, sf::Time et)
{

    pState.setVel(velx,vely,true);//Cambia el booleano para quitar aceleracion o ponerla
    pState.updateState(et);


}
void Player::drawPlayer(sf::RenderWindow& w, double i)
{
    rState.SetRect(frames[dir]);
    rState.Draw(w, pState.getPosBef(), pState.getPosNow(), i);
}

Player::~Player()
{
    //dtor
}
