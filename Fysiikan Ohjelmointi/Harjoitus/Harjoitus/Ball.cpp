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
	/// Y suuntainen seinän törmäys tarkistus ///
	if(position.y > (borderSize.y-shape.getRadius())) // If touch ground
	{
		ColY(-e,borderSize.y-shape.getRadius());
	}
	else
	{
	}
	/// X suuntainen seinän törmäys tarkistus ///
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
	//piirretään shape eli pallo ruudulle
	window.draw(shape);
}

void Ball::ColX(float I, float X)
{
	//kerrotaan kimmoisuuskertoimella
	velocity.x *= I;
	//ja asetetaan positio
	position = sf::Vector2f(X,shape.getPosition().y);
	shape.setPosition(position);
}

void Ball::ColY(float I, float Y)
{
	//kerrotaan kimmoisuus- ja kitkakertoimella
	velocity.y *= I;
	velocity.x *= f;
	//ja asetetaan positio
	position = sf::Vector2f(shape.getPosition().x, Y);
	shape.setPosition(position);
}
