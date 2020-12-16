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

	namespace IODataGrid {
		// Get Sparse matrix from data grid
		template <class T>
		void ReadSparseFormDG(DataGridView^ dgrid, SparseMatrix<T>& matr) {
			int rowCount = matr.GetRowCount();
			int colCount = matr.GetColCount();
			int lenth = matr.GetLength();
			SparseMatrix<float> out(rowCount, colCount);
			for (int i = 0; i < lenth; ++i) {
				out.insert(SparseMatrixNode<float>(
					System::Convert::ToInt32(dgrid[0, i]->Value),
					System::Convert::ToInt32(dgrid[1, i]->Value),
					System::Convert::ToDouble(dgrid[2, i]->Value)));
			}
			matr = out;
		}

		// Print Sparse matrix to data grid
		template <class T>
		void PrintSparseToDG(DataGridView^ dgrid, SparseMatrix<T>& matr) {
			dgrid->ColumnCount = 3;
			int width = dgrid->Width / 7;
			dgrid->Columns[0]->Width = width * 2; 
			dgrid->Columns[1]->Width = width * 2;
			dgrid->Columns[2]->Width = width * 3;
			dgrid->Columns[0]->HeaderText = "Rows = " + matr.GetRowCount().ToString();
			dgrid->Columns[1]->HeaderText = "Columns = " + matr.GetColCount().ToString();
			dgrid->Columns[2]->HeaderText = "Lenth = " + matr.GetLength().ToString();
			if (matr.GetLength() > 0) {
				dgrid->RowCount = matr.GetLength();

				const SparseMatrixNode<T>* ptr = matr.GetFirst();
				for (int i = 0; i < matr.GetLength(); ++i) {
					dgrid[0, i]->Value = ptr->GetRow();
					dgrid[1, i]->Value = ptr->GetCol();
					dgrid[2, i]->Value = ptr->GetValue();
					ptr = ptr->next;
				}
			} else {
				dgrid[0, 0]->Value = "";
				dgrid[1, 0]->Value = "";
				dgrid[2, 0]->Value = "";
				dgrid->RowCount = 1;
			}
		}

		// Get Common matrix from data grid
		template<class T>
		void ReadCommonFormDG(DataGridView^ dgrid, CommonMatrix<T>& matr) {
			int rowCount = matr.GetRowCount();
			int colCount = matr.GetColCount();
			CommonMatrix<float> out(rowCount, colCount);
			for (int j = 0; j < colCount; ++j) {
				for (int i = 0; i < rowCount; ++i) {
					out[i][j] = System::Convert::ToDouble(dgrid[j, i]->Value);
				}
			}
			matr = out;
		}

		// Print Common matrix to data grid
		template<class T>
		void PrintCommonToDG(DataGridView^ dgrid, CommonMatrix<T>& matr) {
			if (matr.GetRowCount() > 0 && matr.GetColCount()) {
				dgrid->ColumnCount = matr.GetColCount();
				dgrid->RowCount = matr.GetRowCount();
				for (int j = 0; j < matr.GetColCount(); ++j) {
					dgrid->Columns[j]->Width = 40;
					for (int i = 0; i < matr.GetRowCount(); ++i) {
						dgrid[j, i]->Value = matr.GetValue(i, j);
					}
				}
			} else {
				ExeptionMtr("Void Matrix", "Matrix has wrong size arguments").ShowException();
			}
		}
	}
}