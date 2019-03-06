#include "Juego.h"
#include <SFML/Graphics.hpp>
using namespace std;

Juego::Juego(int resol_x, int resol_y, string gamename)
{

    ventana= new sf::RenderWindow(sf::VideoMode(resol_x,resol_y),gamename);
    ventana->setFramerateLimit(60);

}

void Juego::updateGameState(sf::Event e)
{

    switch(e.type)
    {

    //Si se recibe el evento de cerrar la ventana la cierro
    case sf::Event::Closed:
        ventana->close();
        break;

    //Se pulsó una tecla, imprimo su codigo
    case sf::Event::KeyPressed:
        pl.movePlayer(e);

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
    while (ventana->isOpen())
    {
        //Bucle de obtención de eventos
        sf::Event event;
        while (ventana->pollEvent(event))
        {
            updateGameState(event);

        }
        render(ventana);
    }

}
