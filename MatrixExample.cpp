#include "Matrix.h"
#include "AffineTransform.h"
#include <cmath>

using namespace std;

void main()
{
/*
	Matrix<int> M(2);
	cout << "Input M ->\n ";
	cin >> M;
*/
	double q[9] = { 1, -2, 3, 0, 0, 2, 0, 3, 2 };
	Matrix<> Q(3, 3, q);

	double a[6] = {1, -2, 3, 0, 0, 2};
	Matrix<> A(2, 3, a);

	double b[6] = {2, 2, 0, 1, 0, 2};
	Matrix<> B(3,2, b);

	Matrix<> C = A*B;
	cout
		<< endl << "A =" << endl << A
		<< endl << "B =" << endl << B
	    << endl << "C =" << endl << C
	
		/*<< endl << "A+B =" << endl << (A+B)
		<< endl << "A-B =" << endl << (A-B)*/
		<< endl << "T(1,2) =" << endl << Translation(1, 2)
		<< endl << "R(1) =" << endl << Rotation(1)
		<< endl << "R(1,2) =" << endl << Rotation(1,2);


	system("pause");
}
