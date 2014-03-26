#include "SceneHandler.h"
#include "BallDropScene.h"
#include "ThrowBallScene.h"
#include "BallCollisionScene.h"

Scene* SceneHandler::curScene = 0;
int SceneHandler::lastScene = -1;


void SceneHandler::update(double dt)
{
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F1) && lastScene != 1) || lastScene == -1)
	{
		curScene = new BallDropScene();
		lastScene = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F2) && lastScene != 2)
	{
		curScene = new ThrowBallScene();
		lastScene = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F3) && lastScene != 3)
	{
		curScene = new BallCollisionScene();
		lastScene = 3;
	}
	curScene->Update(dt);
}

void SceneHandler::draw(sf::RenderWindow &window)
{
	curScene->Draw(window);
}

