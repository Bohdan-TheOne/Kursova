#include "CommonMatrix.h"

using namespace std;

template<class T>	// Initialise default values
CommonMatrix<T>::CommonMatrix() {
	nRow = 0;
	nCol = 0;
	matrix = NULL;
}

template<class T>	// Allocate memory for NxM matrix
CommonMatrix<T>::CommonMatrix(int _nRow, int _nCol) {
	nRow = _nRow;
	nCol = _nCol;
	matrix = new T * [nRow];
	for (int i = 0; i < nRow; ++i) {
		matrix[i] = new T[nCol];
		for (int j = 0; j < nCol; ++j) {
			matrix[i][j] = 0;	// initialise with zero elements
		}
	}
}

template<class T>	// Initialise with two dimentional array
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

template<class T>	// Copy constructor
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

template<class T>	// Free allocated memory
CommonMatrix<T>::~CommonMatrix() {
	if (matrix) {
		for (int i = 0; i < nRow; ++i) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
}

template<class T>	// return number of rows
int CommonMatrix<T>::GetRowCount() const {
	return nRow;
}

template<class T>	// return number of columns
int CommonMatrix<T>::GetColCount() const {
	return nCol;
}

template<class T>	// returns value of position
T CommonMatrix<T>::GetValue(int row, int col) const {
	return matrix[row][col];
}

template<class T>	// Serialise matrix to json format
void CommonMatrix<T>::JsonSerialise(Json::Value& root) {
	if (matrix) {
		root["rowNumber"] = nRow;
		root["columnNumber"] = nCol;
		for (int i = 0; i < nRow; ++i) {
			for (int j = 0; j < nCol; ++j) {
				root["data"][i][j] = matrix[i][j];
			}
		}
	}
}

template<class T>	// Deserialise matrix from json format
void CommonMatrix<T>::JsonDeserialise(Json::Value& root) {
	if (matrix) {	// if matrix already existed
		for (int i = 0; i < nRow; ++i) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
	nRow = root.get("rowNumber", 0).asInt();
	nCol = root.get("columnNumber", 0).asInt();
	matrix = new T * [nRow];
	for (int i = 0; i < nRow; ++i) {
		matrix[i] = new T[nCol];
		for (int j = 0; j < nCol; ++j) {
			matrix[i][j] = root.get("data", 0)[i][j].asDouble();
		}
	}
}

template<class T>	// overload subscript opreator
T*& CommonMatrix<T>::operator[](unsigned int id) {
	return matrix[id];
}

template<class T>	// overload assignment oprator
CommonMatrix<T> CommonMatrix<T>::operator=(CommonMatrix<T> other) {
	if (matrix) {	// if matrix already existed
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

template <typename T>	// overload output operator
ostream& operator<<(ostream& os, const CommonMatrix<T>& matr) {
	if (!matr.matrix) {	// Check if matrix exists
		os << "Invalid matrix object" << endl;
		return os;
	}
	else {	// check if matrix has elements
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