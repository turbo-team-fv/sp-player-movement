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

    pos.push_back(320.0);
    pos.push_back(240.0);


    //La carga de texturas podria ser otra clase
    tex.loadFromFile("resources/sp_alien_texture.png");
    if (!tex.loadFromFile("resources/sp_alien_texture.png"))
    {
        std::cerr << "Error cargando la imagen sp_alien_texture.png";
        exit(0);
    }
    spri.setTexture(tex);
    //Le pongo el centroide donde corresponde
    spri.setOrigin(28/2,44/2);
    //Cojo el sprite que me interesa por defecto del sheet
    spri.setTextureRect(frames[0]);
    spri.setPosition(pos[0],pos[1]);
    spri.scale(1.5,1.5);
}

sf::Sprite Player::getSprite()
{
    return spri;
}
vector<float> Player::getPos()
{
    return pos;
}
void Player::movePlayer(float x, float y) //Esto tendrá que ser un int y no un event, el event en el update
{

    //Verifico si se pulsa alguna tecla de movimiento
    pos[0]+=x;
    pos[1]+=y;
    int sp_num;
    if(x>0&&y==0){sp_num=4;}
    else if(x<0&&y==0){sp_num=6;}
    else if(x==0&&y>0){sp_num=0;}
    else if(x==0&&y<0){sp_num=2;}
    spri.setOrigin(frames[sp_num].width/2,frames[sp_num].height/2);
    spri.setTextureRect(frames[sp_num]);
    spri.setPosition(pos[0],pos[1]);

    std::cout <<x << std::endl;

    /*switch(e.key.code)
    {

    //Mapeo del cursor
    case sf::Keyboard::Right:

        pos[0]+=kVel;
        spri.setOrigin(frames[4].width/2,frames[4].height/2);
        spri.setTextureRect(frames[4]);
        spri.setPosition(pos[0],pos[1]);
        std::cout << e.key.code << std::endl;

        break;

    case sf::Keyboard::Left:

        pos[0]-=kVel;
        spri.setOrigin(frames[6].width/2,frames[6].height/2);
        spri.setTextureRect(frames[6]);
        spri.setPosition(pos[0],pos[1]);
        std::cout << e.key.code << std::endl;
        break;

    case sf::Keyboard::Up:

        pos[1]-=kVel;
        spri.setOrigin(frames[2].width/2,frames[2].height/2);
        spri.setTextureRect(frames[2]);
        spri.setPosition(pos[0],pos[1]);
        std::cout << e.key.code << std::endl;
        break;

    case sf::Keyboard::Down:

         pos[1]+=kVel;
        spri.setOrigin(frames[0].width/2,frames[0].height/2);
        spri.setTextureRect(frames[0]);
        spri.setPosition(pos[0],pos[1]);
        std::cout << e.key.code << std::endl;
        break;

    //Cualquier tecla desconocida se imprime por pantalla su código
    default:
        std::cout << e.key.code << std::endl;
        break;

    }*/


}
Player::~Player()
{
    //dtor
}
