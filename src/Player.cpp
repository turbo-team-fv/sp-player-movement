#include "Player.h"
#include <SFML/Graphics.hpp>
using namespace std;

Player::Player(): rState(),pState()
{
    //ctor
    frames.push_back(sf::IntRect(10, 4,28, 44));//Frente 0
    frames.push_back(sf::IntRect(58, 6,28, 42));//Frente 1
    frames.push_back(sf::IntRect(8,146,32, 46));//Detras 0
    frames.push_back(sf::IntRect(56, 148,32, 44));//Detras 1
    frames.push_back(sf::IntRect(6, 98,40, 46));//SideR 0
    frames.push_back(sf::IntRect(54, 100,40, 44));//SideR 1
    frames.push_back(sf::IntRect(2, 50,40, 46));//SideL 0
    frames.push_back(sf::IntRect(50, 52,40, 44));//SideL 1

    //pos.push_back(320.0);
    //pos.push_back(240.0);



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

sf::Sprite Player::getSprite()
{
    return spri;
}
vector<double> Player::getPos()
{
    return pos;
}
void Player::setDir(int d)
{
    if(d>=0)
    {
        dir=d;
    }
}
void Player::movePlayer(double x, double y) //Esto tendrá que ser un int y no un event, el event en el update
{

    /*
        pos[0]+=x;
        pos[1]+=y;
        //Cambio dirección de los sprites
        int sp_num;
        switch(dir){
        case 0:sp_num=4;
        break;
        case 1:sp_num=6;
        break;
        case 2:sp_num=2;
        break;
        case 3:sp_num=0;
        break;
        default:sp_num=2;
        }

        spri.setOrigin(frames[sp_num].width/2,frames[sp_num].height/2);
        spri.setTextureRect(frames[sp_num]);
        spri.setPosition(pos[0],pos[1]);
    */
    //std::cout <<x << std::endl;


}
void Player::updatePlayer(double velx, double vely, sf::Time et)
{

    //pState.setAcelX(velx);
    //pState.setAcelY(vely);
    pState.setAcel(velx,vely);
    pState.updateState(et);

}
void Player::drawPlayer(sf::RenderWindow& w, double i)
{

    rState.Draw(w, pState.getPosBef(), pState.getPosNow(), i);
}

Player::~Player()
{
    //dtor
}
