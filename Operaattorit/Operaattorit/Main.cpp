#include <iostream>
#include "Vector2D.h"
#include "Vector3D.h"
#include "Matrix3.h"

using namespace std;

int main(void)
{
	Vector3D vektor_1(1.f,1.f,3.f);
	Vector3D vektor_2(2.f,1.f,3.f);

	float matriisi_1[] = 
	{
		1.5f , 0.0f , 0.0f,
		0.0f , 1.2f , 0.0f,
		0.0f , 0.0f , 1.0f
	};
	float matriisi_2[] = 
	{
		2.0f , 0.0f , 0.0f,
		0.0f , 3.0f , 0.0f,
		0.0f , 0.0f , 5.0f
	};

	Matrix3 matrix_1(matriisi_1);
	Matrix3 matrix_2(matriisi_2);
	Matrix3 matrix_3(matriisi_1);
	matrix_3.Transpose();

	cout << "_________________VEKTORI3 LASKUT__________________" << endl;
	cout << "Vektori 1: " << vektor_1 << " Pituus: " << vektor_1.length() << endl;
	cout << "Vektori 2: " << vektor_2 << " Pituus: " << vektor_2.length() << endl;
	cout << "Summa: " << vektor_1+vektor_2 << endl;
	cout << "Erotus: " << vektor_1-vektor_2 << endl;
	cout << "Pistetulo: " << vektor_1.dot(vektor_1,vektor_2) << endl;
	cout << "Ristitulo: " << vektor_1.cross(vektor_2) << endl;
	cout << "Normalisointi: " << vektor_1.normalize() << endl;
	
	cout << "_________________MATRIISI LASKUT__________________" << endl;
	cout << "Matriisi 1: \n" << matrix_1 << endl<< endl;
	cout << "Matriisi 2: \n" << matrix_2 << endl<< endl;
	cout << "Summa: \n" << matrix_1 + matrix_2 << endl<< endl;
	cout << "Tulo: \n" << matrix_1 * matrix_2 << endl<< endl;
	cout << "Determinantti: \n" << matrix_1.determ(matrix_2) << endl<< endl;
	cout << "Tansponointi: \n" << matrix_3 << endl<< endl;

	//Vector2D* A = new Vector2D(1.f,2.f);
	//Vector2D* B = new Vector2D(3.f,1.f);
	//A.print();
	//B.print();

	//Vector2D C(A+B);
	//C.print();
	//C = A-B;
	//C.print();
	//C = A*3;
	//C.print();

	//float V = A*B;
	//std::cout << V << std::endl;

	return 0;
}