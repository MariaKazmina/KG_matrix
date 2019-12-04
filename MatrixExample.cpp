#include "Matrix.h"
#include "AffineTransform.h"

using namespace std;

void main()
{
/*
	Matrix<int> M(2);
	cout << "Input M ->\n ";
	cin >> M;
*/
	double a[6] = {1, -2, 3, 0, 0, 2};
	Matrix<> A(3, 2, a);

	double b[6] = {2, 2, 0, 1, 0, 2};
	Matrix<> B(3,2, b);

	Matrix<> C = A+B;
	cout
		<< endl << "A =" << endl << A
		<< endl << "B =" << endl << B
	    << endl << "C =" << endl << C;
	
		/*<< endl << "A+B =" << endl << (A+B)
		<< endl << "A-B =" << endl << (A-B)
		<< endl << "T(1,2) =" << endl << Translation(1, 2);*/

	system("pause");
}
