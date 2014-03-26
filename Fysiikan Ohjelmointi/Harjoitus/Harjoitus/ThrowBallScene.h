#pragma once

#include "Scene.h"
#include "Ball.h"

class ThrowBallScene : public Scene
{
public:
	ThrowBallScene(void);
	~ThrowBallScene(void);
	void Init();
	void Update(double dt);
	void Draw(sf::RenderWindow &window);

	Ball* ball;
	sf::Time time;
	sf::Clock clock;
	sf::Vector2f velocity;
};

