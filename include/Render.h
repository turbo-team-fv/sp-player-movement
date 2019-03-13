#ifndef RENDER_H
#define RENDER_H
#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>
using namespace std;

class Render {
public:
	Render();
	Render(const Render& orig);
	virtual ~Render();
	void SetTexture(sf::Texture &tex);
	void SetSprite(double u,double v,sf::IntRect s,double x, double y,double scale);
	void Draw(sf::RenderWindow &window, const vector<double> &posBef,const vector<double> &posNow, double interpolation);
	void SetRect(sf::IntRect s);
	sf::Sprite &GetSprite() { return sprite; }
	vector<double> GetRenderPosition() const { return renderPos; }

private:
	sf::Sprite	sprite;
	vector<double> renderPos;
};

#endif // RENDER_H
