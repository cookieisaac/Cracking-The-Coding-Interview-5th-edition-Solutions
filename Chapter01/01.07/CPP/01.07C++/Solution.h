#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <fstream>
class Matrix
{
public:
	Matrix(int M, int N);
	~Matrix();
	void setZeros();

	friend std::ostream& operator<< (std::ostream& os, const Matrix& matrix);
	friend std::istream& operator>> (std::istream& os, Matrix& matrix);
private:
	int m_M;
	int m_N;
	int** m_matrix;
};

#endif