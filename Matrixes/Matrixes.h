#ifndef MATRIXES
#define MATRIXES

#include "CommonMatrix/CommonMatrix.cpp"
#include "SparseMatrix/SparseMatrix.cpp"

namespace Matrixes {

	namespace Convert {
		template <class T>
		SparseMatrix<T> ToSparse(const CommonMatrix<T>& in, SparseMatrix<T>& out);

		template <class T>
		CommonMatrix<T> ToCommon(const SparseMatrix<T>& in, CommonMatrix<T>& out);
	}

}

#endif
