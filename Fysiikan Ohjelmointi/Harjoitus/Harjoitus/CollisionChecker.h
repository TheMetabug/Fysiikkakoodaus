/* CollisionChecker.h
*Tarkastaa ball objektien v�list� t�rm�yst�
*ja asettaa palloille uuden suunnan ja nopeuden
*jos t�rm�ys tapahtuu.
*/

#pragma once
#include <iostream>
#include <vector>
#include "Ball.h"

struct Collision
{
	//Tehd��n collisionille omia muuttujia
	Collision(Ball* a, Ball* b, float CombR, float Ad)
	{
		A = a;
		B = b;
		vA = a->velocity;
		vB = b->velocity;
		CombRad = CombR;
		ADif = Ad;
	}
	//M��ritet��n pallot A,B ja niiden nopeudet.
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

	//Lis�� ball objektin collision listiin
	void addBall(Ball* ball);
	//Tyhjent�� ball objektit listasta
	void clearBallList();
	//Collisionin "update" joka tarkastaa koskeeko pallot toisiinsa
	void applyPhysics();
private:
	//Luodaan ball:ille ja collision:ille vektorit.
	//collisionille luodaan kaksi, jolloin voidaan tarkastaa
	//pallojen t�rm�ykset paremmin
	std::vector<Ball*> ballList;
	std::vector<Collision> collisionList;
	std::vector<std::vector<Collision>> collisionList2;
	//privaatti t�rm�yksen tarkastus luokka
	void CheckCol(Ball* A, Ball* B);

};