#pragma once
#include "Vector3D.h"
class Matrix3
{
	friend Vector3D operator*(const Matrix3& M, const Vector3D V );
	friend Matrix3 operator*(const Matrix3& M1,const Matrix3& M2);
	friend Matrix3 operator+(const Matrix3& M1,const Matrix3& M2);
	friend std::ostream & operator<<(std::ostream &out, const Matrix3 &mat3);

public:
	Matrix3(const float *data);
	Matrix3(Matrix3& matrix3);
	~Matrix3();

	Vector3D determ(Matrix3&);
	void Transpose();
	float x,y,z,w,h,g,i,j,k;
};

