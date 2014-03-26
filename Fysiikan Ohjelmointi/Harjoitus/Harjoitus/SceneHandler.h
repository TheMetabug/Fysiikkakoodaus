#pragma once

#include <SFML/Graphics.hpp>

#include "Scene.h"

class SceneHandler
{
public:
	static void update(double dt);
	static void draw(sf::RenderWindow &window);
	static Scene* curScene;
	static int lastScene;
};

