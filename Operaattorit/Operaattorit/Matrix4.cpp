#include "Matrix4.h"

//Create matrix by using float[]
Matrix4::Matrix4(const float *data)
	:a(data[0]), b(data[1]), c(data[2]), d(data[3]),
	 e(data[4]), f(data[5]), g(data[6]), h(data[7]),
	 i(data[8]), j(data[9]), k(data[10]),l(data[11]),
	 m(data[12]),n(data[13]),o(data[14]),p(data[15])
{}
Matrix4::Matrix4(const float d1, const float d2, const float d3, const float d4,
		         const float d5, const float d6, const float d7, const float d8,
				 const float d9, const float d10,const float d11,const float d12,
				 const float d13,const float d14,const float d15,const float d16)
			:a(d1), b(d2), c(d3), d(d4),
			 e(d5), f(d6), g(d7), h(d8),
			 i(d9), j(d10),k(d11),l(d12),
			 m(d13),n(d14),o(d15),p(d16){}
Matrix4::Matrix4(Matrix4& m)
	:a(m.a), b(m.b), c(m.c), d(m.d),
	 e(m.e), f(m.f), g(m.g), h(m.h),
	 i(m.i), j(m.j), k(m.k), l(m.l),
	 m(m.m), n(m.n), o(m.o), p(m.p){}
Matrix4::~Matrix4(){}
Matrix4 operator+(const Matrix4& M,const Matrix4& W){
	return Matrix4( M.a+W.a, M.b+W.b, M.c+W.c, M.d+W.d,
					M.e+W.e, M.f+W.f, M.g+W.g, M.h+W.h,
					M.i+W.i, M.j+W.j, M.k+W.k, M.l+W.l,
					M.m+W.m, M.n+W.n, M.o+W.o, M.p+W.p);
}
Matrix4 operator*(const Matrix4& M, const float S ){
	return Matrix4( M.a*S, M.b*S, M.c*S, M.d*S,
					M.e*S, M.f*S, M.g*S, M.h*S,
					M.i*S, M.j*S, M.k*S, M.l*S,
					M.m*S, M.n*S, M.o*S, M.p*S);
}
Vector3D operator*(const Matrix4& M, const Vector3D W ){
	return Vector3D((M.a*W.x + M.b*W.y + M.c*W.z + M.d),
					(M.e*W.x + M.f*W.y + M.g*W.z + M.h),
					(M.i*W.x + M.j*W.y + M.k*W.z + M.l));
}
Matrix4 operator*(const Matrix4& M,const Matrix4& W){
	return Matrix4( (M.a*W.a + M.b*W.e + M.c*W.i + M.d*W.m), (M.a*W.b + M.b*W.f + M.c*W.j + M.d*W.n), (M.a*W.c + M.b*W.g + M.c*W.k + M.d*W.o), (M.a*W.d + M.b*W.h + M.c*W.l + M.d*W.p),
					(M.a*W.a + M.b*W.e + M.c*W.i + M.d*W.m), (M.a*W.b + M.b*W.f + M.c*W.j + M.d*W.n), (M.a*W.c + M.b*W.g + M.c*W.k + M.d*W.o), (M.a*W.d + M.b*W.h + M.c*W.l + M.d*W.p),
					(M.a*W.a + M.b*W.e + M.c*W.i + M.d*W.m), (M.a*W.b + M.b*W.f + M.c*W.j + M.d*W.n), (M.a*W.c + M.b*W.g + M.c*W.k + M.d*W.o), (M.a*W.d + M.b*W.h + M.c*W.l + M.d*W.p),
					(M.a*W.a + M.b*W.e + M.c*W.i + M.d*W.m), (M.a*W.b + M.b*W.f + M.c*W.j + M.d*W.n), (M.a*W.c + M.b*W.g + M.c*W.k + M.d*W.o), (M.a*W.d + M.b*W.h + M.c*W.l + M.d*W.p));
}
float Matrix4::determ(){
	return ( a*f*k*p-a*f*l*o-a*g*j*p+a*g*l*n+a*h*j*o-a*h*k*n
			-b*e*k*p+b*e*l*o+b*g*i*p-b*g*l*m-b*h*i*o+b*h*k*m
			+c*e*j*p-c*e*l*n-c*f*i*p+c*f*l*m+c*h*i*n-c*h*j*m
			-d*e*j*o+d*e*k*n+d*f*i*o-d*f*k*m-d*g*i*n+d*g*j*m);
}
Matrix4 Matrix4::Inverse(){
	
	float D = determ();
	return Matrix4(	
			-h*k*n+g*l*n+h*j*o-f*l*o-g*j*p+f*k*p,d*k*n-c*l*n-d*j*o+b*l*o+c*j*p-b*k*p,-d*g*n+c*h*n+d*f*o-b*h*o-c*f*p+b*g*p,d*g*j-c*h*j-d*f*k+b*h*k+c*f*l-b*g*l,
			h*k*m-g*l*m-h*i*o+e*l*o+g*i*p-e*k*p,-d*k*m+c*l*m+d*i*o-a*l*o-c*i*p+a*k*p,d*g*m-c*h*m-d*e*o+a*h*o+c*e*p-a*g*p,-d*g*i+c*h*i+d*e*k-a*h*k-c*e*l+a*g*l,
			-h*j*m+f*l*m+h*i*n-e*l*n-f*i*p+e*j*p,d*j*m-b*l*m-d*i*n+a*l*n+b*i*p-a*j*p,-d*f*m+b*h*m+d*e*n-a*h*n-b*e*p+a*f*p,d*f*i-b*h*i-d*e*j+a*h*j+b*e*l-a*f*l,
			g*j*m-f*k*m-g*i*n+e*k*n+f*i*o-e*j*o,-c*j*m+b*k*m+c*i*n-a*k*n-b*i*o+a*j*o,c*f*m-b*g*m-c*e*n+a*g*n+b*e*o-a*f*o,-c*f*i+b*g*i+c*e*j-a*g*j-b*e*k+a*f*k
			)*(1/D);
}
std::ostream & operator<<(std::ostream &out, const Matrix4 &mat4){
	out << mat4.a << "	" << mat4.b << "	" << mat4.c << "	" << mat4.d << std::endl
	    << mat4.e << "	" << mat4.f << "	" << mat4.g << "	" << mat4.h << std::endl
	    << mat4.i << "	" << mat4.j << "	" << mat4.k << "	" << mat4.l << std::endl
		<< mat4.m << "	" << mat4.n << "	" << mat4.o << "	" << mat4.p;
	return out;
}