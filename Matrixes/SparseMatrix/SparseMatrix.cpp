#include "SparseMatrix.h"

template<class T>
inline SparseMatrixNode<T>::SparseMatrixNode() {	// Initialise default values
	row = 0;
	col = 0;
	value = 0;
	next = NULL;
}

template<class T>
SparseMatrixNode<T>::SparseMatrixNode(int _row, int _col, T _val) { // Initialise with defined values
	row = _row;
	col = _col;
	value = _val;
	next = NULL;
}

template<class T>
SparseMatrixNode<T>::SparseMatrixNode(const SparseMatrixNode& other) {	// Copy constructor
	row = other.row;
	col = other.col;
	value = other.value;
	next = NULL;
}

template<class T>	// Set all members of Node
void SparseMatrixNode<T>::SetNode(int _row, int _col, T _val) {
	row = _row;
	col = _col;
	value = _val;
}

template<class T>	// Set coordinates of Node
void SparseMatrixNode<T>::SetCords(int _row, int _col) {
	row = _row;
	col = _col;
}

template<class T>	// Set value of Node
void SparseMatrixNode<T>::SetValue(T _val) {
	value = _val;
}

template<class T>	// return node row index
int SparseMatrixNode<T>::GetRow() const {
	return row;
}

template<class T>	// return node column index
int SparseMatrixNode<T>::GetCol() const {
	return col;
}

template<class T>	// return node value
T SparseMatrixNode<T>::GetValue() const {
	return value;
}

template<class T>	// Serialise node to json format
void SparseMatrixNode<T>::JsonSerialise(Json::Value& root) const {
	root["row"] = row;
	root["col"] = col;
	root["value"] = value;
}

template<class T>	// Deserialise node form json format
void SparseMatrixNode<T>::JsonDeserialise(Json::Value& root) {	
	row = root.get("row", 0).asInt();
	col = root.get("col", 0).asInt();
	value = root.get("value", 0).asDouble();
}

template<class T>	// Assign operator overload
SparseMatrixNode<T> SparseMatrixNode<T>::operator=(SparseMatrixNode<T> other) {
	row = other.row;
	col = other.col;
	value = other.value;
	next = other.next;
	return *this;
}

template<class T>	// Initialise default values
inline SparseMatrix<T>::SparseMatrix() {
	length = 0;
	nRow = 0;
	nCol = 0;
	start = nullptr;
}

template<class T>	// Initialise with pointer to first element of list
inline SparseMatrix<T>::SparseMatrix(SparseMatrixNode<T>* first) {
	start = first;
	length = 0;

	// determine row and column count
	int maxRow = 0, maxCol = 0;
	SparseMatrixNode<T>* ptr = first;
	while (ptr) {
		++length;
		if (maxRow < ptr->GetRow()) {
			maxRow = ptr->GetRow();
		}
		if (maxCol < ptr->GetCol()) {
			maxCol = ptr->GetCol();
		}
		ptr = ptr->next;
	}
	nRow = maxRow + 1;
	nCol = maxCol + 1;
}

template<class T>	// Initialise with pointer to first element of list and max dimentions
SparseMatrix<T>::SparseMatrix(SparseMatrixNode<T>* first, int rowCount, int colCount) {
	SparseMatrixNode<T>* ptrThis = new SparseMatrixNode<T>();
	SparseMatrixNode<T>* ptrOther = first;
	start = ptrThis;
	length = 0;
	while (ptrOther) {
		ptrThis->next = new SparseMatrixNode<T>(ptrOther->GetRow(), ptrOther->GetCol(), ptrOther->GetValue());
		++length;
		ptrOther = ptrOther->next;
		ptrThis = ptrThis->next;
	}
	SparseMatrixNode<T>* tmp = start;
	start = start->next;
	delete tmp;	
	nRow = rowCount;
	nCol = colCount;
}

template<class T>	// Create matrix with all zero elements
SparseMatrix<T>::SparseMatrix(int rowCount, int colCount) {
	length = 0;
	nRow = rowCount;
	nCol = colCount;
	start = nullptr;
}

template<class T>	// Copy constructor
SparseMatrix<T>::SparseMatrix(const SparseMatrix<T>& other) {
	length = other.length;
	nRow = other.nRow;
	nCol = other.nCol;
	SparseMatrixNode<T>* ptrThis = new SparseMatrixNode<T>();
	SparseMatrixNode<T>* ptrOther = other.start;
	start = ptrThis;
	for (int i = 0; i < other.length; ++i) {
		ptrThis->next = new SparseMatrixNode<T>(ptrOther->GetRow(), ptrOther->GetCol(), ptrOther->GetValue());
		ptrThis = ptrThis->next;
		ptrOther = ptrOther->next;
	}
	SparseMatrixNode<T>* tmp = start;
	start = start->next;		
	delete tmp;		
}

template<class T>
inline SparseMatrix<T>::~SparseMatrix() {
	clearMatrix();
}

template<class T>	// return number of non-zero elements
int SparseMatrix<T>::GetLength() const {
	return length;
}

template<class T>	// return number of rows
int SparseMatrix<T>::GetRowCount() const {
	return nRow;
}

