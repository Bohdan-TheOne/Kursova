#include "Matrixes.h"

namespace Matrixes {

	namespace Convert {
		// Get Common matrix as parameter
		template<class T>
		SparseMatrix<T> ToSparse(const CommonMatrix<T>& in) {
			SparseMatrixNode<T>* ptr = new SparseMatrixNode<T>();
			SparseMatrixNode<T>* start = ptr; // Save pointer to first node
			for (int i = 0; i < in.GetRowCount(); ++i) {
				for (int j = 0; j < in.GetColCount(); ++j) {
					if (in.GetValue(i, j)) {	// if value on position is not zero add it to rezult
						ptr->next = new SparseMatrixNode<T>(i, j, in.GetValue(i, j));
						ptr = ptr->next;
					}
				}
			}
			start = start->next;
			SparseMatrix<T> out(start, in.GetRowCount(), in.GetColCount());
			return out;
		}

		// Get Sparse matrix as parameter
		template <class T>
		CommonMatrix<T> ToCommon(const SparseMatrix<T>& in) {
			CommonMatrix<T> out(in.GetRowCount(), in.GetColCount());	// Create return value
			const SparseMatrixNode<T>* ptr = in.GetFirst();
			for (int i = 0; i < in.GetLength(); ++i) {		// Set every element on it`s place
				out[ptr->GetRow()][ptr->GetCol()] = ptr->GetValue();
				ptr = ptr->next;
			}
			return out;
		}
	}
}