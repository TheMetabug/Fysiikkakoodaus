#include "Ball.h"
#include <iostream>

Ball::Ball(float R, float X, float Y, float vX,float vY,float E, float F, float G, sf::Color c)
	:	radius(R),
		position(X,Y),
		velocityX(vX),
		velocityY(vY),
		e(E),
		f(F),
		g(G),
		color(c)
{
	shape.setRadius(radius);
	shape.setOrigin(radius,radius);
	shape.setFillColor(color);
	shape.setPosition(position);
	velocity = sf::Vector2f(velocityX, velocityY);
}

Ball::~Ball(void)
{
}

void Ball::Update(float dt, sf::Vector2f borderSize)
{
	/// Y MOVEMENT ///
	if(position.y > (borderSize.y-shape.getRadius())) // If touch ground
	{
		ColY(-e,borderSize.y-shape.getRadius());
	}
	else
	{
	}
	/// X MOVEMENT ///
	if(position.x > (borderSize.x-shape.getRadius())) // If hits left border
	{
		ColX(-e, borderSize.x-shape.getRadius()); 
	}
	else if(position.x < 0.f+shape.getRadius()) // If hits rigth border
	{
		ColX(-e, shape.getRadius());
	}
	/// Overall Movement ///
	velocity.y +=  g*dt;
	movement = sf::Vector2f(position.x+velocity.x*dt,position.y+velocity.y*dt);
	position = movement;
	shape.setPosition(position);
}

void Ball::Draw(sf::RenderWindow &window)
{
	window.draw(shape);
}

void Ball::CheckCol(Ball* otherBall)
{
	//const sf::CircleShape A = shape;
	//const sf::CircleShape B = otherBall->shape;
	//float xDif = A.getPosition().x - B.getPosition().x;
	//float CombRad = A.getRadius() + B.getRadius();
	//float ADif = sqrt(pow(xDif,2)/*+pow(yDif,2)*/);

	//if(ADif < CombRad)
	//{return true;
	//}
}

void Ball::ColX(float I, float X)
{
	velocity.x *= I;
	position = sf::Vector2f(X,shape.getPosition().y);
	shape.setPosition(position);
}

void Ball::ColY(float I, float Y)
{
	velocity.y *= I;
	position = sf::Vector2f(shape.getPosition().x, Y);
	shape.setPosition(position);
	velocity.x *= f;
}

float Ball::ColMath(float u1, float m1, float u2, float m2)
{
	float v1 = (u1*(m1-m2)+(2*m2*u2))/(m1+m2);
	//float v2 = (u2*(m2-m1)+(2*m1*u1))/(m1+m2);

	return v1;
}
