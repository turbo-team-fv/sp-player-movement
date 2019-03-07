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
    sf::Keyboard e;

    if(e.isKeyPressed(sf::Keyboard::Escape))
    {
        ventana->close();
    }
    if(e.isKeyPressed(sf::Keyboard::Right))
    {
        pl.movePlayer(kVel,0);
    }
    if(e.isKeyPressed(sf::Keyboard::Left))
    {
        pl.movePlayer(-kVel,0);

    }
    if(e.isKeyPressed(sf::Keyboard::Up))
    {
        pl.movePlayer(0,-kVel);

    }
    if(e.isKeyPressed(sf::Keyboard::Down))
    {
        pl.movePlayer(0,kVel);

    }

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


