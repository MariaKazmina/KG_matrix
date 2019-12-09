#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

using namespace std;


template <typename Cell = double>
class Matrix
{
private:
	int column;
	int row;
	Cell **cells;
	void AllocateCells(int, int);
	void FreeCells();
public:
	Matrix() : column(0), row(0), cells(nullptr) {}	// Конструктор по умолчанию
	Matrix(const Matrix&);					// Конструктор копирования
	Matrix(int, int);							// Конструктор нулевой матрицы
	Matrix(int, int, Cell*);						// Конструктор матрицы из списка
	~Matrix();								// Деструктор

	Cell &operator()(int i, int j) { return cells[i-1][j-1]; }
	
	Matrix& operator = (const Matrix&);		// Перегрузка оператора присваивания
	Matrix  operator + (const Matrix&);		// Сложение матриц
	Matrix  operator - (const Matrix&);		// Вычитание матриц
	Matrix  operator * (const Matrix&);		// Умножение матриц

	friend istream& operator >> <> (istream&, Matrix&);			// Перегрузка оператора >> для ввода матрицы
	friend ostream& operator << <> (ostream&, const Matrix&);	// Перегрузка оператора << для вывода матрицы
};


template <typename Cell>
Matrix<Cell>::Matrix(const Matrix<Cell>& M)
{
	AllocateCells(M.column, M.row);
	for (int i=0; i<column; i++)
	for (int j=0; j<row; j++)
		cells[i][j] = M.cells[i][j];
}

template <typename Cell>
Matrix<Cell>::Matrix(int Column, int Row)
{
	AllocateCells(Column, Row);
	for (int i=0; i<column; i++)
	for (int j=0; j<row; j++)
		cells[i][j] = 0;
}

template <typename Cell>
Matrix<Cell>::Matrix(int Column, int Row, Cell* list)
{
	AllocateCells(Column, Row);
	int k = 0;

	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++) {
			
			cells[i][j] = list[k];
			
			k++;
		}
	}
	
}

template <typename Cell>
Matrix<Cell>::~Matrix()
{
	FreeCells();
}

template <typename Cell>
Matrix<Cell>& Matrix<Cell>::operator=(const Matrix& M)
{
	if ( column != M.column )
	{
		FreeCells();
		AllocateCells(M.column, M.row);
	}
	for (int i=0; i<column; i++)
	for (int j=0; j<row; j++)
		cells[i][j] = M.cells[i][j];
	return *this;
}

template <typename Cell>
Matrix<Cell> Matrix<Cell>::operator+(const Matrix& M)
{
	Matrix<Cell> res(*this);
	if (( column == M.column ) && (row == M.row))
	{
		for (int i = 0; i < column; i++)
			for (int j = 0; j < row; j++)
			{
				//cout << "i: " << i << " ";
				//cout << "j: " << j << " ";
				res.cells[i][j] += M.cells[i][j];
				//cout << " " << res.cells[i][j] << endl;
			}
	}
	return res;
}

template <typename Cell>
Matrix<Cell> Matrix<Cell>::operator-(const Matrix& M)
{
	Matrix<Cell> res(*this);
	if (column == M.column)
	{
		for (int i = 0; i<column; i++)
			for (int j = 0; j<row; j++)
				res.cells[i][j] -= M.cells[i][j];
	}
	return res;
	
}

template <typename Cell>
Matrix<Cell> Matrix<Cell>::operator*(const Matrix& M)
{
	Matrix<> res(column,M.row);
	if (M.column == row) {
		for (int i = 0; i < M.row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				for (int k = 0; k < M.column; k++)
					res.cells[i][j] += cells[i][k] * M.cells[k][j];

			}
		}
	}
	return res;
}

template <typename Cell>
void Matrix<Cell>::AllocateCells(int Column, int Row)
{
	cells = new Cell*[Column];
	for (int i = 0; i<Column; i++)
		cells[i] = new Cell[Row];
	column = Column;
	row = Row;
}

template <typename Cell>
void Matrix<Cell>::FreeCells()
{
	for (int i=0; i<column; i++)
		delete cells[i];
	delete cells;
	column = 0;
}

template <typename Cell>
istream& operator >> (istream& fi, Matrix<Cell>& M)
{
	for (int i=0; i<M.column; i++)
	for (int j=0; j<M.row; j++)
		fi >> M.cells[i][j];
	return fi;
}

template <typename Cell>
ostream& operator << (ostream& fo, const Matrix<Cell>& M)
{
	for (int i=0; i<M.column; i++)
	{
		fo << "  ";
		for (int j=0; j<M.row; j++)
			fo << M.cells[i][j] << " \t";
		fo << endl;
	}
	return fo;
}

#endif MATRIX_H
