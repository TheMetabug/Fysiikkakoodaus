#include "CollisionChecker.h"
#include <cassert>
#include <cmath>

CollisionChecker::CollisionChecker(void)
{
}


CollisionChecker::~CollisionChecker(void)
{
}

void CollisionChecker::addBall(Ball* ball)
{
	ballList.push_back(ball);
}

void CollisionChecker::clearBallList()
{
	ballList.clear();
}

void CollisionChecker::applyPhysics()
{
	collisionList2.push_back(std::vector<Collision>());
	for(int i = 0; ballList.size() > i; i++)
	{
		for(int j = 0; ballList.size() > j; j++)
		{
			if(i != j)
				CheckCol(ballList[i], ballList[j]);
		}
		if (collisionList2.back().size() > 0)
			collisionList2.push_back(std::vector<Collision>());
	}
	collisionList2.pop_back();

	for(int i = 0; collisionList2.size() > i; i++)
	{
		if (collisionList2[i].size() > 1)
		{
			//assert(false);
		}
		const Collision& C = collisionList2[i][0];
		// jokaiselle kollisionille siirretään pallot erikseen 
		//(CombRad - ADif) /2 siirtää kumpaakin palloa erilleen toisistaan
		// muokkaa nykyisen pallon suuntavektoria
		sf::Vector2f difVector = (C.A->position - C.B->position)/C.ADif;
		float difVectorY =	(C.A->position.y - C.B->position.y)/C.ADif;

		C.A->position += ((C.CombRad - C.ADif)/2)*difVector;
		C.B->position -= ((C.CombRad - C.ADif)/2)*difVector;
		
		//Pallojen massa laskettuna r:n mukaan
		float Am = 4*3.14159*pow(C.A->radius,3)/3;
		float Bm = 4*3.14159*pow(C.B->radius,3)/3;
		//Palloille asetetaan uusi suunta ja nopeus
		C.A->velocity = (C.vA*(Am - Bm) + 2.f*Bm*C.vB)/(Am + Bm);
		C.B->velocity = (C.vB*(Bm - Am) + 2.f*Am*C.vA)/(Am + Bm);

		/*C.A->velocity = */

	}
	collisionList2.clear();

}

void CollisionChecker::CheckCol(Ball* ballA, Ball* ballB)
{
	const sf::CircleShape A = ballA->shape;
	const sf::CircleShape B = ballB->shape;
	const float xDif = ballA->position.x - ballB->position.x;
	const float yDif = ballA->position.y - ballB->position.y;
	const float CombRad = A.getRadius() + B.getRadius();
	const float ADif = sqrt(pow(xDif,2) + pow(yDif,2));

	
	if(ADif < CombRad)
	{
		collisionList2.back().push_back(Collision(ballA, ballB,CombRad, ADif));
	}

}