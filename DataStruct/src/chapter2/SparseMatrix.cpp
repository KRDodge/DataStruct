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

		int* rowStart = new int[cols];

		fill(rowStart, rowStart + cols, 0);
		for (int i = 0; i < terms; ++i)
			rowStart[smArray[i].col]++;
		
		int sum = 0;
		for (int i = 0; i < cols; ++i) {
			int temp = rowStart[i];
			rowStart[i] = sum;
			sum += temp;
		}

		for(int i = 0; i < terms; ++i)
		{
			int j = rowStart[smArray[i].col];
			transposed.smArray[j].row = smArray[i].col;
			transposed.smArray[j].col = smArray[i].row;
			transposed.smArray[j].value = smArray[i].value;
			rowStart[smArray[i].col]++;
		}
		delete[] rowStart;

		return transposed;
	}

	void SparseMatrix::Insert(int index, MatrixTerm element)
	{
		if (index >= terms)
			return;
		smArray[index] = element;
	}

	void SparseMatrix::StoreSum(const int sum, const int r, const int c)
	{
		if (sum == 0)
			return;

		if (terms == capacity)
			ChangeSize1D(2 * capacity);
		smArray[terms].row = r;
		smArray[terms].col = c;
		smArray[terms++].value = sum;
	}

	void SparseMatrix::ChangeSize1D(const int newSize)
	{
		if (newSize < terms)
			throw "New Size must be >= number of terms";
		MatrixTerm* temp = new MatrixTerm[newSize];
		copy(smArray, smArray + terms, temp);
		delete[] smArray;
		smArray = temp;
		capacity = newSize;
	}

	SparseMatrix SparseMatrix::Multiply(SparseMatrix b)
	{
		if (cols != b.rows)
			throw "tncompatible matrices";

		SparseMatrix bXpose = b.FastTranspose();
		SparseMatrix d(rows, b.cols, 0);
		int currRowIndex = 0, currRowBegin = 0, currRowA = smArray[0].row;

		if (terms == capacity)
			ChangeSize1D(terms + 1);
		bXpose.ChangeSize1D(terms + 1);
		smArray[terms].row = rows;
		bXpose.smArray[b.terms].row = b.cols;
		bXpose.smArray[b.terms].col = -1;

		int sum = 0;

		while (currRowIndex < terms)
		{
			int currColB = bXpose.smArray[0].row;
			int currColIndex = 0;

			if (smArray[currRowIndex].row != currRowA)
			{
				d.StoreSum(sum, currRowA, currColB);
				sum = 0;
				currRowIndex = currRowBegin;
				while (bXpose.smArray[currColIndex].row == currColB)
					currColIndex++;
				currColB = bXpose.smArray[currColIndex].row;
			}
			else if (bXpose.smArray[currColIndex].row != currColB)
			{
				d.StoreSum(sum, currRowA, currColB);
				sum = 0;
				currRowIndex = currRowBegin;
				currColB = bXpose.smArray[currColIndex].row;
			}
			else
			{
				if (smArray[currRowIndex].col < bXpose.smArray[currColIndex].col)
					currRowIndex++;
				else if (smArray[currRowIndex].col == bXpose.smArray[currColIndex].col)
				{
					sum += smArray[currRowIndex].value * bXpose.smArray[currColIndex].value;
					currRowIndex++;
					currColIndex++;
				}
				else
					currColIndex++;
			}
			
			while (smArray[currRowIndex].row == currRowA)
				currRowIndex++;

			currRowBegin = currRowIndex;
			currRowA = smArray[currRowIndex].row;
		}
		return d;
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
