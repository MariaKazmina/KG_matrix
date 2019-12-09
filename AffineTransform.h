#ifndef AFFINE_TRANSFORM_H
#define AFFINE_TRANSFORM_H
#include<math.h>

Matrix<> Translation(double x, double y)
{
	double T[9] = {
		1, 0, x,
		0, 1, y,
		0, 0, 1};
	return Matrix<>(3, 3, T);
}

// Здесь требуется реализовать функции, возвращающие матрицы базовых АП:
// Identity() - тождественное АП;
// Rotation(t) - поворот на угол t;
// Rotation(c, s) - поворот на угол, косинус и синус которого пропорциональны величинам c и s;
// Scaling(kx, ky) - масштабирование;
// Mapping (различные виды отражений) - по желанию, для создания матриц отражения можно использовать функцию Scaling.

// В приведённом примере используется конструктор матрицы из списка.
// Приветствуются идеи о других способах создания матриц.
// Например, вызов функции, создающей единичную матрицу,
// с последующим переопределением некоторых её коэффициентов.



Matrix<> Rotation(double t)
{
	double R[9] =
	{
		cos(t), -sin(t), 0,
		sin(t), cos(t), 0,
		0, 0 ,1
	};
	return Matrix<>(3, 3, R);

}

Matrix<> Rotation(double c, double s)
{
	double t = 0;
	double val = c*c + s *s;
	double val1 = c / sqrt(val);
	double val2 = s / sqrt(val);
	double R[9] =
	{
		val1, -val2, 0,
		val2, val1, 0,
		0, 0 ,1
	};
	return Matrix<>(3, 3, R);

}

Matrix<> Scaling(double kx, double ky)
{
	double S[9]
	{
		kx, 0, 0,
		0, ky, 0,
		0, 0, 1

	};
	return Matrix<>(3, 3, S);

}

Matrix<> MappingX()
{
	double Mx[9] =
	{
		1, 0, 0,
		0, -1, 0,
		0, 0, 1
	};
	return Matrix<>(3, 3, Mx);

}

Matrix<> MappingY()
{
	double My[9] =
	{
		-1, 0, 0,
		0, 1, 0,
		0, 0, 1
	};
	return Matrix<>(3, 3, My);

}

Matrix<> Mappingo()
{
	double M0[9] =
	{
		-1, 0, 0,
		0, -1, 0,
		0, 0, 1
	};
	return Matrix<>(3, 3, M0);

}


#endif AFFINE_TRANSFORM_H
