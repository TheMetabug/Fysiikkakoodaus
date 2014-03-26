#pragma once

#include "Scene.h"
#include "Ball.h"

class BallDropScene : public Scene
{
public:
	BallDropScene(void);
	~BallDropScene(void);
	void Init();
	void Update(double dt);
	void Draw(sf::RenderWindow &window);

	Ball* ball;
	//sf::CircleShape ball;
	//float G,Vx,T; 
	//sf::Vector2f movement;
	sf::Time time;
	sf::Clock clock;
	sf::Vector2f velocity;
};

