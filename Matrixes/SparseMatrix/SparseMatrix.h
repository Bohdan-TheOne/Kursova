#ifndef SPARSE_MATRIX
#define SPARSE_MATRIX

#include <iostream>
#include <jsoncpp/json/json.h>

using namespace std;

// Class that describes entity of Sparse Matrix Element
template <class T> class SparseMatrixNode {
public:
	SparseMatrixNode();
	SparseMatrixNode(int _row, int _col, T _val);
	SparseMatrixNode(const SparseMatrixNode& other);
	void SetNode(int _row, int _col, T _val);	// Set all members of Node
	void SetCords(int _row, int _col);		// Set coordinates of Node
	void SetValue(T _val);		// Set value of Node
	int GetRow() const;		// return node row index
	int GetCol() const;		// return node column index
	T GetValue() const;		// return node value

	void JsonSerialise(Json::Value& root) const;		// Serialise node to json format
	void JsonDeserialise(Json::Value& root);	// Deserialise node form json format

	SparseMatrixNode<T> operator=(SparseMatrixNode<T> other);

	SparseMatrixNode<T>* next;	// pointer to next value
private:
	int row;	// row index
	int col;	// column index
	T value;	// node value
};

template <typename T> class SparseMatrix;	// Create operator overload prototype
template <typename T> ostream& operator<<(ostream& os, const SparseMatrix<T>& matr);

// Class that describes entity of Sparse Matrix
template <class T> class SparseMatrix {
public:
	SparseMatrix();
	SparseMatrix(SparseMatrixNode<T>* first);
	SparseMatrix(SparseMatrixNode<T>* first, int rowCount, int colCount);
	SparseMatrix(int rowCount, int colCount);
	SparseMatrix(const SparseMatrix& other);
	~SparseMatrix();

	int GetLength() const;		// return number of non-zero elements
	int GetRowCount() const;	// return number of rows
	int GetColCount() const;	// return number of columns
	const SparseMatrixNode<T>* GetFirst() const;	// returns pointer to first element
	void insert(SparseMatrixNode<T> newElem);	// add new non-zero value to matrix
	SparseMatrix<T> transpose() const;		// return transposed matrix
	void clearMatrix();			// clear data list

	void JsonSerialise(Json::Value& root) const;		// Serialise matrix to json format
	void JsonDeserialise(Json::Value& root);	// Deserialise matrix from json format

	SparseMatrix<T> operator=(SparseMatrix<T> other);
	SparseMatrix<T> operator+(SparseMatrix<T>& other);
	SparseMatrix<T> operator*(SparseMatrix<T>& other);
	friend std::ostream& operator<< <T>(std::ostream& os, const SparseMatrix<T>& matr);

private:
	SparseMatrixNode<T>* start;	// Pointer to first element in list
	int length;		// number of non-zero elements
	int nRow;		// number of rows
	int nCol;		// number of columns
};

#endif
