#ifndef STATE_H
#define STATE_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;


class State
{
    public:
        State();
        virtual ~State();

    vector<float> getPosBef();
    vector<float> getPosNow();
    float getAcelX();
    float getAcelY();
    void setPosBef(float x, float y);
    void setPosNow(float x, float y);
    void setAcelX(float ax);
    void setAcelY(float ay);

    void updateState(sf::Time et);

    protected:


    private:
    vector<float> posNow,posBef;
    float acelX,acelY;
};

#endif // STATE_H
