#ifndef MATRIXES
#define MATRIXES

#include "../my_exeption.h"
#include "CommonMatrix/CommonMatrix.cpp"
#include "SparseMatrix/SparseMatrix.cpp"

namespace Matrixes {

	namespace Convert {
		template <class T>	// Convert commot matrix to sparse
		SparseMatrix<T> ToSparse(const CommonMatrix<T>& in);

		template <class T>	// Convert sparse matrix to common
		CommonMatrix<T> ToCommon(const SparseMatrix<T>& in);
	}

	namespace IODataGrid {
		template <class T>
		void ReadSparseFormDG(DataGridView^ dgrid, SparseMatrix<T>& matr); 
		
		template <class T>
		void PrintSparseToDG(DataGridView^ dgrid, SparseMatrix<T>& matr);

		template <class T>
		void ReadCommonFormDG(DataGridView^ dgrid, CommonMatrix<T>& matr);

		template <class T>
		void PrintCommonToDG(DataGridView^ dgrid, CommonMatrix<T>& matr);
	}
}

#endif