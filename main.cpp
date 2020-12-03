#include "Matrixes/Matrixes.cpp"
#include <stdlib.h>
#include <time.h>

int main(void) {
	SparseMatrix<float> matrix = SparseMatrix<float>(13, 17);
	srand(time(NULL));
	for (int i = 1; i < 10; ++i) {
		matrix.insert(SparseMatrixNode<float>(rand()%13, rand()%17, (rand()%200-99)/10.0));
	}

	cout << matrix << endl;
	CommonMatrix<float> common;
	Matrixes::Convert::ToCommon(matrix, common);
	cout << common << endl;

	SparseMatrix<float> newSparse;
	Matrixes::Convert::ToSparse(common, newSparse);
	cout << newSparse << endl << endl;

	return 0;
}
