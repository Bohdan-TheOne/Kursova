#ifndef MY_MATRIX
#define MY_MATRIX

#include<iostream>
#include <jsoncpp/json/json.h>

template <typename T> class CommonMatrix;
template <typename T> std::ostream& operator<<(std::ostream& os, const CommonMatrix<T>& matr);

// Class that describes entity of Common Matrix
template <class T> class CommonMatrix {
public:
	CommonMatrix();
	CommonMatrix(int _nRow, int _nCol);
	CommonMatrix(T** matr, int _nRow, int _nCol);
	CommonMatrix(const CommonMatrix& other);
	~CommonMatrix();

	int GetRowCount() const;	// return number of rows
	int GetColCount() const;	// return number of columns
	T GetValue(int row, int col) const;		// returns value of position

	void JsonSerialise(Json::Value& root);		// Serialise matrix to json format
	void JsonDeserialise(Json::Value& root);	// Deserialise matrix from json format

	T*& operator[](unsigned int id);
	CommonMatrix<T> operator=(CommonMatrix<T> other);
	friend std::ostream& operator<< <T>(std::ostream& os, const CommonMatrix<T>& matr);

private:
	int nRow;		// number of rows
	int nCol;		// number of columns
	T** matrix;		// 2-dimentional array to store values
};

#endif


