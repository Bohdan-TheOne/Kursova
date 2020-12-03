#include "CommonMatrix.h"

using namespace std;

template<class T>
CommonMatrix<T>::CommonMatrix() {
	nRow = 0;
	nCol = 0;
	matrix = NULL;
}

template<class T>
CommonMatrix<T>::CommonMatrix(int _nRow, int _nCol) {
	nRow = _nRow;
	nCol = _nCol;
	matrix = new T * [nRow];
	for (int i = 0; i < nRow; ++i) {
		matrix[i] = new T[nCol];
		for (int j = 0; j < nCol; ++j) {
			matrix[i][j] = 0;
		}
	}
}

template<class T>
CommonMatrix<T>::CommonMatrix(T** matr, int _nRow, int _nCol) {
	nRow = _nRow;
	nCol = _nCol;
	matrix = new T * [nRow];
	for (int i = 0; i < nRow; ++i) {
		matrix[i] = new T[nCol];
		for (int j = 0; j < nCol; ++j) {
			matrix[i][j] = matr[i][j];
		}
	}
}

template<class T>
CommonMatrix<T>::CommonMatrix(const CommonMatrix& other) {
	nRow = other.nRow;
	nCol = other.nCol;
	matrix = new T * [nRow];
	for (int i = 0; i < nRow; ++i) {
		matrix[i] = new T[nCol];
		for (int j = 0; j < nCol; ++j) {
			matrix[i][j] = other.GetValue(i, j);
		}
	}
}

template<class T>
CommonMatrix<T>::~CommonMatrix() {
	if (matrix) {
		for (int i = 0; i < nRow; ++i) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
}

template<class T>
int CommonMatrix<T>::GetRowCount() const {
	return nRow;
}

template<class T>
int CommonMatrix<T>::GetColCount() const {
	return nCol;
}

template<class T>
T CommonMatrix<T>::GetValue(int row, int col) const {
	return matrix[row][col];
}

template<class T>
T*& CommonMatrix<T>::operator[](unsigned int id) {
	return matrix[id];
}

template<class T>
CommonMatrix<T> CommonMatrix<T>::operator=(CommonMatrix<T> other) {
	if (matrix) {
		for (int i = 0; i < nRow; ++i) {
			if (matrix[i])
				delete[] matrix[i];
		}
		delete[] matrix;
	}
	nRow = other.nRow;
	nCol = other.nCol; 
	matrix = new T*[nRow];
	for (int i = 0; i < nRow; ++i) {
		matrix[i] = new T[nCol];
		for (int j = 0; j < nCol; ++j) {
			matrix[i][j] = other[i][j];
		}
	}
	return *this;
}

template <typename T>
ostream& operator<<(ostream& os, const CommonMatrix<T>& matr) {
	if (!matr.matrix) {
		os << "Invalid matrix object" << endl;
		return os;
	}
	else {
		if (!matr.nRow || !matr.nCol) {
			os << "Void matrix" << endl;
		}
	}

	for (int i = 0; i < matr.nRow; ++i) {
		for (int j = 0; j < matr.nCol; ++j) {
			cout << matr.GetValue(i, j) << "  ";
		}
		cout << endl;
	}

	return os;
}
