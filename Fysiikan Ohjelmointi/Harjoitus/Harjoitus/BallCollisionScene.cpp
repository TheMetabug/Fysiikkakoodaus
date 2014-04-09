#include "BallCollisionScene.h"


BallCollisionScene::BallCollisionScene(void)
{
	//kun skene luodaan, initialisoi skene
	Init();
}


BallCollisionScene::~BallCollisionScene(void)
{
	for(int i = 0; i < BALLS; i++)
	{
		//poista listasta kaikki pallot
		delete balls[i];
	}
}

void BallCollisionScene::Init()
{
	for(int i = 0; i < BALLS; i++)
	{
		//Lis�t��n pallo listaan
		balls.push_back(new Ball(rand()%51+50, 
			rand()%windowSize.x, //satunnainen x kohta
			rand()%windowSize.y, //satunnainen y kohta
			rand()%1001-500, //satunnainen x nopeus
			rand()%1001-500, ////satunnainen y nopeus
			0.9f, // kimmoisuuskerroin
			0.9f, // kitkakerroin
			800.f, // gravitaatio 
			sf::Color(rand()%256, rand()%256,rand()%256))); //satunnainen v�ri 
		//lis�� luotu pallo collisionlistaan
		collision.addBall(balls[i]);
	}

}

void BallCollisionScene::Update(double dt)
{
	//p�ivitet��n fysiikkaa ja t�rm�yksien tarkistajaa
	collision.applyPhysics(dt);

	//ball->updatea ei kutsuta, vaan t�ll� kertaa fysiikka tulee collision luokasta.
}

void BallCollisionScene::Draw(sf::RenderWindow &window)
{
	for(int i = 0; i < BALLS; i++)
	{
		//piirret��n kaikki pallot listasta
		balls[i]->Draw(window);
	}

}
