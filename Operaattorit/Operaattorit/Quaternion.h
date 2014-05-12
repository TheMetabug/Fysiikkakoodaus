#pragma once
#include <iostream>
#include "Vector3D.h"
class Quaternion
{
	friend float operator*(const float scale,const Quaternion &quat);
	friend Quaternion operator+(const Quaternion &q1,const Quaternion &q2);
	friend Quaternion operator-(const Quaternion &q1,const Quaternion &q2);
	friend std::ostream & operator<<(std::ostream &out, const Quaternion &quat);

public:
	Quaternion(const float w,const float x,const float y,const float z);
	~Quaternion();
	float normalize();
	Quaternion& operator*=(const Quaternion &q);
	Quaternion rotateVec(const Vector3D &v, const float angle);
	float w,x,y,z;
};
