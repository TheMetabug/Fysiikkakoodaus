#include "Matrix3.h"


Matrix3::Matrix3(const float *data)
	:x(data[0]), y(data[1]), z(data[2]),
	 w(data[3]), h(data[4]), g(data[5]),
	 i(data[6]), j(data[7]), k(data[8]){}
Matrix3::Matrix3(Matrix3& mat)
	:x(mat.x), y(mat.y), z(mat.z),
	 w(mat.w), h(mat.h), g(mat.g),
	 i(mat.i), j(mat.j), k(mat.k){}
Matrix3::~Matrix3(){
}
Vector3D operator*(const Matrix3& M, const Vector3D V ){
	return Vector3D(
		(M.x*V.x + M.y*V.y + M.z*V.z), 
		(M.w*V.x + M.h*V.y + M.g*V.z),
		(M.k*V.x + M.j*V.y + M.k*V.z)
		           );
}
Matrix3 operator*(const Matrix3& M1,const Matrix3& M2){
	float matrix [9] =
	{
	 (M1.x*M2.x + M1.y*M2.w + M1.z*M2.i), (M1.x*M2.y + M1.y*M2.h + M1.z*M2.j), (M1.x*M2.z + M1.y*M2.g + M1.z*M2.k),
	 (M1.w*M2.x + M1.h*M2.w + M1.g*M2.i), (M1.w*M2.y + M1.h*M2.h + M1.g*M2.j), (M1.w*M2.z + M1.h*M2.g + M1.g*M2.k),
	 (M1.i*M2.x + M1.j*M2.w + M1.k*M2.i), (M1.i*M2.y + M1.j*M2.h + M1.k*M2.j), (M1.i*M2.z + M1.j*M2.g + M1.k*M2.k)
	};

	return Matrix3(matrix);
}
Matrix3 operator+(const Matrix3& M1,const Matrix3& M2){
	float matrix [9] =
	{
		M1.x+M2.x , M1.y+M2.y , M1.z+M2.z,
		M1.x+M2.w , M1.x+M2.h , M1.x+M2.g,
		M1.x+M2.i , M1.x+M2.j , M1.x+M2.k 
	};

	return Matrix3(matrix);
}
Vector3D Matrix3::determ(Matrix3&){
	return Vector3D(
					x*(h*k-g*j),
					y*(w*k-g*i),
					z*(w*j-h*i)
					);
}
void Matrix3::Transpose(){
	Matrix3 m(*this);

	x = m.x; y = m.w; z = m.i;
	w = m.y; h = m.h; g = m.j;
	i = m.z; j = m.g; k = m.k;
}
std::ostream & operator<<(std::ostream &out, const Matrix3 &mat3){
	out << mat3.x << "	" << mat3.y << "	" << mat3.z << std::endl
	    << mat3.w << "	" << mat3.h << "	" << mat3.g << std::endl
		<< mat3.i << "	" << mat3.j << "	" << mat3.k;
	return out;
}