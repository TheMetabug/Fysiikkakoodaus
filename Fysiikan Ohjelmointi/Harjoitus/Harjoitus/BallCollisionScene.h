/* BallCollisionScene.h
*Tässä scenessä on useita
*satunnaisesti luotuja palloja,
*jotka törmäävät toisiinsa.
*
*/
#pragma once

#include "Scene.h"
#include "Ball.h"
#include "CollisionChecker.h"
#include <vector>

#define BALLS 5

class BallCollisionScene : public Scene
{
public:
	BallCollisionScene(void);
	~BallCollisionScene(void);
	void Init();
	void Update(double dt);
	void Draw(sf::RenderWindow &window);

	CollisionChecker collision;
	std::vector<Ball*> balls;
};

