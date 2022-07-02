#include "../include/matrix.h"

template <class T>
Matrix<T> Matrix<T>::Zero(int r, int c)
{
	Matrix<T> mat;
	mat.m_rows = r;
	mat.m_columns = c;
	mat.m_elements = new T[r * c]{0};
	return mat;
}

template <class T>
Matrix<T> Matrix<T>::Ones(int r, int c)
{
	Matrix<T> mat;
	mat.m_rows = r;
	mat.m_columns = c;
	mat.m_elements = new T[r * c]{1};
	std::fill_n(mat.m_elements, r * c, 1);
	return mat;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const Matrix<T> &mat)
{
	assert(mat.m_elements != nullptr);
	assert(mat.m_rows > 0);
	assert(mat.m_columns > 0);
	os << "Matrix:\n";
	for (int i = 0; i < mat.m_rows; i++)
	{
		for (int j = 0; j < mat.m_columns; j++)
			os << mat.m_elements[i * (mat.m_columns) + j] << ", ";
		os << "\b\b \n";
	}
	os << "\n";
	return os;
}

bool matrix_test()
{
	auto mat = Matrix<int>::Zero(3, 4);
	std::cout << mat;

	auto mat1 = Matrix<int>::Ones(3, 4);
	std::cout << mat1;

	return true;
}