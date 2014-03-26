#include "ThrowBallScene.h"


ThrowBallScene::ThrowBallScene(void)
{
	Init();
}

ThrowBallScene::~ThrowBallScene(void)
{
	delete ball;
}

void ThrowBallScene::Init()
{
	ball = new Ball(10.f, 50.f, 700.f, 400.f, -1000.f, 0.8f, 0.9f, 1000.f, sf::Color(250,110,50,255));
}

void ThrowBallScene::Update(double dt)
{
	ball->Update(dt,sf::Vector2f(windowSize.x, windowSize.y));
}

void ThrowBallScene::Draw(sf::RenderWindow &window)
{
	ball->Draw(window);
}