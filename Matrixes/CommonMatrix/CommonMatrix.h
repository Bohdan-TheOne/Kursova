#ifndef MY_MATRIX
#define MY_MATRIX

#include<iostream>

template <typename T> class CommonMatrix;
template <typename T> std::ostream& operator<<(std::ostream& os, const CommonMatrix<T>& matr);

template <class T> class CommonMatrix
{
public:
	CommonMatrix();
	CommonMatrix(int _nRow, int _nCol);
	CommonMatrix(T** matr, int _nRow, int _nCol);
	CommonMatrix(const CommonMatrix& other);
	~CommonMatrix();

	int GetRowCount() const;
	int GetColCount() const;
	T GetValue(int row, int col) const;

	T*& operator[](unsigned int id);
	CommonMatrix<T> operator=(CommonMatrix<T> other);
	friend std::ostream& operator<< <T>(std::ostream& os, const CommonMatrix<T>& matr);

private:
	int nRow;
	int nCol;
	T** matrix;
};

#endif


