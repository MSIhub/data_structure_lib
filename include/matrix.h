#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <algorithm>
#include <assert.h>

template <class T>
class Matrix
{
private:
    int m_rows;
    int m_columns;
    T *m_elements;

public:
    Matrix() : m_rows(0), m_columns(0), m_elements(nullptr) {}
    Matrix(int rows_, int columns_) : m_rows(rows_), m_columns(columns_)
    {
        m_elements = new T[rows_ * columns_]{0};
    }

    // Reader and writer
    const T &element(int r, int c) const
    {
        int offset = r * (m_columns) + c;
        return m_elements[offset];
    }

    T &element(int r, int c)
    {
        int offset = r * (m_columns) + c;
        return m_elements[offset];
    }

    static Matrix Zero(int r, int c);
    static Matrix Ones(int r, int c);

    // operator overloading
    friend std::ostream &operator<< <>(std::ostream &os, const Matrix &mat);

    ~Matrix() { delete[] m_elements; }
};

bool matrix_test();

#endif