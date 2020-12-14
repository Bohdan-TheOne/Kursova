#include "Matrixes/Matrixes.cpp"
#include <stdlib.h>
#include <time.h>

int main(void) {
	SparseMatrix<float> matrix = SparseMatrix<float>(13, 17);
	srand(time(NULL));
	for (int i = 1; i < 10; ++i) {
		matrix.insert(SparseMatrixNode<float>(rand() % 13, rand() % 17, (rand() % 200 - 99) / 10.0));
	}

	cout << matrix << endl;
	CommonMatrix<float> common;
	Matrixes::Convert::ToCommon(matrix, common);
	cout << common << endl;

	SparseMatrix<float> newSparse;
	Matrixes::Convert::ToSparse(common, newSparse);
	cout << newSparse << endl << endl;

	SparseMatrix<float> addRez;
	addRez = matrix + newSparse;
	cout << addRez << endl;

	SparseMatrix<float> aMult(4, 3);
	SparseMatrix<float> bMult(3, 5);
	SparseMatrix<float> multRez;
	aMult.insert(SparseMatrixNode<float>(1, 0, 2));
	aMult.insert(SparseMatrixNode<float>(0, 1, 8));
	aMult.insert(SparseMatrixNode<float>(3, 0, 7));
	aMult.insert(SparseMatrixNode<float>(2, 2, 4));
	aMult.insert(SparseMatrixNode<float>(3, 2, 5));
	Matrixes::Convert::ToCommon(aMult, common);
	cout << common << endl;

	bMult.insert(SparseMatrixNode<float>(0, 0, 1));
	bMult.insert(SparseMatrixNode<float>(1, 2, 2));
	bMult.insert(SparseMatrixNode<float>(0, 4, 1));
	bMult.insert(SparseMatrixNode<float>(2, 1, 5));
	bMult.insert(SparseMatrixNode<float>(2, 3, 4));
	Matrixes::Convert::ToCommon(bMult, common);
	cout << common << endl;

	multRez = aMult * bMult;
	cout << multRez << endl;
	Matrixes::Convert::ToCommon(multRez, common);
	cout << common << endl;
	return 0;
}
