#pragma once
#include <iostream>
#include <vector>
#include "Ball.h"

struct Collision
{
	Collision(Ball* a, Ball* b, float CombR, float Ad)
	{
		A = a;
		B = b;
		vA = a->velocity;
		vB = b->velocity;
		CombRad = CombR;
		ADif = Ad;
	}
	Ball* A;
	sf::Vector2f vA;
	Ball* B;
	sf::Vector2f vB;

	float CombRad, ADif;
};

class CollisionChecker 
{
public:
	CollisionChecker(void);
	~CollisionChecker(void);


	void addBall(Ball* ball);
	void clearBallList();
	void applyPhysics();
private:
	std::vector<Ball*> ballList;
	std::vector<Collision> collisionList;
	std::vector<std::vector<Collision>> collisionList2;
	void CheckCol(Ball* A, Ball* B);

};