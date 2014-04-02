#pragma once

#include <SFML/Graphics.hpp>

#include "Scene.h"

class SceneHandler
{
public:
	static void update(double dt);
	static void draw(sf::RenderWindow &window);
	static void init();
	static void deinit();
	static Scene* curScene;
	static int lastScene;

	static sf::Text* text;
	static sf::Font* font;
	static float time;
};

