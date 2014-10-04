#include "Solution.h"
#include <vector>
using namespace std;

Matrix::Matrix(int M, int N)
{
	m_M = M;
	m_N = N;

	m_matrix = (int**)malloc(sizeof(int) * m_M);
	for (int i = 0; i < m_M; i++)
	{
		m_matrix[i] = (int*)malloc(sizeof(int)* m_N);
	}
}
	

Matrix::~Matrix()
{
	for (int i = 0; i < m_M; i++)
	{
		free(m_matrix[i]);
	}
	free(m_matrix);
}

std::ostream& operator<< (std::ostream& os, const Matrix& matrix)
{
	for (int i = 0, j; i < matrix.m_M; i++)
	{
		for (j = 0; j < matrix.m_N - 1; j++)
		{
			os << matrix.m_matrix[i][j] << '\t';
		}
		os << matrix.m_matrix[i][j] << endl;
	}
	return os;
}

std::istream& operator>> (std::istream& os, Matrix& matrix)
{
	for (int i = 0; i < matrix.m_M; i++)
	{
		for (int j = 0; j < matrix.m_N; j++)
		{
			os >> matrix.m_matrix[i][j];
		}
	}
	return os;
}


void Matrix::setZeros()
{
	vector<int> rows;
	vector<int> cols;

	for (int i = 0; i < m_M; i++)
	{
		for (int j = 0; j < m_N; j++)
		{
			if (m_matrix[i][j] == 0)
			{
				rows.push_back(i);
				cols.push_back(j);
			}
		}

		for (std::vector<int>::size_type i = 0; i != rows.size(); i++)
		{
			for (int j = 0; j < m_N; j++)
			{
				m_matrix[rows[i]][j] = 0;
			}
		}

		for (std::vector<int>::size_type j = 0; j != cols.size(); j++)
		{
			for (int i = 0; i < m_M; i++)
			{
				m_matrix[i][cols[j]] = 0;
			}
		}
	}
}