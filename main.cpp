#include "Matrixes/Matrixes.cpp"
#include <stdlib.h>
#include <time.h>
#include <fstream>

int main(void) {
	auto sparse_matrix_0{SparseMatrix<int>(4, 6)};	
	sparse_matrix_0.insert(SparseMatrixNode<int>(1, 1, 200));
	auto sparse_matrix_1{SparseMatrix<int>(6, 4)};	
	sparse_matrix_1.insert(SparseMatrixNode<int>(1, 1, 300));
	auto mult_sparse{sparse_matrix_0 * sparse_matrix_1};
	std::cout << mult_sparse << std::endl;
	auto convRezCommon = Matrixes::Convert::ToCommon(mult_sparse);
	auto convRezSparse = Matrixes::Convert::ToSparse(convRezCommon);
	std::cout << convRezCommon << std::endl;
	std::cout << convRezSparse << std::endl;
	return 0;
}
