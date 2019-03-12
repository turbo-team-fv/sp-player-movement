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

void Render::SetSprite(double u,double v,sf::IntRect s,double x, double y,double scale)
{

    sprite.setOrigin(u,v);
    //Cojo el sprite que me interesa por defecto del sheet
    sprite.setTextureRect(s);
    sprite.scale(scale,scale);

}

void Render::Draw(sf::RenderWindow &window, const vector<double> &posBef,const vector<double> &posNow, double interpolation)
{
    cout<<"Posicion anterior: ";
    cout<<posBef[0]<<" "<<posBef[1];
    cout<<"Posicion ahora: ";
    cout<<posNow[0]<<" "<<posNow[1]<<endl;



    renderPos[0]=(posNow[0]-posBef[0])*interpolation+posBef[0];
     renderPos[1]=(posNow[1]-posBef[1])*interpolation+posBef[1];

     renderPos[0]=posBef[0]*(1-interpolation)+posNow[0]*interpolation;
     renderPos[1]=posBef[1]*(1-interpolation)+posNow[1]*interpolation;




    sprite.setPosition(renderPos[0], renderPos[1]);
    window.draw(sprite);
}