template<class T>	// return number of columns
int SparseMatrix<T>::GetColCount() const {
	return nCol;
}

template<class T>	// returns pointer to first element
const SparseMatrixNode<T>* SparseMatrix<T>::GetFirst() const {
	return start;
}

template<class T>	// add new non-zero value to matrix
void SparseMatrix<T>::insert(SparseMatrixNode<T> newElem) {
	if (newElem.GetRow() >= nRow || newElem.GetCol() >= nCol) {	// Check if index is in range
		cout << "Index out of range" << endl;
		return;
	}
	else if (!newElem.GetValue()) { // Matrix can`t store zero values
		cout << "Element has zero value" << endl;
		return;
	}
	if (!length) {	// if Matrix is void
		start = new SparseMatrixNode<T>(newElem);
		++length;
		return;
	} else if (length == 1) {	// if Matrix has one element
		if (newElem.GetRow() > start->GetRow() || newElem.GetRow() == start->GetRow() && newElem.GetCol() > start->GetCol()) {
			start->next = new SparseMatrixNode<T>(newElem);
			++length;
			return;
		} else {
			SparseMatrixNode<T>* ptr = start;
			start = new SparseMatrixNode<T>(newElem);
			start->next = ptr;
			++length;
			return;
		}
	}
	SparseMatrixNode<T>* ptr = start;	// set pointer for iteration
	if (newElem.GetRow() < start->GetRow() || newElem.GetRow() == start->GetRow() && newElem.GetCol() < start->GetCol()) {
		start = new SparseMatrixNode<T>(newElem);
		start->next = ptr;
		++length;
		return;
	}
	while (newElem.GetRow() > ptr->next->GetRow() || newElem.GetRow() == ptr->next->GetRow() && newElem.GetCol() > ptr->next->GetCol()) {
		ptr = ptr->next;
		if (!ptr->next) {
			break;
		}
	}
	if (ptr->next)	// ELement exists, so can`t be added
		if (newElem.GetRow() == ptr->next->GetRow() && newElem.GetCol() == ptr->next->GetCol()) {
		cout << "Element already exist" << endl;
		return;
	}
	SparseMatrixNode<T>* temp = ptr->next;
	ptr->next = new SparseMatrixNode<T>(newElem);
	ptr->next->next = temp;
	++length;	// increment number of non-zero elements
}

template<class T>	// return transposed matrix
SparseMatrix<T> SparseMatrix<T>::transpose() const {
	SparseMatrix<T> out(nCol, nRow);
	SparseMatrixNode<T>* ptr = start;
	for (int i = 0; i < length; ++i) {	// insert elements one by one to new matrix
		out.insert(SparseMatrixNode<T>(ptr->GetCol(), ptr->GetRow(), ptr->GetValue()));
		ptr = ptr->next;
	}
	return out;
}

template<class T>	// clear data list
void SparseMatrix<T>::clearMatrix() {
	if (start) {	// Check if matrix was initialised
		SparseMatrixNode<T>* temp = start;
		SparseMatrixNode<T>* ptr = start->next;
		for (int i = 0; i < length - 1; ++i) {	// Delete all nodes
			delete temp;
			temp = ptr;
			ptr = ptr->next;
		}
		delete temp;
	}
}


template<class T>	// Serialise matrix to json format
void SparseMatrix<T>::JsonSerialise(Json::Value& root) const {
	if (length) {
		root["rowNumber"] = nRow;
		root["columnNumber"] = nCol;
		root["lenth"] = length;
		Json::Value valList;	// Save node list as json array
		SparseMatrixNode<T>* ptr = start;
		for (int i = 0; i < length; ++i) {
			ptr->JsonSerialise(valList[i]);
			ptr = ptr->next;
		}
		root["data"] = valList;
	}
}

template<class T>	// Deserialise matrix from json format
void SparseMatrix<T>::JsonDeserialise(Json::Value& root) {
	clearMatrix();
	nRow = root.get("rowNumber", 0).asInt();
	nCol = root.get("columnNumber", 0).asInt();
	length = root.get("lenth", 0).asInt();

	SparseMatrixNode<T>* ptrThis = new SparseMatrixNode<T>();
	SparseMatrixNode<T>* temp = new SparseMatrixNode<T>();
	Json::Value valList = root["data"];
	start = ptrThis;
	for (int i = 0; i < length; ++i) {	// read elements of json array
		temp->JsonDeserialise(valList[i]);
		ptrThis->next = new SparseMatrixNode<T>(temp->GetRow(), temp->GetCol(), temp->GetValue());
		ptrThis = ptrThis->next;
	}            
	SparseMatrixNode<T>* tmp = start;
    start = start->next;
	delete tmp; 

}

