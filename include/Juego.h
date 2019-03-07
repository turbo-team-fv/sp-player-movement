#ifndef JUEGO_H
#define JUEGO_H
#include "Player.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>
#define UPDATE_TICK_TIME 1000/5
using namespace std;


class Juego
{
    public:
    Juego(int resol_x, int resol_y, string gamename);
    void loop();
    void render(sf::RenderWindow * ventana);
    void updateGameState();


    private:
    sf::RenderWindow * ventana;
    sf::Clock clock;
    sf::Clock updateClock;
    sf::Time restart;
    float acelX,acelY;//aceleracion
    Player pl;

};

#endif // JUEGO1_H
