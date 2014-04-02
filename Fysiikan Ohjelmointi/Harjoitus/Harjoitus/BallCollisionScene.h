/* BallCollisionScene.h
*Tässä scenessä on useita palloja,
*jotka törmäävät toisiinsa.
*
*/
#pragma once

#include "Scene.h"
#include "Ball.h"
#include "CollisionChecker.h"

class BallCollisionScene : public Scene
{
public:
	BallCollisionScene(void);
	~BallCollisionScene(void);
	void Init();
	void Update(double dt);
	void Draw(sf::RenderWindow &window);

	Ball* ball_1;
	Ball* ball_2;
	Ball* ball_3;
	Ball* ball_4;
	Ball* ball_5;
	Ball* ball_6;

	sf::Time time;
	sf::Clock clock;
	CollisionChecker collision;

};

