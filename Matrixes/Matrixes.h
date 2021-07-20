#ifndef MATRIXES
#define MATRIXES

#include "CommonMatrix/CommonMatrix.cpp"
#include "SparseMatrix/SparseMatrix.cpp"

namespace Matrixes {

	namespace Convert {
		template <class T>	// Convert commot matrix to sparse
		SparseMatrix<T> ToSparse(const CommonMatrix<T>& in);

		template <class T>	// Convert sparse matrix to common
		CommonMatrix<T> ToCommon(const SparseMatrix<T>& in);
	}
}

#endif