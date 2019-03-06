#include "Player.h"
#include <SFML/Graphics.hpp>
using namespace std;

Player::Player()
{
    //ctor
    frames[0]=sf::IntRect(10, 4,28, 44);//Frente 0
    frames[1]=sf::IntRect(58, 6,28, 42);//Frente 1
    frames[2]=sf::IntRect(8,146,32, 46);//Detras 0
    frames[3]=sf::IntRect(56, 148,32, 44);//Detras 1
    frames[4]=sf::IntRect(6, 98,40, 46);//SideR 0
    frames[5]=sf::IntRect(54, 100,40, 44);//SideR 1
    frames[6]=sf::IntRect(2, 50,40, 46);//SideL 0
    frames[7]=sf::IntRect(50, 52,40, 44);//SideL 1

    pos[0]=320.0;
    pos[1]=240.0;
    tex.loadFromFile("resources/sp_alien_texture.png");
    spri.setTexture(tex);
    //Le pongo el centroide donde corresponde
    spri.setOrigin(28/2,44/2);
    //Cojo el sprite que me interesa por defecto del sheet
    spri.setTextureRect(frames[0]);
    spri.setPosition(pos[0],pos[1]);
}

sf::Sprite Player::getSprite()
{
    return spri;
}
void Player::movePlayer(sf::Event e) //Esto tendrá que ser un int y no un event, el event en el update
{

    //Verifico si se pulsa alguna tecla de movimiento
    switch(e.key.code)
    {

    //Mapeo del cursor
    case sf::Keyboard::Right:
        /*sprite.setTextureRect(sf::IntRect(0*75, 2*75, 75, 75));
        //Escala por defecto
        sprite.setScale(1,1);
        sprite.move(kVel,0);*/
        pos[0]+=kVel;
        spri.setOrigin(frames[4].width/2,frames[4].height/2);
        spri.setTextureRect(frames[4]);
        spri.setPosition(pos[0],pos[1]);
        std::cout << e.key.code << std::endl;

        break;

    case sf::Keyboard::Left:
        /* sprite.setTextureRect(sf::IntRect(0*75, 2*75, 75, 75));
         //Reflejo vertical
         sprite.setScale(-1,1);
         sprite.move(-kVel,0);*/
        pos[0]-=kVel;
        spri.setOrigin(frames[6].width/2,frames[6].height/2);
        spri.setTextureRect(frames[6]);
        spri.setPosition(pos[0],pos[1]);
        std::cout << e.key.code << std::endl;
        break;

    case sf::Keyboard::Up:
        /*sprite.setTextureRect(sf::IntRect(0*75, 3*75, 75, 75));
        sprite.move(0,-kVel);*/
        pos[1]-=kVel;
        spri.setOrigin(frames[2].width/2,frames[2].height/2);
        spri.setTextureRect(frames[2]);
        spri.setPosition(pos[0],pos[1]);
        std::cout << e.key.code << std::endl;
        break;

    case sf::Keyboard::Down:
        /*sprite.setTextureRect(sf::IntRect(0*75, 0*75, 75, 75));
        sprite.move(0,kVel);*/
         pos[1]+=kVel;
        spri.setOrigin(frames[0].width/2,frames[0].height/2);
        spri.setTextureRect(frames[0]);
        spri.setPosition(pos[0],pos[1]);
        std::cout << e.key.code << std::endl;
        break;


    //Tecla ESC para salir
    case sf::Keyboard::Escape:
        //ventana->close();
        break;

    //Cualquier tecla desconocida se imprime por pantalla su código
    default:
        std::cout << e.key.code << std::endl;
        break;

    }


}
Player::~Player()
{
    //dtor
}
