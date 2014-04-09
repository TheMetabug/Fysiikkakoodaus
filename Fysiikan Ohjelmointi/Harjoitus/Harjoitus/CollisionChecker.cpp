#include "CollisionChecker.h"
#include <cassert>
#include <cmath>
#include <iostream>
#include "Scene.h"

CollisionChecker::CollisionChecker(void)
{
	Av_tan = 0;
	Bv_tan = 0;
	tan_tan = 0;
}


CollisionChecker::~CollisionChecker(void)
{
}

void CollisionChecker::addBall(Ball* ball)
{
	//lis�� haluttu ball objekti ballList:aan
	ballList.push_back(ball);
}

void CollisionChecker::clearBallList()
{
	//tyhjenn� ballist
	ballList.clear();
}

void CollisionChecker::applyPhysics(float dt)
{
	for(auto it = ballList.begin(); it != ballList.end(); it++)	//k�yd��n listaa palloista l�pi
	{
		CheckWallCol((*it)); // tarkistetaan sein�n kanssa t�rm�ys
		(*it)->velocity.y += (*it)->g*dt; // gravitaatio
	}
	//aluksi lis�t��n collisionList2:seen collision
	collisionList2.push_back(collisionList);
	//tarkistetaan pallojen t�rm�ys, jossa i on t�rm��v� pallo
	//ja j on t�rm�tt�v� pallo
	for(int i = 0; ballList.size() > i; i++)	//k�yd��n listaa palloista l�pi
	{
		for(int j = 0; ballList.size() > j; j++) //ja muista palloista joita on olemassa
		{
			if(i != j)	//tarkistetaan ett� i ja j ei ole samoja, kun pallo ei saisi t�rm�t� itsens� kanssa
				CheckCol(ballList[i], ballList[j]); //tarkistetaan onko n�m� kaksi palloa t�rm�nneet
		}
		if (collisionList2.back().size() > 0)		//tarkistetaan tuliko checkcol():sta collisionlistalle tavaraa
			collisionList2.push_back(collisionList); //jos tuli, niin laitetaan listaan toinen collision
	}
	collisionList2.pop_back();
	
	//std::cout<<"point 2 : "<<clock.restart().asMicroseconds()<<std::endl;

	for(int i = 0; collisionList2.size() > i; i++)
	{
		collisionList2[i][0].A->velocity = sf::Vector2f(0,0);
	}
	
	for(int i = 0; collisionList2.size() > i; i++)
	{
		if (collisionList2[i].size() > 1)
		{
			//t�h�n pit�isi tulla ominaisuuksia, jos yhteen palloon
			//t�rm�� kaksi palloa, mutta jouduin j�tt�m��n sen pois
		}
		//Tehd��n ensimm�isest� t�rm�yksest� C muuttuja
		const Collision& C = collisionList2[i][0];

		//Lasketaan pallojen v�linen et�isyysvektori
		const sf::Vector2f difVector = C.DifVector;

		//Muokkataan nykyisen pallon suuntavektoria
		//Jokaiselle kollisionille siirret��n pallot erikseen 
		//(CombRad - ADif) /2 siirt�� kumpaakin palloa erilleen toisistaan
		C.A->position += ((C.CombRad - C.ADif)*0.5f)*(difVector/C.ADif);

		//Pallojen massa laskettuna r:n mukaan
		float Am = 4*3.14159*pow(C.A->radius,3)/3;
		float Bm = 4*3.14159*pow(C.B->radius,3)/3;

		//lasketaan pallojen v�linen tangentti
		tan = sf::Vector2f(-difVector.y, difVector.x);
		tan_tan = tan.x*tan.x + tan.y*tan.y;

		//lasketaan normaali
		norm_norm = difVector.x*difVector.x + difVector.y*difVector.y;

		//Lasketaan pallon A uusi nopeus/suunta tangentin avulla
		Av_tan = (C.vA.x*tan.x) + (C.vA.y*tan.y);
		C.A->velocity += (Av_tan / tan_tan) * tan;
		
		//Lasketaan pallon B uusi nopeus/suunta normaalin avulla
		Bv_tan = (C.vA.x*difVector.x) + (C.vA.y*difVector.y);
		C.B->velocity += (Bv_tan / norm_norm) * difVector;

	}
	//tyhjennet��n lista lopuksi
	collisionList2.clear();

	for(auto it = ballList.begin(); it != ballList.end(); it++)	//k�yd��n listaa palloista l�pi
	{
		//p�ivitet��n pallojen position arvoja
		(*it)->movement = sf::Vector2f((*it)->position.x+(*it)->velocity.x*dt,(*it)->position.y+(*it)->velocity.y*dt);
		(*it)->position = (*it)->movement;
		(*it)->shape.setPosition((*it)->position);
	}
}

void CollisionChecker::CheckCol(Ball* ballA, Ball* ballB)
{
	//nimet��n kappaleet ja niiden parametrit A:ksi ja B:ksi
	const sf::Vector2f posA = ballA->position;
	const sf::Vector2f velA = ballA->velocity;
	const float radA = ballA->shape.getRadius();
	const sf::Vector2f posB = ballB->position;
	const sf::Vector2f velB = ballB->velocity;
	const float radB = ballB->shape.getRadius();

	//Lasketaan niiden x ja y suuntainen et�isyys 2D avaruudessa
	const sf::Vector2f DifVector = posA - posB;

	//lasketaan x ja y eroista pituusvektori
	const float ADif = sqrt(pow(DifVector.x,2) + pow(DifVector.y,2));

	//Lasketaan pallojen yhteen laskettu s�de
	const float CombRad = radA + radB;

	//katsotaan onko et�isyysvektori pienempi kuin pallojen
	//yhteisen s�teen pituus, jos on niin t�rm�ys on tapahtunut
	if(ADif < CombRad)
	{
		//kun t�rm�ys on tapahtunut, lis�t��n tiedot t�rm�yksest� collisionList2:lle
		collisionList2.back().push_back(Collision(ballA, ballB,CombRad, ADif, DifVector, velA, velB));
	}

}

void CollisionChecker::CheckWallCol(Ball* ball)
{
	
	/// Y suunnassa sein�n t�rm�ys ///
	if(ball->position.y > (Scene::windowSize.y-ball->shape.getRadius())) // If touch ground
	{
		ball->ColY(-ball->e,Scene::windowSize.y-ball->shape.getRadius());
	}
	else if(ball->position.y < (0+ball->shape.getRadius()))
	{
		ball->ColY(-ball->e,0+ball->shape.getRadius());
	}
	/// X suunnassa sein�n t�rm�ys///
	if(ball->position.x > (Scene::windowSize.x-ball->shape.getRadius())) // If hits left border
	{
		ball->ColX(-ball->e, Scene::windowSize.x-ball->shape.getRadius()); 
	}
	else if(ball->position.x < 0.f+ball->shape.getRadius()) // If hits rigth border
	{
		ball->ColX(-ball->e, ball->shape.getRadius());
	}
}