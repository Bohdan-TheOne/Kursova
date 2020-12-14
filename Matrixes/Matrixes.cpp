#include "Matrixes.h"

namespace Matrixes {

	namespace Convert {
		template<class T>
		SparseMatrix<T> ToSparse(const CommonMatrix<T>& in, SparseMatrix<T>& out) {
			SparseMatrixNode<T>* ptr = new SparseMatrixNode<T>();
			SparseMatrixNode<T>* start = ptr;
			for (int i = 0; i < in.GetRowCount(); ++i) {
				for (int j = 0; j < in.GetColCount(); ++j) {
					if (in.GetValue(i, j)) {
						ptr->next = new SparseMatrixNode<T>(i, j, in.GetValue(i, j));
						ptr = ptr->next;
					}
				}
			}
			start = start->next;
			out = SparseMatrix<T>(start, in.GetRowCount(), in.GetColCount());
			return out;
		}

		template <class T>
		CommonMatrix<T> ToCommon(const SparseMatrix<T>& in, CommonMatrix<T>& out) {
			out = CommonMatrix<T>(in.GetRowCount(), in.GetColCount());
			const SparseMatrixNode<T>* ptr = in.GetFirst();
			for (int i = 0; i < in.GetLength(); ++i) {
				out[ptr->GetRow()][ptr->GetCol()] = ptr->GetValue();
				ptr = ptr->next;
			}
			return out;
		}
	}
}