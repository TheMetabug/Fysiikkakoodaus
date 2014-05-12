#include "Quaternion.h"
using namespace std;
//Constructor
Quaternion::Quaternion(const float w,const float x,const float y,const float z)
	:w(w),x(x),y(y),z(z){}
//Desctructor
Quaternion::~Quaternion(){}
//Multiply
float operator*(const Quaternion &q,const Quaternion &k){
	return   (q.w*k.w - q.x*k.x - q.y*k.y - q.z*q.z)
			+(q.w*k.x + q.x*k.w + q.y*k.z + q.z*k.y)
			+(q.w*k.y + q.x*k.z + q.y*k.w + q.z*k.x)
			+(q.w*k.z + q.x*k.y + q.y*k.x + q.z*k.w);
}
//Sum
Quaternion operator+(const Quaternion &q,const Quaternion &k){
	return Quaternion(	q.w+k.w,
						q.x+k.x,
						q.y+k.y,
						q.z+k.z);
}
//Minus
Quaternion operator-(const Quaternion &q,const Quaternion &k){
	return Quaternion(	q.w-k.w,
						q.x-k.x,
						q.y-k.y,
						q.z-k.z);
}
//Normalize
float Quaternion::normalize(){
	float length = sqrt(x*x + y*y + z*z + w*w);
	float M = (1 / length);
	x *= M;
	y *= M;
	z *= M;
	w *= M;
}
//Rotate vector
Quaternion Quaternion::rotateVec(const Vector3D &v,const float angle){
	//Halve the angle
	float halv = angle * 0.5f;
	//Same for the sin
	float sin_halv = sin(halv);

	x = x*sin_halv;
	y = y*sin_halv;
	z = z*sin_halv;
	w = cos(halv);
}
//Print
std::ostream & operator<<(std::ostream &out, const Quaternion &q){
	out << q.w << "w " << q.x << "i " << q.y << "j " << q.z << "k" << endl;
	return out;
}