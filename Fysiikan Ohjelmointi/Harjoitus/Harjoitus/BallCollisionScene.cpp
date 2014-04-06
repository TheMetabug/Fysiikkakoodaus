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
		delete balls[i];
	}
}

void BallCollisionScene::Init()
{
	for(int i = 0; i < BALLS; i++)
	{
		balls.push_back(new Ball(rand()%51+50, rand()%windowSize.x, rand()%windowSize.x, rand()%1001-500, rand()%1001-500, 0.9f, 0.9f, 800.f, sf::Color(rand()%256,rand()%256,rand()%256)));
		collision.addBall(balls[i]);
	}

	//Lisää ball objektit ja lisää ne collision listaan,
	//jotta ne voivat törmätä toisiinsa
	//ball_1 = new Ball(50.f, 1000.f, 400.f, -1000.f, 100.f, 0.9f, 0.9f, 800.f, sf::Color(255.f,100.f,255.f));
	//collision.addBall(ball_1);
	//
	//ball_2 = new Ball(50.f, 120.f, 600.f, 350.f, -600.f, 0.9f, 0.9f, 800.f, sf::Color(100.f,255.f,255.f));
	//collision.addBall(ball_2);

	//ball_3 = new Ball(80.f, 520.f, 500.f, 320.f, 0.f, 0.9f, 0.9f, 800.f, sf::Color(255.f,255.f,100.f));
	//collision.addBall(ball_3);
	//
	//ball_4 = new Ball(70.f, 820.f, 300.f, -310.f, 0.f, 0.9f, 0.9f, 800.f, sf::Color(150.f,150.f,255.f));
	//collision.addBall(ball_4);
	//
	//ball_5 = new Ball(80.f, 20.f, 100.f, 315.f, 0.f, 0.9f, 0.9f, 800.f, sf::Color(255.f,150.f,150.f));
	//collision.addBall(ball_5);
}

void BallCollisionScene::Update(double dt)
{
	//Ball collider fysiikka
	collision.applyPhysics(dt);
}

void BallCollisionScene::Draw(sf::RenderWindow &window)
{
	for(int i = 0; i < BALLS; i++)
	{
		balls[i]->Draw(window);
	}

	//ball_1->Draw(window);
	//ball_2->Draw(window);
	//ball_3->Draw(window);
	//ball_4->Draw(window);
	//ball_5->Draw(window);
}
