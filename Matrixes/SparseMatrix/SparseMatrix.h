#ifndef SPARSE_MATRIX
#define SPARSE_MATRIX
#include<iostream>
#include <jsoncpp/json/json.h>

using namespace std;

template <class T> class SparseMatrixNode
{
public:
	SparseMatrixNode();
	SparseMatrixNode(int _row, int _col, T _val);
	SparseMatrixNode(const SparseMatrixNode& other);
	void SetNode(int _row, int _col, T _val);
	void SetCords(int _row, int _col);
	void SetValue(T _val);
	int GetRow() const;
	int GetCol() const;
	T GetValue() const;

	void JsonSerialise(Json::Value& root);
	void JsonDeserialise(Json::Value& root);

	SparseMatrixNode<T> operator=(SparseMatrixNode<T> other);

	SparseMatrixNode<T>* next;
private:
	int row;
	int col;
	T value;
};

template <typename T> class SparseMatrix;
template <typename T> ostream& operator<<(ostream& os, const SparseMatrix<T>& matr);

template <class T> class SparseMatrix
{
public:
	SparseMatrix();
	SparseMatrix(SparseMatrixNode<T>* first);
	SparseMatrix(SparseMatrixNode<T>* first, int rowCount, int colCount);
	SparseMatrix(int rowCount, int colCount);
	SparseMatrix(const SparseMatrix& other);
	~SparseMatrix();

	int GetLength() const;
	int GetRowCount() const;
	int GetColCount() const;
	const SparseMatrixNode<T>* GetFirst() const;
	void insert(SparseMatrixNode<T> newElem);
	SparseMatrix<T> transpose() const;

	void JsonSerialise(Json::Value& root);
	void JsonDeserialise(Json::Value& root);

	SparseMatrix<T> operator=(SparseMatrix<T> other);
	SparseMatrix<T> operator+(SparseMatrix<T>& other);
	SparseMatrix<T> operator*(SparseMatrix<T>& other);
	friend std::ostream& operator<< <T>(std::ostream& os, const SparseMatrix<T>& matr);

private:
	SparseMatrixNode<T>* start;
	int length;
	int nRow;
	int nCol;
};

#endif
