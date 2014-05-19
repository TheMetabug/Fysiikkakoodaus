#include "Matrix3.h"

//Create matrix by using float[9]
Matrix3::Matrix3(const float *data)
	:x(data[0]), y(data[1]), z(data[2]),
	 w(data[3]), h(data[4]), g(data[5]),
	 i(data[6]), j(data[7]), k(data[8]){}
//Create matrix by inserting float straight into right places
Matrix3::Matrix3(const float d1,const float d2,const float d3,
				 const float d4,const float d5,const float d6,
				 const float d7,const float d8,const float d9)
		:x(d1), y(d2), z(d3),
		 w(d4), h(d5), g(d6),
		 i(d7), j(d8), k(d9){}
//Create matrix by using matrix pointer
Matrix3::Matrix3(Matrix3& mat)
	:x(mat.x), y(mat.y), z(mat.z),
	 w(mat.w), h(mat.h), g(mat.g),
	 i(mat.i), j(mat.j), k(mat.k){}
//Destructor
Matrix3::~Matrix3(){
}
//Matrix * scale
Matrix3 operator*(const Matrix3& M, const float S ){
	return Matrix3
	(M.x*S, M.y*S, M.z*S,
	 M.w*S, M.h*S, M.g*S,
	 M.i*S, M.j*S, M.k*S );
}
//Matrix * vector3D
Vector3D operator*(const Matrix3& M, const Vector3D V ){
	return Vector3D(
		(M.x*V.x + M.y*V.y + M.z*V.z), 
		(M.w*V.x + M.h*V.y + M.g*V.z),
		(M.k*V.x + M.j*V.y + M.k*V.z)
		           );
}
//Matrix * matrix
Matrix3 operator*(const Matrix3& M1,const Matrix3& M2){
	float matrix [9] =
	{
	 (M1.x*M2.x + M1.y*M2.w + M1.z*M2.i), (M1.x*M2.y + M1.y*M2.h + M1.z*M2.j), (M1.x*M2.z + M1.y*M2.g + M1.z*M2.k),
	 (M1.w*M2.x + M1.h*M2.w + M1.g*M2.i), (M1.w*M2.y + M1.h*M2.h + M1.g*M2.j), (M1.w*M2.z + M1.h*M2.g + M1.g*M2.k),
	 (M1.i*M2.x + M1.j*M2.w + M1.k*M2.i), (M1.i*M2.y + M1.j*M2.h + M1.k*M2.j), (M1.i*M2.z + M1.j*M2.g + M1.k*M2.k)
	};

	return Matrix3(matrix);
}
//Matrix + matrix
Matrix3 operator+(const Matrix3& M1,const Matrix3& M2){
	float matrix [9] =
	{
		M1.x+M2.x , M1.y+M2.y , M1.z+M2.z,
		M1.x+M2.w , M1.x+M2.h , M1.x+M2.g,
		M1.x+M2.i , M1.x+M2.j , M1.x+M2.k 
	};

	return Matrix3(matrix);
}
//Matrices determination
float Matrix3::determ(){
	return x*h*k + w*j*z + i*y*g - x*j*g - i*h*z - w*y*k;
}
//Matrices transpose
Matrix3 Matrix3::Transpose(){
	Matrix3 m(*this);

	m.x = x; m.w = y; m.i = z;
	m.y = w; m.h = h; m.j = g;
	m.z = i; m.g = j; m.k = k;
	return m;
}
//Matrices revertion
Matrix3 Matrix3::Revert()
{
	float M = determ();

	Matrix3 result(	h*k-g*j,  z*j-y*z,  y*g-z*h,
					g*i-w*z,  x*k-z*i,  z*w-x*g,
					w*j-h*i,  y*i-x*j,  x*h-y*w );
	return result*(1/M);
}
//Set orientation
void Matrix3::setOrientation(const Quaternion &q)
{
	float n = q.w*q.w + q.x*q.x + q.y*q.y + q.z*q.z;
	const float s = 2/n;
	const float wx = s * q.w * q.x; const float wy = s * q.w * q.y; const float wz = s * q.w * q.z;
	const float xx = s * q.x * q.x; const float xy = s * q.x * q.y; const float xz = s * q.x * q.z;
	const float yy = s * q.y * q.y; const float yz = s * q.y * q.z; const float zz = s * q.z * q.z;
	
	x = 1 - (yy + zz);	y = xy - wz;		z = xz + wy;
    w = xy + wz;		h = 1 - (xx + zz);	g = yz - wx; 
    i = xz - wy;        j = yz + wx;		k = 1 - (xx + yy);

}
//Override function to print matrix using "std::cout << matrix"
std::ostream & operator<<(std::ostream &out, const Matrix3 &mat3){
	out << mat3.x << "	" << mat3.y << "	" << mat3.z << std::endl
	    << mat3.w << "	" << mat3.h << "	" << mat3.g << std::endl
		<< mat3.i << "	" << mat3.j << "	" << mat3.k;
	return out;
}