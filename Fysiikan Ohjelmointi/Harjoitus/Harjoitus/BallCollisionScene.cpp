#include "BallCollisionScene.h"


BallCollisionScene::BallCollisionScene(void)
{
	Init();
}


BallCollisionScene::~BallCollisionScene(void)
{
	delete ball_1;
	delete ball_2;
}

void BallCollisionScene::Init()
{
	ball_1 = new Ball(100.f, 1000.f, 600.f, -1000.f, 0.f, 0.9f, 0.9f, 800.f, sf::Color(255.f,100.f,255.f));
	collision.addBall(ball_1);
	
	ball_2 = new Ball(50.f, 120.f, 600.f, 300.f, 0.f, 0.9f, 0.9f, 800.f, sf::Color(100.f,255.f,255.f));
	collision.addBall(ball_2);

	//add balls to colliders
}

void BallCollisionScene::Update(double dt)
{
	ball_1->Update(dt,sf::Vector2f(windowSize.x,windowSize.y));
	ball_2->Update(dt,sf::Vector2f(windowSize.x,windowSize.y));

	// ball collider physics
	collision.applyPhysics();


	ball_2->CheckCol(ball_1);
	ball_1->CheckCol(ball_2);
	//if(ball_1->shape.getPosition().x <
}

void BallCollisionScene::Draw(sf::RenderWindow &window)
{
	ball_1->Draw(window);
	ball_2->Draw(window);
}
