#pragma once
#include <iostream>

using namespace std;

namespace Chapter2 
{
	class SparseMatrix;

	class MatrixTerm
	{
	public:
		MatrixTerm() {}
		MatrixTerm(int _row, int _col, int _val) : row(_row), col(_col), value(_val) {}
		~MatrixTerm() {}
		friend class SparseMatrix;
		int row, col, value;
	};

	class SparseMatrix
	{
	public:
		SparseMatrix();
		SparseMatrix(int row, int col, int term);
		~SparseMatrix();

		SparseMatrix Transpose();
		SparseMatrix FastTranspose();
		void Insert(int index, MatrixTerm element);
		void StoreSum(const int sum, const int r, const int c);
		void ChangeSize1D(const int newSize);
		SparseMatrix Multiply(SparseMatrix b);

		friend ostream& operator<<(ostream& os, const SparseMatrix& matrix)
		{
			for (int i = 0; i < matrix.terms; i++)
			{
				cout << "row : " << matrix.smArray[i].row << ", col : " << matrix.smArray[i].col << ", value : " << matrix.smArray[i].value << endl;
			}
			return os;
		}
	private:
		int rows, cols, terms, capacity;
		MatrixTerm* smArray;								
	};

	void SparseMatrixInput();
}
