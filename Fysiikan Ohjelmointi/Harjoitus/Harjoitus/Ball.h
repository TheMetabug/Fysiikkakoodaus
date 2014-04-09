/* Ball.h
*Tämä on luokka, joka luo
*itsenäisen pallon, jolla on 
*hieman fysiikkaa
*/
#pragma once
#include <SFML/Graphics.hpp>
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
	void ColX(float impact, float X);
	void ColY(float impact, float Y);
	void CheckWalls();
};

