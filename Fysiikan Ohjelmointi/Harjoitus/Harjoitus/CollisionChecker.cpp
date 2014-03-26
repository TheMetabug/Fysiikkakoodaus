#include "CollisionChecker.h"
#include <cassert>


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
			assert(false);
		const Collision& C = collisionList2[i][0];
		// jokaiselle kollisionille siirretään pallot erikseen 
		//(CombRad - ADif) /2 siirtää kumpaakin palloa erilleen toisistaan
		// muokkaa nykyisen pallon suuntavektoria
		float difVector =	(C.A->position.x - C.B->position.x)/C.ADif;
		C.A->position.x +=	((C.CombRad - C.ADif)/2)*difVector;
		C.B->position.x -=	((C.CombRad - C.ADif)/2)*difVector;
		
		C.A->velocity.x = (C.vA.x*(C.A->radius - C.B->radius) + 2.f*C.B->radius*C.vB.x)/(C.A->radius + C.B->radius);
		C.B->velocity.x = (C.vB.x*(C.B->radius - C.A->radius) + 2.f*C.A->radius*C.vA.x)/(C.A->radius + C.B->radius);
		//////////////////////////
	}
	collisionList2.clear();

}

void CollisionChecker::CheckCol(Ball* ballA, Ball* ballB)
{
	const sf::CircleShape A = ballA->shape;
	const sf::CircleShape B = ballB->shape;
	const float xDif = A.getPosition().x - B.getPosition().x;
	const float CombRad = A.getRadius() + B.getRadius();
	const float ADif = sqrt(pow(xDif,2)/*+pow(yDif,2)*/);

	
	if(ADif < CombRad)
	{
		collisionList2.back().push_back(Collision(ballA, ballB,CombRad, ADif));
	}

}