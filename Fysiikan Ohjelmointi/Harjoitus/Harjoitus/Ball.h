/* Ball.h
*Tämä on luokka, joka luo
* 
*
*/
#pragma once
#include <SFML/Graphics.hpp>
//#include "Scene.h"
class Ball
{
public:
	Ball(void);
	Ball(float Radius,
		float PosX,
		float PosY,
		float velocityX,
		float velocityY,
		float E,
		float F,
		float G,
		sf::Color color);
	~Ball(void);
	sf::CircleShape shape;
	float radius, velocityX, velocityY,e,f,g;
	sf::Color color;
	sf::Vector2f velocity;
	sf::Vector2f movement;
	sf::Vector2f position;

	void Update(float dt, sf::Vector2f borderSize);
	void Draw(sf::RenderWindow &window);
	void CheckCol(Ball* otherball);
	float ColMath(float u1, float m1, float u2, float m2);
	void ColX(float impact, float X);
	void ColY(float impact, float Y);
	void CheckWalls();
};

