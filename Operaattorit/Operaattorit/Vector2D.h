#pragma once
#include <iostream>
class Vector2D
{
	friend Vector2D operator+(Vector2D &v1, Vector2D &v2);
	friend Vector2D operator-(Vector2D &v1, Vector2D &v2);
	friend float	operator*(Vector2D &v1, Vector2D &v2);
	friend Vector2D	operator*(Vector2D &v, float Value);
public:
	Vector2D();
	Vector2D(float X,float Y);
	~Vector2D(void);

	float x,y;

	void print();

};

