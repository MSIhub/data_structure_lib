#include <iostream>
#include <algorithm>
#include <assert.h>

template<class T>
class Matrix
{
private:
	int m_rows;
	int m_columns;
	T * m_elements;
public:
    Matrix():m_rows(0),m_columns(0), m_elements(nullptr){}
	Matrix(int rows_, int columns_):m_rows(rows_), m_columns(columns_)
	{
			m_elements = new T[rows_*columns_]{0};
	}
	
	//Reader and writer 
	const T& element(int r, int c) const 
	{
		int offset = r*(m_columns)+c;
		return m_elements[offset];
	}
	
	T& element(int r, int c)
	{
		int offset = r*(m_columns)+c;
		return m_elements[offset];
	}
	
	static Matrix Zero(int r, int c);
	static Matrix Ones(int r, int c);
	
	
	//operator overloading
	friend std::ostream& operator << <>(std::ostream& os, const Matrix& mat);

	~Matrix(){delete [] m_elements;}
	
};

template<class T>
Matrix<T> Matrix<T>::Zero(int r, int c)
{
	Matrix<T> mat;
    mat.m_rows = r;
    mat.m_columns = c;
    mat.m_elements = new T[r*c]{0};
	return mat;
}

template<class T>
Matrix<T> Matrix<T>::Ones(int r, int c)
{
	Matrix<T> mat;
    mat.m_rows = r;
    mat.m_columns = c;
    mat.m_elements = new T[r*c]{1};
    std::fill_n(mat.m_elements, r*c, 1);
	return mat;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& mat)
	{
		assert(mat.m_elements!=nullptr);
        assert(mat.m_rows > 0);
        assert(mat.m_columns > 0);
		os << "Matrix:\n";
		for(int i = 0; i < mat.m_rows; i++)
		{
			for(int j = 0; j < mat.m_columns; j++)
				 os << mat.m_elements[i*(mat.m_columns) +j]<< ", ";
			os << "\b\b \n";
		}
		os<< "\n";
		return os;
	}

int main()
{
	auto mat = Matrix<int>::Zero(3,4);
	std::cout << mat;
	

    auto mat1 = Matrix<int>::Ones(3,4);
	std::cout << mat1 ;
    
	return 0;
}