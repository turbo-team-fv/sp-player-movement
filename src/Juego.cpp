#include "Juego.h"
#include <SFML/Graphics.hpp>
using namespace std;

Juego::Juego(int resol_x, int resol_y, string gamename){

ventana= new sf::RenderWindow(sf::VideoMode(resol_x,resol_y),gamename);
ventana->setFramerateLimit(60);

//sprites de prueba
tex = new sf::Texture;
sprite= new sf::Sprite;




tex->loadFromFile("resources/sprites.png");
if (!tex->loadFromFile("resources/sprites.png"))
    {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }

sprite->setTexture(*tex);


}


void Juego::dibuja(){

ventana->clear();
ventana->draw(pl.getSprite());
ventana->display();

}

void Juego::loop(){

        //Bucle del juego
    while (ventana->isOpen())
    {
        //Bucle de obtención de eventos
        sf::Event event;
        while (ventana->pollEvent(event))
        {

            switch(event.type){

                //Si se recibe el evento de cerrar la ventana la cierro
                case sf::Event::Closed:
                    ventana->close();
                    break;

                //Se pulsó una tecla, imprimo su codigo
                case sf::Event::KeyPressed:
                   pl.movePlayer(event);//Esto se metera en un update mas adelante

            }

        }

        ventana->clear();
        ventana->draw(pl.getSprite());
        ventana->display();
    }

}
