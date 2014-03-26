#include "BallDropScene.h"


BallDropScene::BallDropScene(void)
{
	Init();
}

BallDropScene::~BallDropScene(void)
{
	delete ball;
}

void BallDropScene::Init()
{
	ball = new Ball(100.f,500.f,0.1f,500.f,0.f,0.8f,0.9f,1000.f,sf::Color(100,250,50,255));
}

void BallDropScene::Update(double dt)
{
	ball->Update(dt,sf::Vector2f(windowSize.x,windowSize.y));
}

void BallDropScene::Draw(sf::RenderWindow &window)
{
	ball->Draw(window);
}