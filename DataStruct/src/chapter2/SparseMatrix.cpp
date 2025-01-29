#include "memory.h"
#include "chapter2/SparseMatrix.h"
#include <algorithm>

using namespace std;

namespace Chapter2
{
	SparseMatrix::SparseMatrix()
	{
		
	}

	SparseMatrix::SparseMatrix(int _row, int _col, int _term)
		: rows(_row), cols(_col), terms(_term)
	{
		smArray = new MatrixTerm[_term];
	}

	SparseMatrix::~SparseMatrix()
	{
		delete[] smArray;
	}

	SparseMatrix SparseMatrix::Transpose()
	{
		SparseMatrix transposed(cols, rows, terms);
		if (terms < 1)
			return transposed;

		int currentB = 0;
		for (int c = 0; c < cols; c++)
		{
			for (int i = 0; i < terms; i++)
			{
				if (smArray[i].col == c)
				{
					transposed.smArray[currentB].row = c;
					transposed.smArray[currentB].col = smArray[i].row;
					transposed.smArray[currentB++].value = smArray[i].value;
				}
			}
		} 
		return transposed;
	}

	SparseMatrix SparseMatrix::FastTranspose()
	{
		SparseMatrix transposed(cols, rows, terms);
		if (terms < 1)
			return transposed;

		int* rowSize = new int[cols];
		int* rowStart = new int[cols];

		fill(rowSize, rowSize + cols, 0);
		for (int i = 0; i < terms; ++i)
			rowSize[smArray[i].col]++;
		
		rowStart[0] = 0;
		for (int i = 1; i < cols; ++i)
			rowStart[i] = rowStart[i - 1] + rowSize[i - 1];

		for(int i = 0; i < terms; ++i)
		{
			int j = rowStart[smArray[i].col];
			transposed.smArray[j].row = smArray[i].col;
			transposed.smArray[j].col = smArray[i].row;
			transposed.smArray[j].value = smArray[i].value;
			rowStart[smArray[i].col]++;
		}
		delete[] rowSize;
		delete[] rowStart;

		return transposed;
	}

	void SparseMatrix::Insert(int index, MatrixTerm element)
	{
		if (index >= terms)
			return;
		smArray[index] = element;
	}

	void SparseMatrixInput()
	{
		int row, col, term;
		cout << "input row, colums and terms" << endl;
		cin >> row >> col >> term;
		
		SparseMatrix s(row, col, term);
		int value;
		for (int i = 0; i < term; ++i)
		{
			cout << "input row, colums and value, " << term - i << "left" << endl;
			cin >> row >> col >> value;
			MatrixTerm* a = new MatrixTerm(row, col, value);
			s.Insert(i, *a);
		}

		cout << s << endl;

		SparseMatrix t = s.Transpose();
		cout << t << endl;

		SparseMatrix ft = s.FastTranspose();
		cout << ft << endl;
	}
}
