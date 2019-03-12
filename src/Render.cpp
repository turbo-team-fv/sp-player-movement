#include "Render.h"
using namespace std;

Render::Render() : sprite()
{
    renderPos.push_back(0.0);
    renderPos.push_back(0.0);
}

Render::Render(const Render& orig)
{
}

Render::~Render()
{
}

void Render::SetTexture(sf::Texture &tex)
{
    sprite = sf::Sprite(tex);
}

void Render::SetSprite(float u,float v,sf::IntRect s,float x, float y,float scale)
{

    sprite.setOrigin(u,v);
    //Cojo el sprite que me interesa por defecto del sheet
    sprite.setTextureRect(s);
    sprite.scale(scale,scale);

}

void Render::Draw(sf::RenderWindow &window, const vector<float> &posBef,const vector<float> &posNow, float interpolation)
{
    cout<<"Posicion anterior: ";
    cout<<posBef[0]<<" "<<posBef[1];
    cout<<"Posicion ahora: ";
    cout<<posNow[0]<<" "<<posNow[1]<<endl;

    cout<<"Interpolacion: ";
    cout<<interpolation<<endl;


    renderPos[0]=(posNow[0]-posBef[0])*interpolation+posBef[0];
     renderPos[1]=(posNow[1]-posBef[1])*interpolation+posBef[1];




    sprite.setPosition(renderPos[0], renderPos[1]);
    window.draw(sprite);
}
