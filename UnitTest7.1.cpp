#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71
{
	TEST_CLASS(UnitTest71)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 4;
			const int colCount = 4;

			int matrix[rowCount][colCount] = {
				{4, 4, 2, 2},
				{3, 1, 1, 1},
				{1, 2, 2, 3},
				{1, 2, 3, 4},
			};

			int sortedMatrix[rowCount][colCount] = {
				{ 2, 2, 4, 4 },
				{ 1, 1, 1, 3 },
				{ 3, 2, 2, 1 },
				{ 4, 3, 2, 1 },
			};

			int* matrixPointers[rowCount] = {
				matrix[0],
				matrix[1],
				matrix[2],
				matrix[3],
			};

			Sort(matrixPointers, rowCount, colCount);

			for (int row = 0; row < rowCount; row++)
				for (int column = 0; column < colCount; column++)
					Assert::AreEqual(sortedMatrix[row][column], matrix[row][column]);
		};

		TEST_METHOD(test_calc)
		{
			const int rowCount = 4;
			const int colCount = 4;

			int matrix[rowCount][colCount] = {
				{-3,  0,  1, 2},
				{ 3, -2, -4, 3},
				{ 0, -3, -5, 6},
				{-4, -2,  3, 4},
			};

			int expctedMatrix[rowCount][colCount] = {
				{-3,  0,  1, 2},
				{ 0, -2, -4, 0},
				{ 0, -3, -5, 0},
				{-4, -2,  0, 4},
			};

			int* matrixPointers[rowCount] = {
				matrix[0],
				matrix[1],
				matrix[2],
				matrix[3],
			};

			int Sum = 0;
			int Count = 0;

			Calc(matrixPointers, rowCount, colCount, Sum, Count);

			for (int row = 0; row < rowCount; row++)
				for (int column = 0; column < colCount; column++)
					Assert::AreEqual(expctedMatrix[row][column], matrix[row][column]);

			Assert::AreEqual(15, Sum);
			Assert::AreEqual(4, Count);
		}
	};
}
		}
	};
}
