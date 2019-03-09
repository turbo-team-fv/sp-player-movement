#ifndef STATE_H
#define STATE_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>


class State
{
    public:
        State();
        virtual ~State();

    float* getPosBef();
    float* getPosNow();
    float getAcelX();
    float getAcelY();
    void setPosBef(float x, float y);
    void setPosNow(float x, float y);
    void setAcelX(float ax);
    void setAcelY(float ay);

    void updateState(sf::Time et);

    protected:


    private:
    float posNow[2],posBef[2];
    float acelX,acelY;
};

#endif // STATE_H
