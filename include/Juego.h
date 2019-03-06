#ifndef JUEGO_H
#define JUEGO_H


#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;


class Juego
{
    public:
    Juego(int resol_x, int resol_y, string gamename);
    void dibuja();
    void loop();
    void render(sf::RenderWindow * ventana);
    void updateGameState(sf::Event e);


    private:
    sf::RenderWindow * ventana;
    sf::Clock clock;
    sf::Clock updateClock;
    sf::Texture * tex;
    sf::Sprite * sprite;
    Player pl;

};

#endif // JUEGO1_H
