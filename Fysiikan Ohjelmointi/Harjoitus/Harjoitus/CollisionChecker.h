/* CollisionChecker.h
*Tarkastaa ball objektien välistä törmäystä
*ja asettaa palloille uuden suunnan ja nopeuden
*jos törmäys tapahtuu.
*/

#pragma once
#include <iostream>
#include <vector>
#include "Ball.h"

struct Collision
{
	//Tehdään collisionille omia muuttujia
	Collision(Ball* a, Ball* b, float CombR, float Ad, sf::Vector2f DifVec, sf::Vector2f VelA, sf::Vector2f VelB)
		: A(a),
		  B(b),
		  DifVector(DifVec),
		  CombRad(CombR),
		  ADif(Ad),
		  vA(VelA),
		  vB(VelB)
	{}
	//Määritetään pallot A,B ja niiden nopeudet.
	Ball* A;
	sf::Vector2f vA;
	Ball* B;
	sf::Vector2f vB;

	sf::Vector2f DifVector;
	float CombRad, ADif;
};

class CollisionChecker 
{
public:
	CollisionChecker(void);
	~CollisionChecker(void);

	//Lisää ball objektin collision listiin
	void addBall(Ball* ball);
	//Tyhjentää ball objektit listasta
	void clearBallList();
	//Collisionin "update" joka tarkastaa koskeeko pallot toisiinsa
	void applyPhysics(float dt);
private:
	//Luodaan ball:ille ja collision:ille vektorit.
	//collisionille luodaan kaksi, jolloin voidaan tarkastaa
	//pallojen törmäykset paremmin
	std::vector<Ball*> ballList;
	std::vector<Collision> collisionList;
	std::vector<std::vector<Collision>> collisionList2;
	//privaatti törmäyksen tarkastus luokka
	void CheckCol(Ball* A, Ball* B);
	//privaatti seinän törmäyksen tarkastus luokka
	void CheckWallCol(Ball*);
	//tangentti ja normaali
	sf::Vector2f tan;
	float Av_tan, tan_tan, Bv_tan, norm_norm;
};