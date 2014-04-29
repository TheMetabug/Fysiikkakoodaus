#include "Vector3D.h"
#include <math.h>

Vector3D::Vector3D(){
}
Vector3D::Vector3D(const Vector3D& vec3)
	:x(vec3.x),
	 y(vec3.y),
	 z(vec3.z){
}
Vector3D::Vector3D(float X, float Y, float Z)
	:x(X),
	 y(Y),
	 z(Z){
}
Vector3D::~Vector3D(){
}
Vector3D operator+(const Vector3D &v1,const Vector3D &v2)	{
	return Vector3D(v1.x+v2.x,v1.y+v2.y,v1.z+v2.z);
}
Vector3D operator-(const Vector3D &v1,const Vector3D &v2){
	return Vector3D(v1.x-v2.x,v1.y-v2.y,v1.z-v2.z);
}
Vector3D operator*(const float scale,const Vector3D &vec3){
	return Vector3D(vec3.x*scale,vec3.y*scale,vec3.z*scale);
}
Vector3D& Vector3D::operator+=(Vector3D &vec3){
	x += vec3.x;
	y += vec3.y;
	z += vec3.z;
	
	return *this;
}
Vector3D& Vector3D::operator-=(Vector3D &vec3){
	x -= vec3.x;
	y -= vec3.y;
	z -= vec3.z;
	
	return *this;
}
Vector3D& Vector3D::operator*=(float scale){
	x *= scale;
	y *= scale;
	z *= scale;

	return *this;
}
float Vector3D::dot(const Vector3D &v1,const Vector3D &v2)	{
	return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
}
Vector3D Vector3D::cross(const Vector3D &v2)	{
	return Vector3D((y*v2.z - z*v2.y),(z*v2.x - x*v2.z),(x*v2.y - y*v2.x));
}
Vector3D& Vector3D::normalize(){
	const float len = length();
	x/=len;
	y/=len;
	z/=len;

	return *this;
}	
float Vector3D::length(){
	return sqrt(dot(*this,*this));
}
std::ostream & operator<<(std::ostream &out, const Vector3D &vec3){
	out << vec3.x << " " << vec3.y << " " << vec3.z;
	return out;
}