template<class T>	// assign operator overload
SparseMatrix<T> SparseMatrix<T>::operator=(SparseMatrix<T> other) {
	clearMatrix();	// if matrix already existed
	length = other.length;
	nRow = other.nRow;
	nCol = other.nCol;
	SparseMatrixNode<T>* ptrThis = new SparseMatrixNode<T>();
	SparseMatrixNode<T>* ptrOther = other.start;
	start = ptrThis;
	for (int i = 0; i < other.length; ++i) {	// Copy elements one by one
		ptrThis->next = new SparseMatrixNode<T>(ptrOther->GetRow(), ptrOther->GetCol(), ptrOther->GetValue());
		ptrThis = ptrThis->next;
		ptrOther = ptrOther->next;
	}
	SparseMatrixNode<T>* tmp = start;
	start = start->next;		
	delete tmp;
	return *this;
}

template<class T>	//	Addition operator overload
SparseMatrix<T> SparseMatrix<T>::operator+(SparseMatrix<T>& other) {
	if (nRow != other.nRow || nCol != other.nCol) {	// Check if matrixes have same size
		cout << "Matrixes cannot be added" << endl;
		return SparseMatrix<T>();
	}
	SparseMatrix<T> out(nRow, nCol);
	const SparseMatrixNode<T>* aPtr = start;
	const SparseMatrixNode<T>* bPtr = other.GetFirst();
	while (aPtr && bPtr) {	// Iterate through both matrixes
		if (aPtr->GetRow() > bPtr->GetRow() ||
			aPtr->GetRow() == bPtr->GetRow() &&
			aPtr->GetCol() > bPtr->GetCol())
		{	// if first has non-zero value with lower index
			out.insert(SparseMatrixNode<T>(*bPtr));
			bPtr = bPtr->next;
		}
		else if (aPtr->GetRow() > bPtr->GetRow() ||
			aPtr->GetRow() == bPtr->GetRow() &&
			aPtr->GetCol() > bPtr->GetCol())
		{	// if second has non-zero value with lower index
			out.insert(SparseMatrixNode<T>(*aPtr));
			aPtr = aPtr->next;
		}
		else {	// if both have non-zero value with same index
			double addValue = aPtr->GetValue() + bPtr->GetValue();
			if (addValue) {
				out.insert(SparseMatrixNode<T>(aPtr->GetRow(), aPtr->GetCol(), addValue));
			}
			aPtr = aPtr->next;
			bPtr = bPtr->next;
		}
	}
	while (aPtr) {	// Add rest nodes of first matrix (if any)
		out.insert(*aPtr);
		aPtr = aPtr->next;
	}
	while (bPtr) {	// Add rest nodes of second matrix (if any)
		out.insert(*bPtr);
		bPtr = bPtr->next;
	}

	return out;
}


template<class T>	//	Multiplication operator overload
SparseMatrix<T> SparseMatrix<T>::operator*(SparseMatrix<T>& second) {
	if (nCol != second.nRow) {
		cout << "Matrixes cannot be multiplied" << endl;
		return SparseMatrix<T>();
	}
	SparseMatrix<T> other = second.transpose();	// Transpose for better efficiency
	SparseMatrix<T> out(nRow, other.nRow);
	SparseMatrixNode<T>* aPtr,* bPtr;	// Pointers to store current position

	aPtr = start;
	while(aPtr) {	// Iterate through first matrixes rows
		int curRow = aPtr->GetRow();

		bPtr = other.start;
		while (bPtr) {	// Iterate through second matrixes columns
			int curCol = bPtr->GetRow();

			SparseMatrixNode<T>* aTemp = aPtr;
			SparseMatrixNode<T>* bTemp = bPtr;
			T sum = 0;

			// find non-zero elements to multiply
			while (aTemp && aTemp->GetRow() == curRow && bTemp && bTemp->GetRow() == curCol) {
				if (aTemp->GetCol() < bTemp->GetCol()) {
					aTemp = aTemp->next;
				}
				else if (aTemp->GetCol() > bTemp->GetCol()) {
					bTemp = bTemp->next;
				}
				else {	// both elements are non-zero
					sum += aTemp->GetValue() * bTemp->GetValue();
					aTemp = aTemp->next;
					bTemp = bTemp->next;
				}
			}
			if (sum) {	//	add new elemente to resulting matrix
				out.insert(SparseMatrixNode<T>(curRow, curCol, sum));
			}

			// Move to next column
			while (bPtr && bPtr->GetRow() == curCol) {
				bPtr = bPtr->next;
			}
		}
		// Move to next row
		while (aPtr && aPtr->GetRow() == curRow) {
			aPtr = aPtr->next;
		}
	}
	return out;
}


template <typename T>
ostream& operator<<(ostream& os, const SparseMatrix<T>& matr) {
	if (!matr.start) {
		os << "Invalid matrix object" << endl;
		return os;
	}
	else {
		if (!matr.length) {
			os << "Void matrix" << endl;
		}
	}

	os << "Matrix (" << matr.GetRowCount() << "x" << matr.GetColCount() << ")" << endl;
	os << "Lenth = " << matr.GetLength() << endl;
	os << "Row\tColumn\tValue" << endl;

	SparseMatrixNode<T>* ptr = matr.start;
	for (int i = 0; i < matr.length; ++i) {
		os << ptr->GetRow() << "\t" << ptr->GetCol() << "\t" << ptr->GetValue() << endl;
		ptr = ptr->next;
	}

	return os;
}