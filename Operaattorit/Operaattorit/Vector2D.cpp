#include "Vector2D.h"

Vector2D::Vector2D(){}
Vector2D::Vector2D(float X, float Y)
	:x(X),
	 y(Y)
{}

Vector2D::~Vector2D(void)
{
}

void Vector2D::print()
{
	std::cout << "X: " << x << "  Y: " << y << std::endl;
}

Vector2D operator+(Vector2D &LeftVal, Vector2D &RightVal)
{
	Vector2D result;
	result.x = LeftVal.x + RightVal.x;
	result.y = LeftVal.y + RightVal.y;
	return result;
}
Vector2D operator-(Vector2D &LeftVal, Vector2D &RightVal)
{
	Vector2D result;
	result.x = LeftVal.x - RightVal.x;
	result.y = LeftVal.y - RightVal.y;
	return result;
}
float operator*(Vector2D &LeftVal, Vector2D &RightVal)
{
	float result;
	result = (LeftVal.x * RightVal.x) + (LeftVal.y * RightVal.y);
	return result;
}
Vector2D operator*(Vector2D &LeftVal, float value)
{
	Vector2D result;
	result.x = (LeftVal.x * value);
	result.y = (LeftVal.y * value);
	return result;
}