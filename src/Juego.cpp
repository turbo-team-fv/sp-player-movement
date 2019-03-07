#include "Juego.h"
#include <SFML/Graphics.hpp>
using namespace std;

Juego::Juego(int resol_x, int resol_y, string gamename)
{

    ventana= new sf::RenderWindow(sf::VideoMode(resol_x,resol_y),gamename);
    ventana->setFramerateLimit(60);

}

void Juego::updateGameState()
{
    float xm=0,ym=0;

    sf::Keyboard e;
    if(e.isKeyPressed(sf::Keyboard::Escape))
    {
        ventana->close();
    }


    if(e.isKeyPressed(sf::Keyboard::Right))
    {
        if(acelX<5&&acelX>(-5))
            acelX+=1;

        xm+=acelX;
        ym=0;
        pl.setDir(ym);
    }
    if(e.isKeyPressed(sf::Keyboard::Left))
    {

        if(acelX<5&&acelX>(-5))
            acelX-=1;

        xm+=acelX;
        ym=0;
        pl.setDir(1);
    }
    if(e.isKeyPressed(sf::Keyboard::Up))
    {
        if(acelY<5&&acelY>(-5)){
        acelY-=1;
        cout<<"Biiitch"<<endl;}


        xm=0;
        ym+=acelY;
        pl.setDir(2);
    }
    if(e.isKeyPressed(sf::Keyboard::Down))
    {
        if(acelY<5&&acelY>(-5))
            acelY+=1;

        xm=0;
        ym+=acelY;
        pl.setDir(3);
    }


    if (((acelY)>-0.25&&(acelY)<0.25) && ((acelX)>-0.25&&(acelX)<0.25) )
    {
        acelY = 0,acelX=0;
    }
    else
    {
        //decrease the speed
        if(acelX>0)
            acelX -= 0.1f;

        if(acelX<0)
            acelX +=0.1;

        if(acelY>0)
            acelY -= 0.1f;

        if(acelY<0)
            acelY +=0.1;
        //acelY -= 0
        //acelY -= 0.1f;
        pl.movePlayer(xm+acelX,ym+acelY);

    }

    // pl.movePlayer(0,0);





}

void Juego::render(sf::RenderWindow * ventana)
{
    ventana->clear();
    ventana->draw(pl.getSprite());
    ventana->display();
}

void Juego::loop()
{

    //Bucle del juego
    vector<float> lastPos(2);
    sf::Event e;
    while (ventana->isOpen())
    {
        ventana->pollEvent(e); //Por algun motivo, si dejo esto no pasa a estado de "Not responding"

        if(updateClock.getElapsedTime().asMilliseconds() > UPDATE_TICK_TIME)
        {
            updateGameState();
        }
        render(ventana);

    }

}


