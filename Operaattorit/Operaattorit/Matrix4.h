#pragma once
#include "Vector3D.h"
class Matrix4
{
	friend Matrix4 operator*(const Matrix4& M, const float S );
	friend Vector3D operator*(const Matrix4& M, const Vector3D V );
	friend Matrix4 operator*(const Matrix4& M1,const Matrix4& M2);
	friend Matrix4 operator+(const Matrix4& M1,const Matrix4& M2);
	friend std::ostream & operator<<(std::ostream &out, const Matrix4 &mat4);

public:
	Matrix4(const float *data);
	Matrix4(const float d1, const float d2, const float d3, const float d4,
		    const float d5, const float d6, const float d7, const float d8,
			const float d9, const float d10,const float d11,const float d12,
			const float d13,const float d14,const float d15,const float d16);
	Matrix4(Matrix4& matrix4);
	~Matrix4();

	float determ();

	Matrix4 Inverse();
	float	a,b,c,d,
			e,f,g,h,
			i,j,k,l,
			m,n,o,p;
};

