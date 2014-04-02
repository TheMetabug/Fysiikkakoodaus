#include "BallCollisionScene.h"


BallCollisionScene::BallCollisionScene(void)
{
	Init();
}


BallCollisionScene::~BallCollisionScene(void)
{
	delete ball_1;
	delete ball_2;
	delete ball_3;
	delete ball_4;
	delete ball_5;
}

void BallCollisionScene::Init()
{
	ball_1 = new Ball(50.f, 1000.f, 400.f, -1000.f, 0.f, 0.9f, 0.9f, 800.f, sf::Color(255.f,100.f,255.f));
	collision.addBall(ball_1);
	
	ball_2 = new Ball(50.f, 120.f, 600.f, 300.f, 0.f, 0.9f, 0.9f, 800.f, sf::Color(100.f,255.f,255.f));
	collision.addBall(ball_2);

	ball_3 = new Ball(80.f, 520.f, 500.f, 300.f, 0.f, 0.9f, 0.9f, 800.f, sf::Color(255.f,255.f,100.f));
	collision.addBall(ball_3);

	ball_4 = new Ball(70.f, 820.f, 300.f, -300.f, 0.f, 0.9f, 0.9f, 800.f, sf::Color(150.f,150.f,255.f));
	collision.addBall(ball_4);

	ball_5 = new Ball(80.f, 20.f, 100.f, 300.f, 0.f, 0.9f, 0.9f, 800.f, sf::Color(255.f,150.f,150.f));
	collision.addBall(ball_5);

	//ball_6 = new Ball(50.f, 120.f, 2600.f, 300.f, 0.f, 0.9f, 0.9f, 800.f, sf::Color(100.f,255.f,255.f));
	//collision.addBall(ball_2);
	//add balls to colliders
}

void BallCollisionScene::Update(double dt)
{
	ball_1->Update(dt,sf::Vector2f(windowSize.x,windowSize.y));
	ball_2->Update(dt,sf::Vector2f(windowSize.x,windowSize.y));
	ball_3->Update(dt,sf::Vector2f(windowSize.x,windowSize.y));
	ball_4->Update(dt,sf::Vector2f(windowSize.x,windowSize.y));
	ball_5->Update(dt,sf::Vector2f(windowSize.x,windowSize.y));
	// ball collider physics
	collision.applyPhysics();


	//ball_2->CheckCol(ball_1);
	//ball_1->CheckCol(ball_2);
	//if(ball_1->shape.getPosition().x <
}

void BallCollisionScene::Draw(sf::RenderWindow &window)
{
	ball_1->Draw(window);
	ball_2->Draw(window);
	ball_3->Draw(window);
	ball_4->Draw(window);
	ball_5->Draw(window);
	//ball_5->Draw(window);
	//ball_6->Draw(window);
}
