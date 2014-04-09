/* Scene.h
*Virtuaali luokka, mit‰ skenet
*k‰ytt‰v‰t. Sis‰lt‰‰ kaiken mit‰
*skene tarvitsee.
*/
#pragma once

#include <SFML/Graphics.hpp>

class Scene
{
public:
	Scene(void);
	~Scene(void);
	virtual void Init() = 0;
	virtual void Update(double dt) = 0;
	virtual void Draw(sf::RenderWindow &window) = 0;

	static sf::Vector2u windowSize;

private:
	int scene;
};

