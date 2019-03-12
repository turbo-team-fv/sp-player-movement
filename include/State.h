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

    vector<double> getPosBef();
    vector<double> getPosNow();
    vector<double> getAcel();

    void setPosBef(double x, double y);
    void setPosNow(double x, double y);
    void setAcel(double ax,double ay);


    void updateState(sf::Time et);

    protected:


    private:
    vector<double> posNow,posBef;
    vector<double> acel;
};

#endif // STATE_H
