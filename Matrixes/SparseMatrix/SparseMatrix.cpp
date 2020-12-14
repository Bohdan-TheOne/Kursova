#include "SparseMatrix.h"

template<class T>
inline SparseMatrixNode<T>::SparseMatrixNode() {
	row = 0;
	col = 0;
	value = 0;
	next = NULL;
}

template<class T>
SparseMatrixNode<T>::SparseMatrixNode(int _row, int _col, T _val) {
	row = _row;
	col = _col;
	value = _val;
	next = NULL;
}

template<class T>
SparseMatrixNode<T>::SparseMatrixNode(const SparseMatrixNode& other) {
	row = other.row;
	col = other.col;
	value = other.value;
	next = other.next;
}

template<class T>
void SparseMatrixNode<T>::SetNode(int _row, int _col, T _val) {
	row = _row;
	col = _col;
	value = _val;
}

template<class T>
void SparseMatrixNode<T>::SetCords(int _row, int _col) {
	row = _row;
	col = _col;
}

template<class T>
void SparseMatrixNode<T>::SetValue(T _val) {
	value = _val;
}

template<class T>
int SparseMatrixNode<T>::GetRow() const {
	return row;
}

template<class T>
int SparseMatrixNode<T>::GetCol() const {
	return col;
}

template<class T>
T SparseMatrixNode<T>::GetValue() const {
	return value;
}

template<class T>
SparseMatrixNode<T> SparseMatrixNode<T>::operator=(SparseMatrixNode<T> other) {
	row = other.row;
	col = other.col;
	value = other.value;
	next = other.next;
	return *this;
}

template<class T>
inline SparseMatrix<T>::SparseMatrix() {
	length = 0;
	nRow = 0;
	nCol = 0;
	start = nullptr;
}

template<class T>
inline SparseMatrix<T>::SparseMatrix(SparseMatrixNode<T>* first) {
	start = first;
	length = 0;

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

template<class T>
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
	start = start->next;
	nRow = rowCount;
	nCol = colCount;
}

template<class T>
SparseMatrix<T>::SparseMatrix(int rowCount, int colCount) {
	length = 0;
	nRow = rowCount;
	nCol = colCount;
	start = nullptr;
}

template<class T>
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
	start = start->next;
}

template<class T>
inline SparseMatrix<T>::~SparseMatrix() {
	if (start) {
		SparseMatrixNode<T>* temp = start;
		SparseMatrixNode<T>* ptr = start->next;
		for (int i = 0; i < length - 1; ++i) {
			delete temp;
			temp = ptr;
			ptr = ptr->next;
		}
		delete temp;
	}
}

template<class T>
int SparseMatrix<T>::GetLength() const {
	return length;
}

template<class T>
int SparseMatrix<T>::GetRowCount() const {
	return nRow;
}

template<class T>
int SparseMatrix<T>::GetColCount() const {
	return nCol;
}

template<class T>
const SparseMatrixNode<T>* SparseMatrix<T>::GetFirst() const {
	return start;
}

template<class T>
void SparseMatrix<T>::insert(SparseMatrixNode<T> newElem) {
	if (newElem.GetRow() >= nRow || newElem.GetCol() >= nCol) {
		cout << "Index out of range" << endl;
		return;
	}
	if (!length) {
		start = new SparseMatrixNode<T>(newElem);
		++length;
		return;
	} else if (length == 1) {
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
	SparseMatrixNode<T>* ptr = start;
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
	if (ptr->next)
		if (newElem.GetRow() == ptr->next->GetRow() && newElem.GetCol() == ptr->next->GetCol()) {
		cout << "Element already exist" << endl;
		return;
	}
	SparseMatrixNode<T>* temp = ptr->next;
	ptr->next = new SparseMatrixNode<T>(newElem);
	ptr->next->next = temp;
	++length;
}

template<class T>
SparseMatrix<T> SparseMatrix<T>::transpose() const {
	SparseMatrix<T> out(nCol, nRow);
	SparseMatrixNode<T>* ptr = start;
	for (int i = 0; i < length; ++i) {
		out.insert(SparseMatrixNode<T>(ptr->GetCol(), ptr->GetRow(), ptr->GetValue()));
		ptr = ptr->next;
	}
	return out;
}

template<class T>
SparseMatrix<T> SparseMatrix<T>::operator=(SparseMatrix<T> other) {
	if (start) {
		delete start;
	}
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
	start = start->next;
	return *this;
}

template<class T>
SparseMatrix<T> SparseMatrix<T>::operator+(SparseMatrix<T> other) {
	if (nRow != other.nRow || nCol != other.nCol) {
		cout << "Matrixes cannot be added" << endl;
		return SparseMatrix<T>();
	}
	SparseMatrix<T> out(nRow, nCol);
	const SparseMatrixNode<T>* aPtr = start;
	const SparseMatrixNode<T>* bPtr = other.GetFirst();
	while (aPtr && bPtr) {
		if (aPtr->GetRow() > bPtr->GetRow() ||
			aPtr->GetRow() == bPtr->GetRow() &&
			aPtr->GetCol() > bPtr->GetCol())
		{
			out.insert(*bPtr);
			bPtr = bPtr->next;
		}
		else if (aPtr->GetRow() > bPtr->GetRow() ||
			aPtr->GetRow() == bPtr->GetRow() &&
			aPtr->GetCol() > bPtr->GetCol())
		{
			out.insert(*aPtr);
			aPtr = aPtr->next;
		}
		else {
			double addValue = aPtr->GetValue() + bPtr->GetValue();
			if (addValue) {
				out.insert(SparseMatrixNode<T>(aPtr->GetRow(), aPtr->GetCol(), addValue));
			}
			aPtr = aPtr->next;
			bPtr = bPtr->next;
		}
	}
	while (aPtr) {
		out.insert(*aPtr);
		aPtr = aPtr->next;
	}
	while (bPtr) {
		out.insert(*bPtr);
		bPtr = bPtr->next;
	}

	return out;
}


template<class T>
SparseMatrix<T> SparseMatrix<T>::operator*(SparseMatrix<T> other) {
	if (nCol != other.nRow) {
		cout << "Matrixes cannot be multiplied" << endl;
		return SparseMatrix<T>();
	}
	other = other.transpose();
	SparseMatrix<T> out(nRow, other.nRow);
	SparseMatrixNode<T>* aPtr,* bPtr;

	aPtr = start;
	while(aPtr) {
		int curRow = aPtr->GetRow();

		bPtr = other.start;
		while (bPtr) {
			int curCol = bPtr->GetRow();

			SparseMatrixNode<T>* aTemp = aPtr;
			SparseMatrixNode<T>* bTemp = bPtr;
			T sum = 0;
			while (aTemp && aTemp->GetRow() == curRow && bTemp && bTemp->GetRow() == curCol) {
				if (aTemp->GetCol() < bTemp->GetCol()) {
					aTemp = aTemp->next;
				}
				else if (aTemp->GetCol() > bTemp->GetCol()) {
					bTemp = bTemp->next;
				}
				else {
					sum += aTemp->GetValue() * bTemp->GetValue();
					aTemp = aTemp->next;
					bTemp = bTemp->next;
				}
			}
			if (sum) {
				out.insert(SparseMatrixNode<T>(curRow, curCol, sum));
			}

			while (bPtr && bPtr->GetRow() == curCol) {
				bPtr = bPtr->next;
			}
		}
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