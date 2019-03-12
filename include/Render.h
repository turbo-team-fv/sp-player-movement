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
	void SetSprite(float u,float v,sf::IntRect s,float x, float y,float scale);
	void Draw(sf::RenderWindow &window, const vector<float> &posBef,const vector<float> &posNow, float interpolation);
	sf::Sprite &GetSprite() { return sprite; }
	vector<float> GetRenderPosition() const { return renderPos; }

private:
	sf::Sprite	sprite;
	vector<float> renderPos;
};

#endif // RENDER_H
