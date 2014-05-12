#include <iostream>
#include "Vector2D.h"
#include "Vector3D.h"
#include "Matrix3.h"
#include "Matrix4.h"

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

	Matrix3 matrix_1(matriisi_1);
	Matrix3 matrix_2(
		2.0f , 1.0f , 1.0f,
		3.0f , 3.0f , 4.0f,
		1.0f , 2.0f , 5.0f);
	Matrix4 matrix_3(
		2.0f , 1.0f , 1.0f, 1.0f,
		3.0f , 3.0f , 4.0f, 1.0f,
		1.0f , 2.0f , 5.0f, 1.0f,
		2.0f , 1.0f , 2.0f, 1.0f);
	Matrix4 matrix_4(
		1.0f , 3.0f , 2.0f, 4.0f,
		1.0f , 1.0f , 2.0f, 2.0f,
		3.0f , 1.0f , 2.0f, 1.0f,
		1.0f , 2.0f , 2.0f, 3.0f);

	cout << "_________________VEKTORI3 LASKUT__________________" << endl;
	cout << "Vektori 1: " << vektor_1 << " Pituus: " << vektor_1.length() << endl;
	cout << "Vektori 2: " << vektor_2 << " Pituus: " << vektor_2.length() << endl;
	cout << "Summa: " << vektor_1+vektor_2 << endl;
	cout << "Erotus: " << vektor_1-vektor_2 << endl;
	cout << "Pistetulo: " << vektor_1.dot(vektor_1,vektor_2) << endl;
	cout << "Ristitulo: " << vektor_1.cross(vektor_2) << endl;
	cout << "Normalisointi: " << vektor_1.normalize() << endl;
	
	cout << "_________________MATRIISI LASKUT__________________" << endl;
	cout << "Matriisi 1: \n" << matrix_1 << endl << endl;
	cout << "Matriisi 2: \n" << matrix_2 << endl << endl;
	cout << "Summa: \n" << matrix_1 + matrix_2 << endl << endl;
	cout << "Tulo: \n" << matrix_1 * matrix_2 << endl<< endl;
	cout << "Determinantti: \n" << matrix_1.determ() << endl << endl;
	cout << "Tansponointi: \n" << matrix_2.Transpose() << endl << endl;
	cout << "Kaanteismatriisi: \n" << matrix_1.Revert() << endl << endl << endl;

	cout << "Matriisi 3 (4x4): \n" << matrix_3 << endl << endl;
	cout << "Matriisi 4 (4x4): \n" << matrix_4 << endl << endl;
	cout << "Skalaarilla kertominen: \n" << matrix_3*3 << endl << endl;
	cout << "Vektorilla kertominen: \n" << matrix_3*vektor_2 << endl << endl;
	cout << "Yhteenlasku: \n" << matrix_3+matrix_4 << endl << endl;
	cout << "Kertolasku: \n" << matrix_3*matrix_4 << endl << endl;
	cout << "Determinantti: (4x4) \n" << matrix_3.determ() << endl << endl;
	cout << "Kaanteismatriisi: (4x4) \n" << matrix_3.Inverse() << endl << endl;


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