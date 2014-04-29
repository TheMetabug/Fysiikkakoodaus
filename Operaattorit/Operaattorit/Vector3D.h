#pragma once
#include <iostream>
class Vector3D
{
	friend Vector3D operator*(const float scale,const Vector3D &vec3);
	friend Vector3D operator+(const Vector3D &v1,const Vector3D &v2);
	friend Vector3D operator-(const Vector3D &v1,const Vector3D &v2);
	friend std::ostream & operator<<(std::ostream &out, const Vector3D &vec3);

public:
	Vector3D();
	Vector3D(const Vector3D& vec3);
	Vector3D(float X, float Y, float Z);
	~Vector3D();
	float dot(const Vector3D &v1,const Vector3D &v2);
	Vector3D cross(const Vector3D &v2);
	Vector3D& normalize();
	float length();
	Vector3D& operator+=(Vector3D &v1);
	Vector3D& operator-=(Vector3D &v1);
	Vector3D& operator*=(float scale);

	float x, y, z;
};

